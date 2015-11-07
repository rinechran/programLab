#include <iostream>
#include "Char.hpp"


using namespace std;


int main() {
	Char korea("hello");
	Char temp = " wolrd";
	cout << korea << endl;;
	korea = korea + temp;
	cout << korea << endl;;



}