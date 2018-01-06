#include <vector>
#include "Primes.h"
using namespace std;

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
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

int numSequences(std::vector<int> *primes, int num) {

    // your code here
	int ct = 0;
	vector<int>::iterator start_it = primes->begin();
	while (true){
		int sum = 0;
		for (vector<int>::iterator it=start_it; it!=primes->end(); it++){
			sum += *it;
			if (sum >= num){
				break;
			}
		}
		if (sum == num){
			ct += 1;
		}
		start_it++;
		if (start_it == primes->end()){
			break;
		}
	}
	return ct;
}
