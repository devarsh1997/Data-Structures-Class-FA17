#include <string>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "mp1.h"

using namespace cs225;
using namespace std;

void rotate(std::string inputFile, std::string outputFile) {
	cs225::PNG in;
	in.readFromFile(inputFile);
	cs225::PNG out(in.width(),in.height());

	// cout << in.width() << endl;
	// cout << in.height() << endl;

	for (unsigned x = 0; x < in.width(); x++) {
		for (unsigned y = 0; y < in.height(); y++) {
		  HSLAPixel* inPixel = in.getPixel(x, y);
		  HSLAPixel* outPixel = out.getPixel(in.width()-x-1, in.height()-y-1);
		  outPixel->h = inPixel->h;
		  outPixel->s = inPixel->s;
		  outPixel->l = inPixel->l;
		  outPixel->a = inPixel->a;

		}
	}
  out.writeToFile(outputFile);
}
