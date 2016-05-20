#include <iostream>
#include <cassert>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <functional>
using namespace std;


#define HEIGHT 10
#define WIDTH 10

int map[HEIGHT][WIDTH];


void fEach(function<void(int&,int&)> fn) {
	for (int i = 0;i < HEIGHT;i++) {
		for (int j = 0; j < WIDTH; j++) {
			fn(i, j);
		}
	}
}

template <typename T>
void TEach(T fn) {
	for (int i = 0;i < HEIGHT;i++) {
		for (int j = 0; j < WIDTH; j++) {
			fn(i, j);
		}
	}
}
void cellPrint(int i, int j) {
	cout << map[i][j];
}
void addMap(int i, int j) {
	map[i][j]+=2;
}
int main() {
	fEach(addMap);
	cout << endl;
	fEach(cellPrint);
	cout << endl;

	TEach(addMap);
	cout << endl;
	TEach(cellPrint);
	cout << endl;



}
