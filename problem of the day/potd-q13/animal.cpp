// animal.cpp
#include "animal.h"
#include <iostream>
#include <string>
using namespace std;

Animal::Animal(){
	this->type_ = "cat";
	this->food_ = "fish";
}
Animal::Animal(string type, string food){
	this->type_ = type;
	this->food_ = food;
}
string Animal::getType(){
	return this->type_;
}
void Animal::setType(string type){
	this->type_ = type;
}
string Animal::getFood(){
	return this->food_;
}
void Animal::setFood(string food){
	this->food_ = food;
}
string Animal::print(){
	string out = "I am a "+this->type_+".";
	return out;
}