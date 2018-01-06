#include <string>
#include "pet.h"

using namespace std;

// Put your constructor code here!
Pet::Pet(){
	this->setName("Rover");
	this->setBY(2017);
	this->setType("dog");
	this->setOwnerName("Cinda");
}

Pet::Pet(string name, int birth_year, string type, string owner_name){
	this->setName(name);
	this->setBY(birth_year);
	this->setType(type);
	this->setOwnerName(owner_name);
}

void Pet::setName(string newName) {
  name = newName;
}

void Pet::setBY(int newBY) {
  birth_year = newBY;
}

void Pet::setType(string newType) {
  type = newType;
}

void Pet::setOwnerName(string newName) {
  owner_name = newName;
}

string Pet::getName() {
  return name;
}

int Pet::getBY() {
  return birth_year;
}

string Pet::getType() {
  return type;
}

string Pet::getOwnerName() {
  return owner_name;
}
