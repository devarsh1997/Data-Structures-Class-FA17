#include "../cs225/HSLAPixel.h"
#include "../Point.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "ColorPicker.h"
#include "MyColorPicker.h"
using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 */
// MyColorPicker::MyColorPicker(HSLAPixel color) : color(color) { }
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  /* initialize random seed: */
  /* generate secret number between 0 and 9: */
  // srand((unsigned)time(0)); 
  // int i;
  // i = (rand()%6)+1; 
  // // double v1 = rand() % 100;
  // srand((unsigned)time(0));
// double floor = 0;
// double ceiling = 3.5;
// double range = (ceiling - floor);
// int rnd = floor + int((range * rand()) / (RAND_MAX + 1.0));
	// int h1 = rand();
	// int h2 = rand();
	// int h3 = rand();
	double h = ((rand()%10)*36);
	if ((x+y)%7 > 3){
		h /= 4;
	}
  // srand (time(NULL));
	double s = (rand() % 10)/10.0;
  // srand (time(NULL));	
	double l = (rand() % 10)/10.0;
	// srand (time(NULL));
	double a = (rand() % 10)/10.0;

  HSLAPixel pixel(h,s,l,a);


  return pixel;
}
