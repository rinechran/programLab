// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
std::ostream& operator<<(ostream& os, const char* str) {
    printf("%s", str);
    return os;
}

void Boo() {
    cout << "Boo" << endl;
}
void Hoo() {
    cout << "Hoo" << endl;
}


void koo() {

}


std::ostream& operator<<(ostream& os, const string& str) {
    Boo();
    printf("%s", str.c_str());
    return os;
}

std::ostream& endl(ostream& os)
{
    printf("\n");
    Hoo();

    return os;
}


void foo(string val, int val1, int val2,int val3) {
    std::cout << val << val1 << val2 << val3<< endl;
}




int main()
{
    koo();
    foo("asd", 1, 2,3);
}
