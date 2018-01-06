#include "Hash.h"
#include <string>
#include <iostream>

    // b_hash = 5381
    // for all character in str:
    //     b_hash *= 33 + character //use the ASCII value of the character here


unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for (std::string::iterator it=str.begin(); it!=str.end(); it++){
		b_hash *= 33;
		b_hash += int(*it);
	}

	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = "";
	//Your code here
	for (std::string::iterator it=str.end()-1; it>=str.begin(); it--){
		output += *it;
	}
	return output;
}
