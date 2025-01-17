% EE569 Homework Assignment #4 
% Date: Noverber 29th 2015 
% Name: Meiyi Yang
% ID:  6761-0405-85 
% email:  meiyiyan@usc.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Problem 2:    Coutour Modeling
% p2_code/p2_Level_Set/prob2b.m       % Main script for prob2b
% p2_code/p2_Level_Set/drlse_edge.m   % Helper function for level-set
% p2_code/p2_Level_Set/level_set.m    % Helper function for level-set
% p1_code/p2_Snake_Algorithm/         % GUI for snake algorithm
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 


clear all;
close all;

number = input('Which subproblem (0 or 1 or 2 or 3)? ');
%%%%%%%%%%%%%%%%%%%
%%%% Problem2a %%%%
%%%%%%%%%%%%%%%%%%%
if number == 0
    filename = 'spine.tif';
    iter_outer = 70;
    lambda = 5; % coefficient of the weighted length term L(phi)
    alfa = 2;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 30;
    x_max = 380;
    y_min = 10;
    y_max = 590;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end
if number == 0
    filename = 'spine.tif';
    iter_outer = 60;
    lambda = 2; % coefficient of the weighted length term L(phi)
    alfa = 5;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 30;
    x_max = 380;
    y_min = 10;
    y_max = 590;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end
if number == 0
    filename = 'spine.tif';
    iter_outer = 70;
    lambda = 2; % coefficient of the weighted length term L(phi)
    alfa = 2;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 30;
    x_max = 380;
    y_min = 10;
    y_max = 590;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end

%%%%%%%%%%%%%%%%%%%
%%%% Problem2b %%%%
%%%%%%%%%%%%%%%%%%%
if number == 1
    filename = 'coronary.tif';
    iter_outer = 60;
    lambda = 5; % coefficient of the weighted length term L(phi)
    alfa = 2;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 70;
    x_max = 420;
    y_min = 50;
    y_max = 460;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end

if number == 1
    filename = 'coronary.tif';
    iter_outer = 60;
    lambda = 2; % coefficient of the weighted length term L(phi)
    alfa = 5;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 70;
    x_max = 420;
    y_min = 50;
    y_max = 460;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end

if number == 1
    filename = 'coronary.tif';
    iter_outer = 60;
    lambda = 2; % coefficient of the weighted length term L(phi)
    alfa = 2;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 70;
    x_max = 420;
    y_min = 50;
    y_max = 460;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end

%%%%%%%%%%%%%%%%%%%
%%%% Problem2c %%%%
%%%%%%%%%%%%%%%%%%%
if number == 2
    filename = 'blood_cells.tif';
    iter_outer = 50;
    lambda = 5; % coefficient of the weighted length term L(phi)
    alfa = 2;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 120;
    x_max = 430;
    y_min = 340;
    y_max = 580;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end

if number == 2
    filename = 'blood_cells.tif';
    iter_outer = 50;
    lambda = 2; % coefficient of the weighted length term L(phi)
    alfa = 5;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 120;
    x_max = 430;
    y_min = 340;
    y_max = 580;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end

%%%%%%%%%%%%%%%%%%%
%%%% Problem2d %%%%
%%%%%%%%%%%%%%%%%%%
if number == 3
    filename = 'brain.tif';
    iter_outer = 50;
    lambda = 5; % coefficient of the weighted length term L(phi)
    alfa = 2;  % coefficient of the weighted area term A(phi)
    epsilon = 1; % papramater that specifies the width of the DiracDelta function
    x_min = 120;
    x_max = 280;
    y_min = 350;
    y_max = 510;
    level_set(filename, iter_outer, lambda, alfa, epsilon, x_min, x_max, y_min, y_max)
end