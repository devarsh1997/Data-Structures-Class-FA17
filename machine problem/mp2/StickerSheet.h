#ifndef STICKERSHEET_H
#define STICKERSHEET_H

#include "Image.h"

class StickerSheet{
public:
	StickerSheet (const Image &picture, unsigned max);
	StickerSheet (const StickerSheet &other);
	const StickerSheet & 	operator= (const StickerSheet &other);
	~StickerSheet ();

	void changeMaxStickers (unsigned max);
	int addSticker (Image &sticker, unsigned x, unsigned y);
	bool translate (unsigned index, unsigned x, unsigned y);
	void removeSticker (unsigned index);
	Image* getSticker (unsigned index) const;
	Image render () const;

	void _copy(const StickerSheet& other);
	void _destroy();
private:
	unsigned img_ct;
	unsigned img_max;
	Image* baseImage;
	Image** imageList;
	unsigned* xCord;
	unsigned* yCord;
};

#endif



 	