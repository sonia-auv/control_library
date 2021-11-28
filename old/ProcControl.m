classdef ProcControl
% Classe ProcControl
% Cette classe fait l'orchestration des tâches du Proc Control.
%==========================================================================
%Proprietes
%==========================================================================
    properties
        
    end
%==========================================================================
%Methodes
%==========================================================================   
    methods
        % Methodes publiques
        % Constructeur
        function this = ProcControl()
           
        end
        
        function setMode(this, mode)
           % Changement de mode du controleur
           disp("Nouveau mode: " + mode);
        end
        
        function addPose(this, x, y, z, roll, pitch, yaw, frame, zoneData)
           % Crée un waypoint.
           wpts = Waypoint(x, y, z, roll, pitch, yaw, frame, zoneData);
           disp("Nouvelle pose: " + wpts.x);
        end
        
        function computeTrajectory(this)
           % Génération de la trajectoire après avoir donné les poses.
           disp("Generation trajectoire");
        end
        
        function clearWaypoints(this)
           % Suppression des waypoints.
           disp("Suppression des waypoints");
        end
    end
end
