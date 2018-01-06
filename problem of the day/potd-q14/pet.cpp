// pet.cpp
#include "pet.h"
#include <string>

using namespace std;

Pet::Pet()
:Animal(),name_("Fluffy"),owner_name_("Cinda"){
}
Pet::Pet(string type, string food, string name, string ownerName)
:Animal(type, food), name_(name), owner_name_(ownerName){
}
// string pet::getFood(){
// 	return this->food_;
// }
// void pet::setFood(string food){
// 	this->food_ = food;
// }
string Pet::getName(){
	return this->name_;
}
void Pet::setName(string name){
	this->name_ = name;
}
string Pet::getOwnerName(){
	return this->owner_name_;
}
void Pet::setOwnerName(string name){
	this->owner_name_ = name;
}
string Pet::print(){
	string out = "My name is "+this->name_;
	return out;
}