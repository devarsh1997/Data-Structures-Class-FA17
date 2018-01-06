// Your code here
#include "potd.h"
#include <string>
#include <vector>
using namespace std;

string getFortune(const string &s){
	vector<string> fortunes;
	fortunes.push_back("aaaa");
	fortunes.push_back("bbbb");
	fortunes.push_back("cccc");
	fortunes.push_back("dddd");
	fortunes.push_back("eeee");
	int mod = s.length()%5;
	return fortunes[mod];
	// if (s == "Will I get an A?"){
	// 	return "a";
	// }
	// if (s == "Where is the bug?"){
	// 	return "b";
	// }	
	// if (s == "Should I eat that"){
	// 	return "c";
	// }
	// if (s == "Why this segfault?!"){
	// 	return "d";
	// }
	// if (s == "What is on the exam?"){
	// 	return "e";
	// }
}