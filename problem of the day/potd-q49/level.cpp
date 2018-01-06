#include "MinHeap.h"
#include <math.h>

vector<int> lastLevel(MinHeap & heap)
{
    // Your code here
	vector<int> output;
	int node_num = heap.elements.size();
	int h = log2(node_num);
	int lo = pow(2,h);
	for (int i=lo; i<node_num; i++){
		output.push_back(heap.elements[i]);
	}
	return output;
}

