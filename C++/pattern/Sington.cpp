#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>


using namespace std;

template <typename T>
class Sington {
public:
	static T* get(){
		if (_singleton)
			return _singleton;
		_singleton = new T;
		
		return _singleton;
	}
	static T * _singleton;
};

template <typename T>
T* Sington<T>::_singleton = NULL;

class AAA : public Sington<AAA> {
public:
	int a;
};

class BBB : public Sington<BBB> {
public:
	int a;
};
int main() {
	AAA * a = AAA::get();
	AAA * b = AAA::get();
	a->a = 30;
	cout << b->a << endl;

	BBB * c = BBB::get();
	BBB * d = BBB::get();
	c->a = 50;
	a->a = 500;
	cout << b->a << endl;;
	cout << c->a << endl;;

	
}
