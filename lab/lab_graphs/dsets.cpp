/* Your code here! */
#include <vector>
#include "dsets.h"

using namespace std;

void DisjointSets::addelements (int num){
	for (int i=0; i<num; i++){
		arr_.push_back(-1);
	}
}	

int DisjointSets::find (int elem){
	int output;
	if (arr_[elem]<0){
		output = elem;
	}else{
		output = find(arr_[elem]);
		// path compression step
		arr_[elem] = output;
	}
	return output;

}

void DisjointSets::setunion	(int a,int b){
	// find the root first
	a = find(a);
	b = find(b);

	int newSize = arr_[a] + arr_[b];

	if (arr_[a] < arr_[b]){
		arr_[b] = a;
		arr_[a] = newSize;
	}else{
		arr_[a] = b;
		arr_[b] = newSize;
	}
}

int DisjointSets::size (int elem){
	return -(arr_[find(elem)]);
}	
