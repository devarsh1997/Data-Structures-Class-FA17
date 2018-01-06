// your code here
#include "Chara.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

string Chara::getStatus() const{
	int n = q.size();
	if (n == 0){
		return "Empty";
	}else if (n <= 3){
		return "Light";
	}else if (n <= 6){
		return "Moderate";
	}else{
		return "Heavy";
	}
}
void Chara::addToQueue(string name){
	q.push(name);
}
string Chara::popFromQueue(){
	string out = q.front();
	q.pop();
	return out;
}