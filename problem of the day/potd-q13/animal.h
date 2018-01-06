// animal.h
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;
class Animal{
private:
	string type_;
	string food_;
public:
	Animal();
	Animal(string type, string food);
	string getType();
	void setType(string type);
	string getFood();
	void setFood(string food);
	string print();
};

#endif