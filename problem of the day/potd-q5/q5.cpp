// your code here
#include "q5.h"

void increase_quantity(food* foodPtr){
	int current = foodPtr->get_quantity();
	current += 1;
	foodPtr->set_quantity(current);
	// increases the quantity of a food by one.
}
