#include <iostream>
#include <algorithm>
#include <functional>
#include <algorithm>
#include <random>     
template <typename T>
bool compare(T a, T b) {
	return a < b;
}

template <typename T >
void selectionSort(T *arr ,int size ) {
	for (int i = 0;i < size - 1;i++) {
		for (int j = i+1; j < size ; j++) {
			if ( compare(arr[j], arr[i])) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

template <typename T >
void insertSort(T *arr, int size) {
	for (int i = 1;i < size;i++) {
		for (int j = 0;j < i;j++) {
			if (compare(arr[i], arr[j])) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
}
template <typename T >
void bubbleSort(T *arr, int size) {
	for (int i = 0;i < size;i++) {
		for (int j = 0;j < size;j++) {
			if (compare(arr[i], arr[j])) std::swap(arr[i], arr[j]);
		}
	}
}
template <typename T >
void quickSort(T arr[], T left, T right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (arr[i] < pivot)
		i++;
	while (arr[j] > pivot)
		j--;
	if (i <= j) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
			i++;
			j--;
	}
	

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
int main() {


	int arr[] = {1,2,3,4,5,6 };
	std::shuffle(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])], std::default_random_engine(NULL));
	//selectionSort(arr, sizeof(arr)/sizeof(arr[0]));
	
	quickSort(arr, 0,5);
	for (int i = 0;i < sizeof(arr) / sizeof(arr[0]);i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;

	
	

}