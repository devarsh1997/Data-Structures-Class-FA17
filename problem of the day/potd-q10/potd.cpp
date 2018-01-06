// your code here!
#include "potd.h"
#include <iostream>
#include <cmath>
using namespace std;
namespace potd {

    int *raise(int *arr){
    	//count the length of array
    	int count = 1;
    	for(int i=0; arr[i] != -1; i++){
    		count += 1;
    	}
    	int* out = new int[count];
    	for (int i=0; i<count-2; i++){
    		out[i] = pow((arr[i]),(arr[i+1]));
    	}
    	out[count-2] = arr[count-2];
   		out[count-1] = arr[count-1];
     	return out;
    }
}