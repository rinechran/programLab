#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct simple_iota_view
{
	T _from;
	T _to;
	operator vector<T>() {
		vector<T> v;
		v.reserve(_to - _from);
		for (;from != _to;from++) {
			v.emplace_back(from);
		}
		return v;
	}

};
struct simple_iota_fn{

	template<typename T>
	simple_iota_view<T> operator()(T beg, T end) {
		return { beg,end };
	}
}simple_iota;
int main() {
	vector<int> b = simple_iota(10, 30);
}