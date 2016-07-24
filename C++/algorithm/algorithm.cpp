#include <iostream>
#include <cassert>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <numeric>
using namespace std;


int main() {
	//std::find 값을 못찾으면 arr[4]를 반환
	int arr[4] = { 10, 20, 30, 10 };

	
	//find
	cout << *std::find(&arr[0], &arr[4], 30) << endl;

	cout << *std::find(&arr[0], &arr[4], 0) << endl;

	int index = std::find(&arr[0], &arr[4], 20) - &arr[0];
	cout << index << endl;; // arr[4]


	//for_each


	for_each(&arr[0], &arr[4], [&](int &i) {i= i * 10;});

	//element
	cout << *max_element(&arr[0], &arr[4]) << endl;

	cout << *min_element(&arr[0], &arr[4]) <<endl;

	//count count_if
	cout << count(&arr[0], &arr[4], 200) << endl;;
	cout << count_if(&arr[0], &arr[4], [&](int &i) { return i == 100;}) << endl;;

	//accumulate
	cout << std::accumulate(&arr[0], &arr[4], 0) << endl;;
	cout << std::accumulate(&arr[0], &arr[4], 0, [](int a, int b) {return a + b;}) << endl;;



}
