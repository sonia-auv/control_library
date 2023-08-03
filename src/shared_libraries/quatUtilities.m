classdef quatUtilities
    % this class contains methods for quaternion handling that are
    % not supported by default for code generation.

    % The Fossen(2021) Reference is the book "Handbook of Marine Craft Hydrodynamics and Motion Control second edition"
    % Disponible a la bibliotheque de l'ets. Code : VM 156 F67 2021

    methods(Static)
         %=================================================================
         % Fonction qui tourne un vecteur selon un quaternion.
         function rp = quatRotation(p,q)

             qs = q(1);   % quaternion partie scalaire
             qu = q(2:4); % quaternion partie vectoriel

             % QuatRotate n'est pas compilable
             rp= (2*dot(qu,p)*qu +(qs^2-dot(qu,qu))*p + 2*qs*cross(qu,p));
         end

         %=================================================================
         % Fonction qui normalise un quaternion.
         % quatnormalize de matlab demande areospace block set pour etre compilable.
         function nq = quatNorm(q)

            % Fossen(2021) eq 2.86 p.37
            nq = q ./ norm(q);
         end

        %=================================================================
        % Fonction qui assure la continuité entre 2 quaternions
         function q = checkQuatFlip(q, qk)

            % Regarder la discontinuité entre le qk et qk-1
            if  dot(qk,q) < 0
                q = -q;
            end

        end

        %=================================================================
        % Fonction qui calcule la rotation entre 2 vector
        % https://math.stackexchange.com/questions/2356649/how-to-find-the-quaternion-representing-the-rotation-between-two-3-d-vectors
        function q = quaternionForm2Vectors(v1, v2)

            c = cross(v1, v2);

            n = c / norm(c);

            theta = atan(norm(c) / dot(v1,v2));

            q = [ cos(theta / 2), n * sin(theta / 2)]; % Fossen eq 2.67 p.33

        end

        %=================================================================
        % Fonction qui calcule l'angle entre 2 quaternion
        function angle = angleBetween2Quaternion(q1, q2)

            qRel = quatmultiply(quatconj(q1),q2);
            angle = 2 * atan2(norm(qRel(2:4)),qRel(1));

        end
         %=================================================================
         % Fonction qui convertie un quaternion instantané en vitesses angulaires.
         function angularRates = qDot2angularRates(q,qDot)

            E2 = quatUtilities.liniairzeE2(q);
            invE2 = pinv(E2);

            angularRates = -(invE2 * qDot.').';

         end

        %=================================================================
         % Fonction qui convertie des vitesses angulaires quaternion instantané en quaternion instantané.
         function qDot = angularRates2qDot(this, q, omega)

            E2 = quatUtilities.liniairzeE2(q);

            qDot = -E2* omega.';
         end

        %==================================================================
        % Fonnction qui retoure le quaternion le plus court/long selon
        % l'utilisateur

        function rq = getQuatDir(lq,q,dir)

            %---------------------------------------------------------------
            % Code not ready for deploy yet. It is comment to avoid instablitiy
            % during pool testing.
            %---------------------------------------------------------------
            %           norm = dot(lq,q);
            %             % conjuger le quaternion au besoin
            %             %if  norm > 1 && dir == 0 || norm < 1 && dir == 1
            %            if  norm < 0  && dir == 0 || norm >= 0 && dir == 1
            %                 q = quatconj(q);
            %                 this.lastConj =true;
            %
            %             end
            rq = quatmultiply(lq,q);

        end

    end

    methods(Static, Access = private)

       %=================================================================
        % Fonction qui Convertie un vecteur 3x1 en une matrice antisymétrique 3x3
        function sm = skew3(u)
            % Fossen(2021) eq 2.47 p30
            sm=[0,-u(3),u(2);
                u(3), 0, -u(1);
               -u(2), u(1), 0];
        end

        %=================================================================
        % Calcule la matrice de transformation vitesse angulaire à quaternion instantané
        function E2 = liniairzeE2(q)
            % Fossen(2021) eq 2.77 - 2.78 page 35
            E2 = (1/2) * [-q(2:4); q(1)*eye(3) + quatUtilities.skew3(q(2:4))];
        end



    end
end

