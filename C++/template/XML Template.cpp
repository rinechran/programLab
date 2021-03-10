// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>




template <typename T>
std::string GetType(typename T) {
	return typeid(T).name();
}


template <>
std::string GetType<int>(int) {
	return "Interger";
}
template <>
std::string GetType<double>(double) {
	return "Float";
}
template <>
std::string GetType<std::string>(std::string) {
	return "String";
}
template <>
std::string GetType<const char*>(const char*) {
	return "String";
}

template <typename T>
std::string getValue(T value) {
	return value;
}
template <>
std::string getValue<int>(int i) {
	return std::to_string(i);
}
template <>
std::string getValue<double>(double i) {
	return std::to_string(i);
}



template <typename T>
std::string typeToXmlStirng(T type) {
	std::string result = "<" + GetType(type) + ">" + getValue(type) + "</" + GetType(type) + ">\n";
	return result;
}
template <typename T>
std::string print(T value) {
	return typeToXmlStirng(value);
}
template <typename T, typename ...AS>
std::string print(T type, AS&& ...as) {
	std::string result = typeToXmlStirng(type);
	result += print(as...);
	return result;
}

template < typename ...AS>
std::string foo(AS&& ...as) {
	return "<Foo>\n" + print(as...) +  "</Foo>";
}

int main()
{
	std::string result = foo("hello", 10,123.3,1000,400,"300");
	std::cout << result << std::endl;
}

