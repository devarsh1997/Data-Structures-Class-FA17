// Your code here
#include "food.h"
#include <string>

using namespace std;

food::food(){
	this->name_ = "apples";
	this->quantity_ = 5;
}

string food::get_name(){
	return this->name_;
}
void food::set_name(string name){
	this->name_ = name;
}
int food::get_quantity(){
	return this->quantity_;
}
void food::set_quantity(int quant){
	this->quantity_ = quant;
}

