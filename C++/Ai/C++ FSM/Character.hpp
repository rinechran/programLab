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
#include <string>
#include "CharacterState.hpp"
#include <typeinfo>
#ifndef Character_hpp
#define Character_hpp

class TomInHouse;


#include "CharacterState.hpp"

template <typename T>
class AiObject : public BaseObject{
public:
    AiObject() = default;
    std::string getLocation();
protected:
    StateMachine<T>  stateMachine;
    Location location;
};



class Tom : public AiObject<Tom>{
public:
    Tom() : AiObject<Tom>(){
        std::cout<<"hello Tom : " << this->getUid() <<std::endl;
        //stateMachine.changeState(TomInHouse);
        
    }
    ~Tom(){
        std::cout<<"Tom Die"<<std::endl;
        
    }
    void update();
  private:
  

};
//문제코드
template <typename T>
void Tom::update(){
    
}


class Jerry : public AiObject<Jerry>{
public:
    Jerry() : AiObject<Jerry>(){
        std::cout<<"hello Jerry : " << this->getUid() <<std::endl;
    }
    void update(){
        
    }
    

};




template <typename T>
std::string AiObject<T>::getLocation(){
    return to_string(location);
}

#endif /* Character_hpp */
