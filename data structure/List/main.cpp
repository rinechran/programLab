#include "List.h"
#include <iostream>



int main() {
	List<int> a;
	a.print();
	a.push_front(10);
	a.pop_front();
	a.push_front(10);
	a.print();
	
	

}