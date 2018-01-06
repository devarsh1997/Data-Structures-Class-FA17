#include "intersperse.h"
#include <vector>
using namespace std;

vector<int>::iterator findMax(vector<int>& v){
	vector<int>::iterator max_it = v.begin();
	for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		if (*it > *max_it){
			max_it = it;
		}
	}
	return max_it;
}

vector<int> zigZag(vector<int> v1, vector<int> v2){

	//write your code here
	vector<int> out;
	while ((!v1.empty()) && (!v2.empty())){
		vector<int>::iterator v1_max = findMax(v1);
		vector<int>::iterator v2_max = findMax(v2);
		out.push_back(*v1_max);
		out.push_back(*v2_max);
		v1.erase(v1_max);
		v2.erase(v2_max);
	}
	return out;
}

