classdef ThrusterModel
    %THRUSTERMODEL Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        L; %Mapping Matrix
        D; %Fault Matrix
        TSPEC; %T200 Spec table
        T; %Vecteur classe thruster
        FT; % Force min max truster
        MLD; % Max load all DOF
        
    end
    
    methods
        function this = ThrusterModel(d14,d58,z,dz)
            %THRUSTERMODEL Construct an instance of this class
            %   Detailed explanation goes here
           this.TSPEC= load('T200-Spec-16V.mat').T200Spec16V ;
           this.L = this.GetMappingMatrix(d14,deg2rad(45),d58,z,dz);
           this.T = this.GetThrusterMatrix();
           this.FT = this.GetMinMax(this.TSPEC{:,6});
           this.MLD = this.GetMaxLoadAllAxis();
        end
%==========================================================================
        function T = GetThrusterMatrix(this)
         % Crée le vecteur de class thruster.
         % Arguments : NA.
         T=T200Thruster.empty(8,0);
          for i=1:8
                T(i)=T200Thruster(this.TSPEC,i);
           end
        end
%==========================================================================        
        function L = GetMappingMatrix(this,d14,a14,d58,z,dz)
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
        function lax= GetMaxLoadAllAxis(this)
        % Calcule la force Maximum déployer sur les thrusters pur les 6DDL.
        % Arguments : V matrice de composantes des thrusters (6DDL)
        %             tf, matrice de force thruster horraire, antihorraire
        [rows ] = size(this.L);
        vml=zeros(size(6));
         for i=1:rows
            V = this.L(i,:);
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
       
    end
end

