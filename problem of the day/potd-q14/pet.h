// pet.h
#ifndef PET_H
#define PET_H
#include <string>
#include "animal.h"
using namespace std;

class Pet: public Animal{
private:
	string name_;
	string owner_name_;
public:
	Pet();
	Pet(string type, string food, string name, string ownerName);
	// string getFood();
	// void setFood(string food);
	string getName();
	void setName(string name);
	string getOwnerName();
	void setOwnerName(string name);
	string print();
};

#endif