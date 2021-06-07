clear all

% Complete PATH
addpath("../helper_methods")
addpath("../utils")

% Set example data
useExampleFile = false;
%fName = 'testData'

% Get filename from directory if we are not using the example data
if ~useExampleFile
%   fNumber = 3097; % 3097 is the one with the problem
  fNumber = 3097;
  fName = getFilenameFromNumber(fNumber, '/home/kersimon/Documents/2021-03-14 - HBC failure at Schutz und Rettung/');
%   fprintf(['\nGot filename: ', fName, ' from number: ', num2str(fNumber)]);
end

% Read data
logElements = loadLogFile(fName);
fprintf(['\n\nLoaded data from binary file:', fName]);


% Generate Index Variables
verbose = false;
genIndexVariables(logElements, verbose);
fprintf('\n\nGenerated indices for the log elements!\n');
fprintf(['Start of log file ' datestr(datetime( logElements(idx_hbc_measEulerZyxControlToBase_y).timeStruct.seconds(1), 'ConvertFrom', 'posixtime' )) '\n'])
fprintf(['Start of log file as unix time stamp ' num2str(logElements(idx_hbc_measEulerZyxControlToBase_y).systime(1)) '\n'])
fprintf(['End of log file' datestr(datetime( logElements(idx_hbc_measEulerZyxControlToBase_y).timeStruct.seconds(end), 'ConvertFrom', 'posixtime' )) '\n'])
fprintf(['End of log file as unix time stamp ' num2str(logElements(idx_hbc_measEulerZyxControlToBase_y).systime(end)) '\n'])

%%
figure(1)
clf
sgtitle('Zylinderposition')
subplot(2,2,1)
hold on
plotDataWithName(logElements, idx_model_state_joint_positions_meas_1, {'color','r'});
grid minor
subplot(2,2,2)
hold on
plotDataWithName(logElements, idx_model_state_joint_positions_meas_5, {'color','r'});
grid minor
subplot(2,2,3)
hold on
plotDataWithName(logElements, idx_model_state_joint_positions_meas_8, {'color','r'});
grid minor
subplot(2,2,4)
hold on
plotDataWithName(logElements, idx_model_state_joint_positions_meas_13, {'color','r'});
grid minor

subplot(2,2,1)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_0, {'color','g'});
subplot(2,2,2)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_4, {'color','g'});
subplot(2,2,3)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_9, {'color','g'});
subplot(2,2,4)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_14, {'color','g'});

subplot(2,2,1)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_2, {'color','b'});
plotDataWithName(logElements, idx_command_actuatorCommands2_position, {'linestyle', '--', 'color','k'});
subplot(2,2,2)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_6, {'color','b'});
plotDataWithName(logElements, idx_command_actuatorCommands6_position, {'linestyle', '--', 'color','k'});
subplot(2,2,3)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_10, {'color','b'});
plotDataWithName(logElements, idx_command_actuatorCommands10_position, {'linestyle', '--', 'color','k'});
subplot(2,2,4)
plotDataWithName(logElements, idx_model_state_joint_positions_meas_15, {'color','b'});
plotDataWithName(logElements, idx_command_actuatorCommands15_position, {'linestyle', '--', 'color','k'});

legend('HFE', 'HAA', 'STEER', 'STEER ref')

%%
figure(10)
clf
sgtitle('Control mode')
subplot(2,2,1)
hold on
plotDataWithName(logElements, idx_command_actuatorCommands1_mode, {'color', 'r'})
plotDataWithName(logElements, idx_command_actuatorCommands0_mode, {'color', 'g'})
plotDataWithName(logElements, idx_command_actuatorCommands2_mode, {'color', 'b'})
grid minor

subplot(2,2,2)
hold on
plotDataWithName(logElements, idx_command_actuatorCommands5_mode, {'color', 'r'})
plotDataWithName(logElements, idx_command_actuatorCommands4_mode, {'color', 'g'})
plotDataWithName(logElements, idx_command_actuatorCommands6_mode, {'color', 'b'})
grid minor

subplot(2,2,3)
hold on
plotDataWithName(logElements, idx_command_actuatorCommands8_mode, {'color', 'r'})
plotDataWithName(logElements, idx_command_actuatorCommands9_mode, {'color', 'g'})
plotDataWithName(logElements, idx_command_actuatorCommands10_mode, {'color', 'b'})
grid minor

subplot(2,2,4)
hold on
plotDataWithName(logElements, idx_command_actuatorCommands13_mode, {'color', 'r'})
plotDataWithName(logElements, idx_command_actuatorCommands14_mode, {'color', 'g'})
plotDataWithName(logElements, idx_command_actuatorCommands15_mode, {'color', 'b'})  
legend('HFE', 'HAA', 'STEER')
grid minor

%%
figure(2)
clf
sgtitle('Driving commanded velocity')
plotDataWithName(logElements, idx_command_actuatorCommands3_velocity, {'linestyle','-.','color','r'});
grid minor

%%
figure(3)
clf
sgtitle('Chassisregler')
subplot(2,2,1)
hold on
title('Height')
plotDataWithName(logElements, idx_hbc_measHeightAlongSurfaceNormal, {'color','r'});
plotDataWithName(logElements, idx_hbc_desHeightAlongSurfaceNormal, {'linestyle', '--', 'color','k'});
grid minor
subplot(2,2,2)
hold on
title('Roll')
plotDataWithName(logElements, idx_hbc_measEulerZyxControlToBase_x, {'color','r'});
plotDataWithName(logElements, idx_hbc_desEulerZyxControlToBase_x, {'linestyle', '--', 'color','k'});
grid minor
subplot(2,2,3)
hold on
title('Pitch')
plotDataWithName(logElements, idx_hbc_measEulerZyxControlToBase_y, {'color','r'});
plotDataWithName(logElements, idx_hbc_desEulerZyxControlToBase_y, {'linestyle', '--', 'color','k'});
grid minor
subplot(2,2,4)
hold on
title('Yaw')
plotDataWithName(logElements, idx_hbc_measEulerZyxControlToBase_z, {'color','r'});
plotDataWithName(logElements, idx_hbc_desEulerZyxControlToBase_z, {'linestyle', '--', 'color','k'});
grid minor
%%
figure(4)  
clf
sgtitle('Kraft Abstützzylinder')
subplot(2,2,1)
hold on
plotDataWithName(logElements, idx_model_state_joint_torques_meas_1, {'color','r'});
plotDataWithName(logElements, idx_command_actuatorCommands1_effort, {'k--'})
grid minor
subplot(2,2,2)
hold on
plotDataWithName(logElements, idx_model_state_joint_torques_meas_5, {'color','r'});
plotDataWithName(logElements, idx_command_actuatorCommands5_effort, {'k--'})
grid minor
subplot(2,2,3)
hold on
plotDataWithName(logElements, idx_model_state_joint_torques_meas_8, {'color','r'});
plotDataWithName(logElements, idx_command_actuatorCommands8_effort, {'k--'})
grid minor
subplot(2,2,4)
hold on
plotDataWithName(logElements, idx_model_state_joint_torques_meas_13, {'color','r'});
plotDataWithName(logElements, idx_command_actuatorCommands13_effort, {'k--'})
grid minor
%%
orientationBaseToWorldQuat = [logElements(idx_model_state_orientationBaseToWorld_meas_w).data, logElements(idx_model_state_orientationBaseToWorld_meas_x).data, logElements(idx_model_state_orientationBaseToWorld_meas_y).data, logElements(idx_model_state_orientationBaseToWorld_meas_z).data];
orientationBaseToWorldEul = quat2eul(orientationBaseToWorldQuat);

figure(5)
clf
title('Chassisorientierung')
hold all

plotTime = datetime(logElements(idx_model_state_orientationBaseToWorld_meas_w).systime, 'ConvertFrom', 'posixtime');
plotTime = plotTime + seconds(3600);

plot(plotTime, orientationBaseToWorldEul);
legend('yaw', 'pitch', 'roll')
grid minor
%%
axesHandles = findobj('Type', 'axes');
for i = 1:size(axesHandles)
    axesHandles(i).FontSize = 15;
    
end