#include "List.h"
#include <iostream>



int main() {
	List<int> a;

	a.push_front(10);
	a.pop_front();
	a.print();
	
	a.push_front(10);
	a.print();

	a.push_front(30);
	a.print();

}