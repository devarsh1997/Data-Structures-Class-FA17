#include <iostream>
#include <string>
#include "Chara.h"
using namespace std;


int main() {
	Chara* test = new Chara();
	test->addToQueue("aa");
	test->addToQueue("bb");
	test->addToQueue("cc");
	test->addToQueue("dd");
	cout << test->getStatus() << endl;
	cout << test->popFromQueue() << endl;
	return 0;
}
