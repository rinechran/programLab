//
//  State.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include "Character.hpp"

template <typename T>
class State{
    virtual void excute(T * /* obj */){
        
    }
public:
    
};

class TomInHouse : State<Tom>{
    virtual void excute(Tom * /* obj */){
        
    }
public:
    
};


class JerryInHouse : State<Jerry>{
    virtual void excute(Tom * /* obj */){
        
    }
public:
    
};


template <typename T>
class StateMachine{
    
    State<T> * pCurrentState;
    State<T> * pBeforeState;
    
    StateMachine(){
        pCurrentState = nullptr;
        pBeforeState = nullptr;
        
    }
    void excute(){
        this->pCurrentState->excute();
    }
    void changeState(T * obj){
        pBeforeState = pCurrentState;
        pCurrentState = obj;
    }
    
};


#endif /* State_hpp */
