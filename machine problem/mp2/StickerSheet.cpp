#include "StickerSheet.h"
#include "Image.h"
#include <iostream>
using namespace std;


StickerSheet::StickerSheet (const Image &picture, unsigned max){
	this->img_ct = 0;
	this->img_max = max;
	this->baseImage = new Image(picture);
	this->imageList = new Image*[max];
	this->xCord = new unsigned[max];
	this->yCord = new unsigned[max];
	// cout<<"created a sticker sheet at "<<this<<endl;
}
StickerSheet::StickerSheet (const StickerSheet &other){
	this->_copy(other);
}
const StickerSheet& StickerSheet::operator= (const StickerSheet &other){
	this->_destroy();
	this->_copy(other);
	return *this;
}

StickerSheet::~StickerSheet (){
	this->_destroy();
}

void StickerSheet::_copy(const StickerSheet& other){
	this->img_ct = other.img_ct;
	this->img_max = other.img_max;
	this->baseImage = new Image(*other.baseImage);
	this->imageList = new Image*[img_max];
	this->xCord = new unsigned[img_max];
	this->yCord = new unsigned[img_max];
	for (unsigned i=0; i<img_max; i++){
		*(this->imageList[i]) = *(other.imageList[i]);
		this->xCord[i] = other.xCord[i];
		this->yCord[i] = other.yCord[i];
	}
}
void StickerSheet::_destroy(){
	delete this->baseImage; this->baseImage = NULL;
	delete[] this->imageList; this->imageList = NULL;
	delete[] this->xCord; this->xCord = NULL;
	delete[] this->yCord; this->yCord = NULL;
}

void StickerSheet::changeMaxStickers (unsigned max){
	this->img_max = max;
	Image** newList = new Image*[max];
	unsigned* newX = new unsigned[max];
	unsigned* newY = new unsigned[max];
	if (max < this->img_ct){
		this->img_ct = max;
	}
	for (unsigned i=0; i<img_ct; i++){
		*newList[i] = *this->imageList[i];
		newX[i] = this->xCord[i];
		newY[i] = this->yCord[i];
	}
	delete[] this->imageList; this->imageList = newList;
	delete[] this->xCord; this->xCord = newX;
	delete[] this->yCord; this->yCord = newY;
}
int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
	// if (img_ct >= img_max){
	// 	this->changeMaxStickers(2*img_max);
	// }
	// cout<<"start adding a sticker"<<endl;
	if (img_ct < img_max){
		this->imageList[img_ct] = new Image(sticker); // ??????
		this->xCord[img_ct] = x;
		this->yCord[img_ct] = y;
		this->img_ct += 1;
		return (img_ct-1);
	}else{
		// cout<<"cannot add this one!"<<endl;
		return -1;
	}
	
}
bool StickerSheet::translate (unsigned index, unsigned x, unsigned y){
	if (index < this->img_ct){//ok to change
		this->xCord[index] = x;
		this->yCord[index] = y;
		return true;
	}else{
		return false;
	}
}
void StickerSheet::removeSticker (unsigned index){
	if (index < (img_ct-1)) {
		for (unsigned i = index; i < (img_ct - 1); i++){
			*imageList[i] = *imageList[i+1];
			xCord[i] = xCord[i+1];
			yCord[i] = yCord[i+1];
		}
		delete imageList[img_ct - 1]; imageList[img_ct - 1] = NULL;
		xCord[img_ct-1] = 0;
		xCord[img_ct-1] = 0;
		img_ct-= 1;
		}
	else if (index == (img_ct-1)) {
		delete imageList[img_ct - 1]; imageList[img_ct - 1] = NULL;
		xCord[img_ct-1] = 0;
		xCord[img_ct-1] = 0;
		img_ct-= 1;
	}
}
	// cout<<"start delete number "<<index<<endl;
	// cout<<"it has address "<<this->imageList[index]<<endl;
// 	delete this->imageList[index];
// 	// cout<<"it has address "<<this->imageList[index]<<endl;
// 	for (unsigned i=index; i<img_ct-1; i++){
// 		this->imageList[i] = this->imageList[i+1];
// 		this->xCord[i] = this->xCord[i+1];
// 		this->yCord[i] = this->yCord[i+1];
// 	}
// 	this->imageList[img_ct-1] = NULL; // ??????
// 	img_ct -= 1;
// }
Image* StickerSheet::getSticker (unsigned index) const{
	if (index < this->img_ct){
		return this->imageList[index];
	}else{
		return NULL;
	}
}
	

Image StickerSheet::render () const{
	unsigned initialW = this->baseImage->width();
	unsigned initialH = this->baseImage->height();
	Image* output = new Image(initialW,initialH);
	//copy base image
	for (unsigned x=0; x<initialW; x++){
		for (unsigned y=0; y<initialH; y++){
			HSLAPixel* origin = baseImage->getPixel(x,y);
			HSLAPixel* target = output->getPixel(x,y);
			if (origin->a != 0){
				*target = *origin;
			}
		}
	}
	//copy stickers
	for (unsigned i=0; i<this->img_ct; i++){
		Image* sticker = this->imageList[i];
		unsigned stickerW = sticker->width();
		unsigned stickerH = sticker->height();
		unsigned startX = this->xCord[i];
		unsigned startY = this->yCord[i];
		unsigned endX = startX+stickerW;
		unsigned endY = startY+stickerH;
		if (endX > initialW){
			initialW = endX;
			output->resize(initialW,initialH);
		}
		if (endY > initialH){
			initialH = endY;
			output->resize(initialW,initialH);
		}
		for (unsigned x=0; x<stickerW; x++){
			for (unsigned y=0; y<stickerH; y++){
				HSLAPixel* origin = sticker->getPixel(x,y);
				HSLAPixel* target = output->getPixel(startX+x,startY+y);
				if (origin->a != 0){
					*target = *origin; //core copy pixel step
				}

			}
		}
	}
	return *output;
}












