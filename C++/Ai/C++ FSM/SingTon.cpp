//
//  SingTon.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include "SingTon.hpp"
#include <mutex>
template <typename T>
class SingTon{
public:
    SingTon(){
        _obj = nullptr;

    }
    static T* getInstance (){
        sMutex.lock();
        if(_obj==nullptr)
            _obj = new T;
        sMutex.unlock();
        return _obj;

    }
    
private:
    static T * _obj;
    static std::mutex sMutex;
};
