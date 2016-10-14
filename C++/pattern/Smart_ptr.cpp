//
//  main.cpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 6..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <memory>

template <typename T>
class smert_ptr{
    
public:
    int * count;
    T* ptr_object;
    
    smert_ptr(){
        count = new int(0);
        ptr_object = nullptr;
    }
    smert_ptr(T * _ptr){
        count = new int(1);
        ptr_object = _ptr;
    }
    smert_ptr(const smert_ptr &ptr){
        count = ptr.count;
        (*count)++;
        ptr_object = ptr.ptr_object;
    }
    int getCount(){
        return *count;
    }
    T* operator->(){
        return ptr_object;
    }
    ~smert_ptr(){
        
        (*count)--;
        if(*count <= 0){
            delete ptr_object;
            ptr_object=nullptr;
        }
    }
    
};

class A{
public:
    int a;
    A(){
        a=0;
    }
    
};
int main() {
    using namespace std;
    smert_ptr<A> ptr = new A;
    std::cout<<ptr->a;

    
    return 0;
}
