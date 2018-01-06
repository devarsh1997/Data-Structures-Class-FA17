/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

/** maps TileImages to a MosaicCanvas based
*	on which TileImage has an average color
*	that is closest to the average color
*	of that region in the original image.
**/
MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> & theTiles)
{
    /**
     * @todo Implement this function!
     */
	// get size of theSource and output MosaicCanvas
	int row = theSource.getRows();
	int col = theSource.getColumns();
	// create the output MosaicCanvas which has same size as source
	MosaicCanvas* output = new MosaicCanvas(row, col);
	// a mapping between points representing tiles, and corresponding tiles
	map<Point<3>, TileImage*> point_tile;
	// vector of points representing tiles, which is needed to create KDtree
	vector<Point<3>> points;
	// build the point_tile map and points vector
	for (size_t i=0; i<theTiles.size(); i++){
		HSLAPixel ave_pix = theTiles[i].getAverageColor();
		double h = ave_pix.h / 360;
		double s = ave_pix.s;
		double l = ave_pix.l;
		Point<3> pt;
		pt[0] = h;
		pt[1] = s;
		pt[2] = l;
		point_tile[pt] = &(theTiles[i]);
		points.push_back(pt);
	}
	// build the KDTree by points vector
	KDTree<3>* tile_tree = new KDTree<3>(points);
	// fill in tiles to mosaic canvas by findNearestNeighbor
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			HSLAPixel target = theSource.getRegionColor(i,j);
			double h = target.h / 360;
			double s = target.s;
			double l = target.l;
			Point<3> regional;
			regional[0] = h;
			regional[1] = s;
			regional[2] = l;
			Point<3> nearest = tile_tree->findNearestNeighbor(regional);
			// TileImage* found = point_tile[nearest];
			output->setTile(i,j,point_tile[nearest]);
		}
	}
    return output;
}
