//
//  SingleTon.hpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 14..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef SingleTon_hpp
#define SingleTon_hpp
#include <mutex>




template <typename T>
class SingleTon{
public:
    static T* getInstance(){
        mx.lock();
        
        if(pObj==nullptr)
            pObj = new T;

        mx.unlock();
        return pObj;
    }
    static std::mutex mx;
    static T* pObj;
};

template <typename T>
T* SingleTon<T>::pObj = nullptr;

#endif /* SingleTon_hpp */
