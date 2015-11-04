# 569
EE569 2015 Fall

# EE569 Homework Assignment #1
# Date:     Sep 20, 2015
# Name:     Meiyi Yang
#
# Compiled on OS X Yosemite Version 10.10.4
#
# Define compiler and linker in Makefile
# Coding in C++11

# 1. Usage for compiling, linking and runing

# Compile, link and default run:

make

# Clean compiling files:

make clean


# 2. File list and explanation
#
# p1_resize.cpp:        Problem 1.a
# p1_bilinear.cpp :     Problem 1.b.1
# p1_MHC.cpp:           Problem 1.b.2
# p2_transfer:          Problem 2.a.methodA
# p2_cumulative:        Problem 2.a.methodB
# p2_oilpainting.cpp    Problem 2.b
# p3_gaussian.cpp       Problem 3.a
# p3_median.cpp         Problem 3.a
# p3_guided.cpp         Problem 3.b
#
# hw1_helper.cpp
# hw1_helper.h

#########################################################
# EE569 Homework Assignment #2
# Date:     Oct 20, 2015
# Name:     Meiyi Yang
#########################################################
# Compiled on OS X Yosemite Version 10.10.4
# Define compiler and linker in CMakeLists.txt
# 		cmake_minimum_required(VERSION 3.3)
# Coding in C++11
# Matlab R2015a
# OpenCV: 3.0 (https://github.com/Itseez/opencv.git)
#########################################################
 * EE569 Homework Assignment #2
 * Date: October 14, 2015
 * Name: Meiyi Yang
 * ID: 6761054585
 * email: meiyiyan@usc.edu
——————————————————————
 * slic.h.
 * Written by: Pascal Mettes.
 * This file contains the class elements of the class Slic. This class is an
 * implementation of the SLIC Superpixel algorithm by Achanta et al. [PAMI'12,
 * vol. 34, num. 11, pp. 2274-2282].
 * This implementation is created for the specific purpose of creating
 * over-segmentations in an OpenCV-based environment.
 * From: https://github.com/PSMM/SLIC-Superpixels
——————————————————————
 * meanshift.h
 * Author: Kanglai Qian
 * From: https://github.com/qiankanglai/opencv.meanshift

###################################
# 1. Usage for compiling, linking and running
# Compile, link and default run:

# Problem3a:
# make sure you are in the HW2 folder: three sub-folder p3
# in HW2 root folder
cd p3
cmake .
make
./p3
——————————————————————
# Problem3b, Problem3c:
# Matlab: make sure two scripts are run under four toolbox:
# image processing toolbox
# Statistic and Machine Learning Toolbox
# Piotr's Computer Vision Matlab Toolbox (https://github.com/pdollar/toolbox.git)
# Structured Edge Detection Toolbox V3.0 (https://github.com/pdollar/edges.git)
# MATLAB and Octave Functions for Computer Vision and Image Processing (http://www.csse.uwa.edu.au/~pk/research/matlabfns/)
# CCP source code (https://github.com/fuxiang87/MCL_CCP)
# benchmark source code given by TA
run p3b.m
run p3c.m
——————————————————————
# Clean compiling files:
make clean
#########################################################
# 2. File list and explanation
 * Problem3. Image Segmentation
 * p3a: 
 * Main function: p2_main.cpp
 * Class slic: slic.h, slic.cpp
 * Function Meanshift: meanshift.h, meanshift.cpp
 * Class ImgMatOperator:hw2_helper.h, hw2_helper.cpp
 *
 * p3b & p3c: MATLAB code
 * p3b.m
 * p3c.m
 * run_cpp.m
 * run_evaluation.m
#########################################################





# EE569 Homework Assignment #3
# Date:     Nov 1, 2015
# Name:     Meiyi Yang
# ID:       6761-0405-85
# Email:    meiyiyan@usc.edu
#########################################################
# Compiled on OS X Yosemite Version 10.10.4
# Define compiler and linker in CMakeLists.txt
# 		cmake_minimum_required(VERSION 3.3)
# Coding in C++11
#########################################################
# 1. Usage for compiling, linking and running
# Compile, link and default run:
# Problem1:
# in HW3 root folder:
# Use cmake
cd p1
cmake .
make
./p1

# OR just use makefile: 
make
./p1
——————————————————————
# Problem2:
# in HW3 root folder:
# Use cmake
cd p2
cmake .
make
./p2

# OR just use  makefile: 
make
./p2
——————————————————————
# Problem3:
# in HW3 root folder:
# Use cmake
cd p3
cmake .
make
./p3

# OR just use makefile: 
make
./p3
——————————————————————
# Clean compiling files:
make clean
#########################################################
 * 2. File list and explanation
 * Problem1. Geometrical Modification
 * main implementing and testing file
 p1_main.cpp
 * class file
 Image.h
 Image.cpp

 * Problem2. Digital Half-toning
 * main implementing and testing file
 p2_main.cpp
 * class file
 Image.h
 Image.cpp
 Halftoning.h
 Halftoning.cpp

 * Problem3. Morphological Processing
 * main implementing and testing file
 * p3_main.cpp
 * class file
 Image.h
 Image.cpp
 Morphology.h
 Morphology.cpp
#########################################################