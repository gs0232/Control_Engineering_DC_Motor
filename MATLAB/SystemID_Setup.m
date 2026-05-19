
% Identification of system
%   This script sets the frame conditions for system identification.
%   Nothing must be added or changed here!
%   Run the script to open the simulink model for system identificatoin.
%   To-Do: 
%       -Run the model and play with direction and
%       speed of the motor. Observe how the acqurired sensor data looks like.
%       Please start from 0 PWM to prevent damage

%% Clean up
clc
close all

%% Define Parameters
T = 0.0001;     %Sample time

%% Open System Identification Simulink model
open_system("EncoderRead.slx")