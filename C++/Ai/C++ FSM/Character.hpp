//
//  Character.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//
#include <iostream>
#ifndef Character_hpp
#define Character_hpp


class BaseObject{
public:
    BaseObject() : uId(TotalUid++){
    }
    
    int getUid(){
        return this->uId;
    }
    
    virtual ~BaseObject(){};
    
private:
    const uint uId;

    static uint TotalUid;
    
};



class Tom : public BaseObject{
public:
    Tom() : BaseObject(){
        std::cout<<"hello Tom : " << this->getUid() <<std::endl;
    }
    ~Tom(){
        std::cout<<"Tom Die"<<std::endl;;
    }
    
};


class Jerry : public BaseObject{
public:
    Jerry() : BaseObject(){
        std::cout<<"Jerry Tom : " << this->getUid() <<std::endl;
    }
};



#endif /* Character_hpp */
