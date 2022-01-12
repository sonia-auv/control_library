
A = [ 0 1 -2 1 3 0 1 1];

B = [ .1 .1 2 .1 .1 .1 .1 .1 ];

C = A < B
mode =2;
% 
% % trouver le champ du mode
%     mode = ['c',sprintf('%d',10)]
% % chercher la liste e mode
%     list = fieldnames(MPC.gains,'-full')
%     
% % Vérifier si le mode existe
%     
%     if sum(strcmp(list, mode )) == 1 % mode existe et unique
%       
%         
%         OV = MPC.gains.(mode).OV
%         MV = MPC.gains.(mode).MV
%         MVR = MPC.gains.(mode).MVR
%     
%     else % mode non trouver 
%         OV = MPC.c
%         MV = MPC.gains.('defaut').MV
%         MVR = MPC.gains.('defaut').MVR
%         
%     end
    
    

    
% Vérifier si le mode existe
    corr = MPC.gainsList(:,1) == mode
    
    if sum(corr) == 1 % mode existe et unique
        
        i = find(corr == 1)
    else 
        i=1;
    end
    
        
        OV = MPC.gainsList(i,2:14)
        MV = MPC.gainsList(i,15:22)
        MVR = MPC.gainsList(i,23:30)
   