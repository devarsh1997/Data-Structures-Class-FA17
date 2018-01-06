// Your code here!
#include <string>
#include <iostream>
#include "thing.h"

using namespace std;
using namespace potd;
Thing::Thing(int size){
	this->props_ct_ = 0;
	this->props_max_ = size;
	this->properties_ = new string[props_max_];
	this->values_ = new string[props_max_];
}

Thing::Thing(const Thing& that){
	this->_copy(that);
}

Thing& Thing::operator=(const Thing& that){
	if (this != &that){
		this->_destroy();
	// cout<<"success delete origin one"<<endl;

		this->_copy(that);
	}
	
	// this->props_ct_ = that.props_ct_;
	// this->props_max_ = that.props_max_;
	// this->properties_ = that.properties_;
	// this->values_ = that.values_;
	return *this;
}


Thing::~Thing(){
	this->_destroy();
}

int Thing::set_property(string name,string value){
	for (int i=0; i<props_ct_; i++){
		if (properties_[i] == name){
			values_[i] = value;
			return i;
		}
	}
	if (props_ct_ >= props_max_){
		return -1;
	}
	this->properties_[props_ct_] = name;
	this->values_[props_ct_] = value;
	props_ct_ += 1;
	return (props_ct_-1);
}


string Thing::get_property(string name){
	for (int i=0; i<props_ct_; i++){
		if (properties_[i] == name){
			return values_[i];
		}
	}
	return "";
}

void Thing::_copy(const Thing& that){
	this->props_ct_ = that.props_ct_;
	this->props_max_ = that.props_max_;
	this->properties_ = new string[this->props_max_];
	this->values_ = new string[this->props_max_];
	for (int i=0; i<this->props_ct_; i++){
		this->properties_[i] = that.properties_[i];
		this->values_[i] = that.values_[i];
	}
}

void Thing::_destroy(){
	// cout<<"address of properties_ is "<<properties_<<endl;
	// cout<<"address of values_ is "<<values_<<endl;
	delete[] this->properties_; this->properties_=NULL;
	// cout<<properties_<<endl;

	delete[] this->values_; this->values_ = NULL;
	// cout<<"call destroy()"<<endl;
	// cout<<"address of properties_ is "<<properties_<<endl;
	// cout<<"address of values_ is "<<values_<<endl;
 //    int size = *(&properties_ + 1) - properties_;
 //    // cout<<size<<endl;
	// for (int i=0; i<size; i++){
	// 	delete properties_[i];
	// 	properties_[i] = NULL;
	// }

}