#include <iostream>
#include <cassert>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
T clamp(T x, T low, T high) {
	assert(low < high);
	return std::min(std::max(x, low), high);
	
}
void MinMax();
int main() {
	cout << "std::min std::max" << endl;
	MinMax();
	
}

void MinMax() {
	//Upward value
	//Max value = 50
	const int maxValue = 50;

	int value = 20;
	value = std::min(value, maxValue);
	cout << value << endl;


	value = 60;
	value = std::min(value, maxValue);
	cout << value << endl;


	//Lower value
	//Max value = 0
	const int minValue = 0;

	value = 20;
	value = std::max(value, minValue);
	cout << value << endl;


	value = -1;
	value = std::max(value, minValue);
	cout << value << endl;


	//Lower  Upward value

	value = 20;
	value = std::max(std::min(value, maxValue), minValue);
	cout << value << endl;


	value = -1;
	value = std::max(std::min(value, maxValue), minValue);
	cout << value << endl;


	//template function
	value = 60;
	value = clamp(60, minValue, maxValue);
	cout << value << endl;
}