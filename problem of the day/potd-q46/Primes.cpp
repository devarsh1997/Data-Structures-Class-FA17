#include <vector>
#include "Primes.h"
#include <iostream>

using namespace std;

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    // your code here
    for (int number=2; number<M+1; number++){
    	v->push_back(number);

    }

    vector<int>::iterator p = v->begin();
    while(true){
    	for (vector<int>::iterator i=p+1; i!=v->end();){
    		if (*i % *p == 0){
    			v->erase(i);
    		}else{
    			i++;
    		}
    	}
    	if (((*p)*(*p)) >= v->back()){
    		break;
    	}
    	p++;
    }
    return v;
}
