#include <vector> 
#include <list> 
#include <stack> 
#include <iostream> 
#include <typeinfo> 


template <typename T,typename ...AS>
void print(T type,AS&& ...as) {
	std::cout << type << endl;
	print(as...);
}
void print() {

}

int main()
{
	//cout << add(3.0);
	print(3, 4, 5, 5, 6, 7, 7, 7,"asdas");
	//print(3, 4, 5, 6, 7, 10);
}