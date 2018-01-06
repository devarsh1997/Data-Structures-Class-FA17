// your code here
#ifndef BAR_H
#define BAR_H

#include "foo.h"
#include <string>
using namespace std;

namespace potd{
	class bar{
	public:
		bar(string in);
		bar(const bar &that);
		bar& operator = (const bar &that);
		string get_name() const;
		~bar();
	private:
		foo* f_;
	};
}

#endif