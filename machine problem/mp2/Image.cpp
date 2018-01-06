#include "Image.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
using namespace std;

Image::Image():PNG(){
	// cout<<"using default image constructor"<<endl;

}
Image::Image(unsigned int width, unsigned int height):PNG(width, height){
	// cout<<"using input image constructor"<<endl;
	// PNG(width, height);
}
void Image::lighten(){
// Lighten an Image by increasing the luminance of every pixel by 0.1.
// This function ensures that the luminance remains in the range [0, 1].
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->l += 0.1;
			if (pixel->l > 1){
				pixel->l = 1;
			}
		}
	}
}
void Image::lighten(double amount){
// Lighten an Image by increasing the luminance of every pixel by amount.

// This function ensures that the luminance remains in the range [0, 1].
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->l += amount;
			if (pixel->l > 1){
				pixel->l = 1;
			}
		}
	}
}

void Image::darken(){
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->l -= 0.1;
			if (pixel->l < 0){
				pixel->l = 0;
			}
		}
	}
}
void Image::darken(double amount){
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->l -= amount;
			if (pixel->l < 0){
				pixel->l = 0;
			}
		}
	}
}
void Image::saturate(){
// Saturates an Image by increasing the saturation of every pixel by 0.1.

// This function ensures that the saturation remains in the range [0, 1].
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->s += 0.1;
			if (pixel->s > 1){
				pixel->s = 1;
			}
		}
	}
}
void Image::saturate(double amount){
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->s += amount;
			if (pixel->s > 1){
				pixel->s = 1;
			}
		}
	}
}
void Image::desaturate(){
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->s -= 0.1;
			if (pixel->s < 0){
				pixel->s = 0;
			}
		}
	}
}
void Image::desaturate(double amount){
	for (unsigned w=0; w<this->width(); w++){
		for (unsigned h=0; h<this->height(); h++){
			HSLAPixel* pixel = this->getPixel(w,h);
			pixel->s -= amount;
			if (pixel->s < 0){
				pixel->s = 0;
			}
		}
	}
}
void Image::grayscale(){
	for (unsigned w=0; w<this->width(); w++) {
		for (unsigned h=0; h<this->height(); h++) {
			HSLAPixel *pixel = this->getPixel(w, h);

			// `pixel` is a pointer to the memory stored inside of the PNG `image`,
			// which means you're changing the image directly.  No need to `set`
			// the pixel since you're directly changing the memory of the image.
			pixel->s = 0;
		}
	}
}
void Image::rotateColor(double amount){
// Rotates the color wheel by degrees.

// This function ensures that the hue remains in the range [0, 360].
	for (unsigned w=0; w<this->width(); w++) {
		for (unsigned h=0; h<this->height(); h++) {
			HSLAPixel *pixel = this->getPixel(w, h);

			// `pixel` is a pointer to the memory stored inside of the PNG `image`,
			// which means you're changing the image directly.  No need to `set`
			// the pixel since you're directly changing the memory of the image.
			double frac = amount - int(amount);
			pixel->h += ((int(amount)%360)+frac);
			if (pixel->h > 360){
				pixel->h -= 360;
			}
			if (pixel->h < 0){
				pixel->h += 360;
			}
		}
	}

}
void Image::illinify(){
	for (unsigned x = 0; x < this->width(); x++) {
		for (unsigned y = 0; y < this->height(); y++) {
			HSLAPixel *pixel = this->getPixel(x, y);
			if ((pixel->h > 113.5)&&(pixel->h <= 293.5)){
				pixel->h = 216;
			}else{
				pixel->h = 11;
			}
			// double toOrange = abs(pixel->h - 11);
			// double toBlue = abs(pixel->h - 216);
			// if (toOrange > toBlue){
			//   pixel->h = 216;
			// }else{
			//   pixel->h = 11;
			// }
		}
	}
}
void Image::scale(double factor){
	unsigned int newW = factor*this->width();
	unsigned int newH = factor*this->height();
	// cout<<newW<<endl;
	// cout<<newH<<endl;
// CHANGE!!!!!!!!!!!!
	//Image* out = new Image(newW, newH);
	Image* out = new Image(newW, newH);
	// cout<<out<<endl;
	// cout<<out->width()<<" "<<out->height()<<endl;
	for (unsigned x = 0; x < newW; x++) {
		for (unsigned y = 0; y < newH; y++) {
			HSLAPixel* pixel = out->getPixel(x, y);
			pixel->h = this->getPixel(int(x/factor), int(y/factor))->h;
			pixel->s = this->getPixel(int(x/factor), int(y/factor))->s;
			pixel->l = this->getPixel(int(x/factor), int(y/factor))->l;
			pixel->a = this->getPixel(int(x/factor), int(y/factor))->a;
		}
	}
	*this = *out;
	delete out; out=NULL;
	// cout<<this<<endl;
	// this = out;
}
void Image::scale(unsigned w, unsigned h){
	double scaleW = double(this->width())/double(w);
	double scaleH = double(this->height())/double(h);
	int aveW;
	int aveH;
	if (scaleW >= 1){
		aveW = scaleW;
	}else{
		aveW = 1;
	}
	if (scaleH >= 1){
		aveH = scaleH;
	}else{
		aveH = 1;
	}
	Image* out = new Image(w, h);

	// cout<<aveW<<"and"<<aveH<<endl;

	for (unsigned x = 0; x < w; x++) {
		for (unsigned y = 0; y < h; y++) {
			HSLAPixel* pixel = out->getPixel(x, y);
			//take average 
			double hn=0;
			double sn=0;
			double ln=0;
			double an=0;
			for (int i=0; i<aveW; i++){
				for (int j=0; j<aveH; j++){
					hn += this->getPixel(int(x*scaleW)+i,int(y*scaleH)+j)->h;
					// cout << y << endl;
					// cout << scaleH << endl;
					// cout << y*scaleH << endl;
					// cout << int(y*scaleH) << endl;
					// cout << int(y*scaleH)+j <<endl;
					// cout<<int(x*scaleW)+i<<" and "<<int(y*scaleH)+j<<endl;
					sn += this->getPixel(int(x*scaleW)+i,int(y*scaleH)+j)->s;
					ln += this->getPixel(int(x*scaleW)+i,int(y*scaleH)+j)->l;
					an += this->getPixel(int(x*scaleW)+i,int(y*scaleH)+j)->a;
				}
			}
			hn /= double(aveW*aveH);
			sn /= double(aveW*aveH);
			ln /= double(aveW*aveH);
			an /= double(aveW*aveH);
			pixel->h = hn;
			pixel->s = sn;
			pixel->l = ln;
			pixel->a = an;
			// pixel->h = this->getPixel(int(x/scaleW), int(y/scaleH))->h;
			// pixel->s = this->getPixel(int(x/scaleW), int(y/scaleH))->s;
			// pixel->l = this->getPixel(int(x/scaleW), int(y/scaleH))->l;
			// pixel->a = this->getPixel(int(x/scaleW), int(y/scaleH))->a;
		}
	}
	*this = *out;
	delete out; out=NULL;
}

Image::~Image(){}
