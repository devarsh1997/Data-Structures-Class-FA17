// your code here
#include "foo.h"
#include "bar.h"
#include <string>

using namespace potd;
using namespace std;

bar::bar(string in){
	this->f_ = new foo(in);
}
bar::bar(const bar &that){
	this->f_ = new foo(that.f_->get_name());
}

bar & bar:: operator = (const bar &that){
	delete this->f_;
	this->f_ = new foo(that.get_name());
	return *this;
}
string bar::get_name() const{
	return this->f_->get_name();
}

bar::~bar(){

	delete f_;this->f_=NULL;
	// delete this; 
}