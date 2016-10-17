//
//  Character.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//
#include <iostream>
#include "BaseObject.hpp"
#include "State.hpp"

#ifndef Character_hpp
#define Character_hpp


class TomInHouse;
class JerryInHouse;


template <typename T>
class AiObject : public BaseObject{
protected:
    AiObject() = default;
    
    StateMachine<T> *stateMachine;
};


class Tom : public AiObject<Tom>{
public:
    Tom() : AiObject<Tom>(){
        std::cout<<"hello Tom : " << this->getUid() <<std::endl;
    }
    ~Tom(){
        std::cout<<"Tom Die"<<std::endl;;
    }
    void update(){
        
    }
  private:
    

};


class Jerry : public AiObject<Jerry>{
public:
    Jerry() : AiObject<Jerry>(){
        std::cout<<"Jerry Tom : " << this->getUid() <<std::endl;
    }
    void update(){
        
    }
    

};


class TomInHouse : public State<Tom> {
public:
    TomInHouse() : State<Tom>() {
        
    }
    virtual void excute(Tom * /* obj */){
        location = Location::TomHouse;
      //  std::cout<<"Tom Location : " << getLocationString(location)<<std::endl;
    }
    
    
};


class JerryInHouse : public State<Jerry>{
public:
    JerryInHouse() : State<Jerry>() {
        
    }
    virtual void excute(Tom * /* obj */){
        
    }
    
    
};



#endif /* Character_hpp */
