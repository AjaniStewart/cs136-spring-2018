#pragma once
#include <string>
extern const int MAX_H = 512;
extern const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(int image[MAX_H][MAX_W], int height, int width, std::string outName);
void invertImage(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width);
void invertHalf(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width);