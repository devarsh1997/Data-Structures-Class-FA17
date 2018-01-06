#include <iostream>
#include <string>
#include "piece.h"
#include "queen.h"
using namespace std;

// implementation of class queen
queen::queen(){
	piece();
}
string queen::getType(){
	return "Queen";
}