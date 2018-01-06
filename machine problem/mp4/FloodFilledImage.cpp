#include "cs225/PNG.h"
#include <list>
#include <iostream>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;
using namespace std;
/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
	this->base = new PNG(png);
}

/**
 * Adds a flood fill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
	if (traversal.seq.empty()){
		return;
	}
	while(!traversal.seq.empty()){
		Point look = traversal.seq.front();
		traversal.seq.pop_front();
		int x = look.x;
		int y = look.y;
		HSLAPixel* p = this->base->getPixel(x, y);
		HSLAPixel n = colorPicker.getColor(x, y);
		this->new_pix.push_back(n);
		this->trav_seq.push_back(look);
	}
}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) {
  Animation animation;
  /** @todo [Part 2] */
  this->frames.push_back(base);
  animation.addFrame(*base);
  unsigned num_pix = this->trav_seq.size();
  for (unsigned i=0; i<num_pix; i+=frameInterval){
  	// cout << "add a frame" << endl;
  	PNG* add_one = new PNG(*(this->frames.back()));
  	for (unsigned j=0; j<frameInterval; j++){
  		if (i+j >= num_pix){
  			break;
  		}
		int x = trav_seq[i+j].x;
		int y = trav_seq[i+j].y;
		HSLAPixel change = new_pix[i+j];

		HSLAPixel* origin = add_one->getPixel(x, y);
		origin->h = change.h;
		origin->s = change.s;
		origin->l = change.l;
		origin->a = change.a;
  	}
	this->frames.push_back(add_one);
  	animation.addFrame(*add_one);
  }
  return animation;
}
