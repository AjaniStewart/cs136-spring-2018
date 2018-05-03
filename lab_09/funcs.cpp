#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

constexpr int MAX_H = 512;
constexpr int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width, string outName) {
	ofstream ostr;
	ostr.open(outName + ".pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
}

void invertImage(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width)
{
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
            outImage[row][col] = 255 - inImage[row][col];
}

void invertHalf(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width)
{
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
        {
            if (col < width/2)
                outImage[row][col] = inImage[row][col];
            else
                outImage[row][col] = 255 - inImage[row][col];
        }
}

void box(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width)
{
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
        {
            if (row > height/4 && row < 3*height/4 && col > width/4 && col < 3*width/4)
                outImage[row][col] = 255;
            else    
                outImage[row][col] = inImage[row][col];
        }
}

void frame(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width)
{
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
        {
            //disgusting
            if ((((row == height / 4 && col > width / 4 && col < 3 * width / 4) || 
                (row == 3 * height / 4 && col > width / 4 && col < 3 * width / 4)))
                || (col == width / 4 && row > height / 4 && row < 3 * height / 4) || 
                (col == 3 * width / 4 && row > height / 4 && row < 3 * height / 4))
                outImage[row][col] = 255;
            else
                outImage[row][col] = inImage[row][col];
        }
}

//TODO: fix
void scale(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width)
{
    for (int row = 0; row < height; ++row)
        for (int col = 0; col < width; ++col)
        {
            outImage[2*row][2*col] = inImage[row][col];
            outImage[2*row+1][2*col] = inImage[row][col];
            outImage[2*row][2*col+1] = inImage[row][col];
            outImage[2*row+1][2*col+1] = inImage[row][col];
        }
}

void pixelate(int inImage[MAX_H][MAX_W], int outImage[MAX_H][MAX_W], int height, int width)
{
    for (int row = 0; row < height; row += 2)
        for (int col = 0; col < width; col += 2)
        {
            int sum = inImage[row][col] + inImage[row+1][col]
                      + inImage[row][col+1] + inImage[row+1][col+1];
            int avg = sum/4;
            outImage[row][col] = avg;
            outImage[row+1][col] = avg;
            outImage[row][col+1] = avg;
            outImage[row+1][col+1] = avg;
        }
}

