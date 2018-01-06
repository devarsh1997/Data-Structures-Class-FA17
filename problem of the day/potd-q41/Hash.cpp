#include <vector>
#include <string>
#include "Hash.h"
#include <algorithm>
using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
	int sum = 0;
	for(char& c : s) {
	    sum += int(c);
	}
	return sum%M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	int index;
	// Your Code Here
	vector<int> store;
	for (size_t k=0; k<inputs.size(); k++){
		index = hashFunction(inputs[k], M);
		if(find(store.begin(), store.end(), index) != store.end()){
			collisions += 1;
		}else{
			store.push_back(index);
		}
	}
	return collisions;
}
