//
//  SingTon.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef SingTon_hpp
#define SingTon_hpp

#include <mutex>

template <typename T>
class SingTon{
public:
    static T* getInstance() {
//        sMutex.lock();
        if(_obj==nullptr)
            _obj = new T();
//        sMutex.unlock();
        return _obj;
        
    }
    
private:
    static T * _obj;
    static std::mutex sMutex;
};

template <typename T>
T * SingTon<T>::_obj = nullptr;

#endif /* SingTon_hpp */
