#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
using namespace std;

int main() {
	Image alma;
	alma.readFromFile("tests/alma.png");

	alma.scale(2.0);
	Image i;
	i.readFromFile("tests/i.png");

	Image pig;
	pig.readFromFile("pig.png");

	Image homer;
	homer.readFromFile("homer.png");

	// Image rick;
	// rick.readFromFile("rick.png");

	Image rick2;
	rick2.readFromFile("ricknmorty.png");

	Image homer2;
	homer2.readFromFile("homer2.png");

	Image bob;
	bob.readFromFile("bob.png");

	StickerSheet sheet(alma, 3);
	sheet.changeMaxStickers(10);
	sheet.addSticker(i, 20, 200);
	sheet.addSticker(pig, 100, 50);
	// sheet.addSticker(rick, 150, 60);
	sheet.addSticker(homer, 200, 180);
	sheet.addSticker(bob, 1000, 300);
	sheet.addSticker(homer2, 50, 650);
	sheet.addSticker(rick2, 300, 550);
	sheet.translate(0,50,700);
	sheet.removeSticker(0);
	Image* tryOne = sheet.getSticker(0);
	(*tryOne).writeToFile("tryOne.png");
	// Image expected;
	// expected.readFromFile("tests/expected.png");

	sheet.render().writeToFile("myImage.png");//I add this line

	// REQUIRE( sheet.render() == expected );
	return 0;
}
