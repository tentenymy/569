/* EE569 Homework Assignment #4
 * Date: Noverber 29, 2015
 * Name: Meiyi Yang
 * ID: 6761054585
 * email: meiyiyan@usc.edu
 * Problem1. OCR
 *
 * Main function:
 * p1_main.cpp
 *
 * Class OCR:
 * OCR.h
 * OCR.cpp
 *
 * Class Image:
 * image.h
 * image.cpp
 *
 * Class Morphology:
 * Morphology.h
 * Morphology.cpp
 */

#ifndef P3_IMAGE_H
#define P3_IMAGE_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

//////////////////////////////////////////////
/////////// Structure Definition /////////////
//////////////////////////////////////////////
const double PI = 3.14159265;
const int MODE_X = 0;
const int MODE_Y = 1;
const int MODE_Z = 2;
typedef unsigned char ImgPixel;
typedef float ImgCoord[4];
typedef float ImgColor[3];
typedef float Matrix[4][4];
typedef float Coord3D[3];
typedef struct GeoPixel {
    ImgCoord coord;
    ImgColor color;
} GeoPixel;


//////////////////////////////////////////////
/////////// Function Declaration /////////////
//////////////////////////////////////////////
float COS(float);
float SIN(float);
float TAN(float);


//////////////////////////////////////////
/////////// Class Definition /////////////
//////////////////////////////////////////
class Image {
public:
    int col;
    int row;
    int byte;
    int geo_row;
    int geo_col;
    ImgPixel *data = NULL;
    GeoPixel *geo_data = NULL;


/////////////////////////////////////
/////////// Constructor /////////////
/////////////////////////////////////
    Image(int, int, int, ImgPixel*);
    Image(int, int, int, string);
    Image();
    ~Image();


/////////////////////////////////
/////////// Display /////////////
/////////////////////////////////
    void Write (Image*, string);
    void Write (string);
    void Write (string, int);
    void Write_Txt(string);
    void Print_Data(string);
    void Print_Data(string, int, int);
    void Print_Pattern_Data(string str);
    void Print_Geodata_Color(string);
    void Print_Geodata_Color(string, int, int);
    void Print_Geodata_Coord(string);
    void Print_Geodata_Coord(string, int, int);


/////////////////////////////////////
/////////// Access Data /////////////
/////////////////////////////////////
    ImgPixel Get_Value(int i, int j, int k);
    ImgPixel* Get_Pixel(int i, int j, int k);
    float Get_Geo_Coord(int i, int j, int k);
    float Get_Geo_Value(int i, int j, int k);
    int Get_Row(int index);
    int Get_Col(int index);
    int Get_Byte(int index);


/////////////////////////////////
/////////// Process /////////////
/////////////////////////////////
//@ new_row, new_col: resize row and col
    void Convert_To_Gray();
    void Convert_To_Binary();
    void Convert_Size(int new_row, int new_col);
    void Convert_Row_Size(int new_row);
};
#endif //P3_IMAGE_H
