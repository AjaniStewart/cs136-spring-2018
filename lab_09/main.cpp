/*
  Author: Ajani Stewart

  Description:
    The program reads a PGM image from the file "inImage.pgm",
    and outputs a modified image to "outImage.pgm"
*/

#include "funcs.h"

int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];

	//and save this new image to file "outImage.pgm"
	invertImage(img,out,h,w);
	writeImage(out, h, w, "task-a");

	readImage(img, h, w);
	invertHalf(img,out,h,w);
	writeImage(out,h,w,"task-b");

	readImage(img, h, w);
	box(img,out,h,w);
	writeImage(out,h,w,"task-c");

	readImage(img, h, w);
	frame(img,out,h,w);
	writeImage(out,h,w,"task-d");

	readImage(img,h,w);
	scale(img,out,h,w);
	writeImage(out,h,w,"task-e");

	readImage(img, h, w);
	pixelate(img, out, h, w);
	writeImage(out, h, w, "task-f");
}

