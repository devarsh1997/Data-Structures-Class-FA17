#ifndef THING_H
#define THING_H

#include <string>
using namespace std;
namespace potd {
  class Thing {
  public:
    Thing(int size);
    Thing(const Thing &);
    Thing & operator=(const Thing &);
    ~Thing();

    int set_property(string name, string value);
    string get_property(string name);

  private:

    void _copy(const Thing &);
    void _destroy();

    string* properties_;
    string* values_;
    int props_ct_;
    int props_max_;
  };
}
#endif
