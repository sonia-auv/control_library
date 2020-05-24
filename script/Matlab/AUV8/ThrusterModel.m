classdef ThrusterModel
    %THRUSTERMODEL Summary of this class goes here
    %   Detailed explanation goes here
%==========================================================================
%Propriétés.
%==========================================================================
   
    properties
        L; %Mapping Matrix
        D; %Fault Matrix
        TSPEC; %T200 Spec table
        T; %Vecteur classe thruster
        FT; % Force min max truster
        MLDT; % Max load all DOF théorique
        MLDR; % Max load all DOF réel
        C; % Fichier config
        fl; %Limitation mecanique du truster en %.
        OPT; % optimisation thruster
        CT; % Commande Truster
     
    end
%==========================================================================
%Methodes
%==========================================================================
    methods
        function this = ThrusterModel(Config)
            %THRUSTERMODEL Construct an instance of this class
            %   Detailed explanation goes here
           this.C=Config;
           this.TSPEC= load('T200-Spec-16V.mat').T200Spec16V ;
           this.L = this.GetMappingMatrix();
           this.T = this.GetThrusterMatrix();
           this.FT = this.GetMinMax(this.TSPEC{:,6});
           this.fl =this.EleMecRatio();
           this.D= repmat(this.fl,1,this.C.nbt);
           
           this.OPT= TrusterOptimisation(this.L,this.FT,this.D,...
                               this.TSPEC{:,6},this.TSPEC{:,7},this.C.nbt);
                           
           this.MLDT = this.GetMaxLoadAllAxis(this.L);
           this.MLDR = this.GetMaxLoadAllAxis(this.L*diag(this.D));
           
        end
%==========================================================================
        function T = GetThrusterMatrix(this)
         % Crée le vecteur de class thruster.
         % Arguments : NA.
         T=T200Thruster.empty(this.C.nbt,0);
          for i=1:8
                T(i)=T200Thruster(this.TSPEC,i);
           end
        end
%==========================================================================        
        function L = GetMappingMatrix(this)
            % Calcule la matrice de componsates des thruster sur les 6DDL.
            % Arguments : d14, Matrice Distance x y z  des trusters 1 - 4.
            %             a14, Angles des trusters 1 - 4.
            %             d58, Matrice distance x y z des trusters 5 - 8.
            %             z,   Position des truster sur le frame.
            %             dz,  Distance entre les postions du frame.
            if ~exist('dz','var') %paramètre optionelle
              dz = 0;
            end
             if ~exist('z','var')
              z=[0,0,0,0];
             end
             % concactener les variables pour avour une matrice lisible.
             a14 =this.C.a14;
             d14 =this.C.d14;
             d58=this.C.d58;
             z=this.C.z;
             dz =this.C.dz;
             % Thruster effort Mapping Matrix (L)
            %       x         y      z rx ry           rz
            l1 = [ sin(a14),-cos(a14), 0, (d14(3)+z(1)*dz)*cos(a14),...
                 (d14(3)+z(1)*dz)*sin(a14),-hypot( d14(1), d14(2))];
             
            l2 = [ sin(a14), cos(a14), 0,-(d14(3)+z(2)*dz)*cos(a14),...
                 (d14(3)+z(2)*dz)*sin(a14),-hypot(-d14(1), d14(2))];
             
            l3 = [ sin(a14),-cos(a14), 0, (d14(3)+z(3)*dz)*cos(a14),...
                 (d14(3)+z(3)*dz)*sin(a14), hypot(-d14(1),-d14(2))];
             
            l4 = [ sin(a14), cos(a14), 0,-(d14(3)+z(4)*dz)*cos(a14),...
                 (d14(3)+z(4)*dz)*sin(a14), hypot( d14(1),-d14(2))];
             
            l5 = [0, 0, 1, d58(2),-d58(1), 0];
            l6 = [0, 0,-1,-d58(2),-d58(1), 0];
            l7 = [0, 0, 1,-d58(2), d58(1), 0];
            l8 = [0, 0,-1, d58(2), d58(1), 0];

            L= [l1.', l2.', l3.', l4.', l5.' l6.', l7.', l8.'];
        end

%==========================================================================
        function lax= GetMaxLoadAllAxis(this,L)
        % Calcule la force Maximum déployer sur les thrusters pur les 6DDL.
        % Arguments : V matrice de composantes des thrusters (6DDL)
        %             tf, matrice de force thruster horraire, antihorraire
        [rows ] = size(L);
        vml=zeros(size(6));
         for i=1:rows
            V = L(i,:);
            vml(i)= this.GetMaxLoadOneAxis(V);
         end
         lax=vml.';

        end

%==========================================================================
        function lxx= GetMaxLoadOneAxis(this,V)
        % Calcule la force Maximum déployer sur les thrusters sur 1 DDL.
        % Arguments : V matrice de composantes des thrusters pour 1 DDL
        %             tf, matrice de force thruster horraire, antihorraire
        mt = 0;
         for i = 1:numel(V)
            mt=mt+this.GetThrusterMaxLoad(V(i));    
         end
         lxx=mt;
        end

%==========================================================================
        function mt = GetThrusterMaxLoad(this,c)
        % Retourne la force de la composante selon le sens du thruster
        % Arguments : c, la composante du thruster, 
        %             tf, matrice de force thruster horraire, antihorraire.
            if c>0
               mt = c*this.FT(1);
            else
               mt = c*this.FT(2);
            end
        end
%==========================================================================
        function mm= GetMinMax(this,A)
        % trouve la valeur maximum et minimum d'une matrice.
        % Arguments : N, Matrice data.
        mm=[A(end),A(1)];
        end
%==========================================================================
        function r= EleMecRatio(this)
        % transforme le % de limitation élé(A) en % limitation mec (N).
   
            %Séparer la relation newton selon watt en 2 pour pas que la
            %fonction soit complexe.
            PN=this.TSPEC{108:end,6};
            NN=this.TSPEC{1:94,6};
            PW=this.TSPEC{108:end,7};
            NW=this.TSPEC{1:94,7};
            % Trouver les min max en x ey y
            MW= this.GetMinMax(this.TSPEC{:,7});
           
            %Trouver la fonction de la parti positif(P) et négatif(N)
            TP=this.GetRelation(PW,PN);
            TN=this.GetRelation(NW,NN);
            %Trouver la force équivalent au courant maximum limité 
            LIMP=TP(MW(1)*this.C.psl);
            LIMN=TN(MW(2)*this.C.psl);
            % Mettre les nouvelle force maximal en %.
            MLP=LIMP/this.FT(1);
            MLN=LIMN/this.FT(2);
            %retourner la valeur min.
            r= min(MLP,MLN);
        end
%==========================================================================
        function f= GetRelation(this,x,y)
        % trouve une équoition d'orde 6 pour un nuage de point donnée.
        % Arguments : x, Matrice des composante x.
        %             y, Matrice des composante y.
        opt = fitoptions('poly2','Normalize', 'on', 'Robust', 'Bisquare');
        f=fit(x,y,'poly5',opt);
        end
%==========================================================================
    function OT = GetThrusterOutput(this,command)
    % optimise la sortie des thrusters pour limiter la force total
    % Arguments : input,vecteur résultant
        OT=this.OPT.optimiseThrusterOutput(command);
    
    end
    
%==========================================================================   
    function OT = GetNlThrusterOutput(this,command)
    % optimise la sortie des thrusters pour limiter la cosomation élé
    % Arguments : input,vecteur résultant    
        OT=this.OPT.NLoptimiseThrusterOutput(command);
   
    end
%==========================================================================


    end
end

