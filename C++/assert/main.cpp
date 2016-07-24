#include <iostream>
#include <cassert>
#include <string>
using namespace std;

int distance(int start, int end) {
	assert(!"invalid imput "&& start < end);
	return end - start;
}
int main() {
	cout << "Normal imput" << endl;
	cout << distance(10, 11);

	cout << "invalid imput" << endl;
	cout << distance(12, 10);

}