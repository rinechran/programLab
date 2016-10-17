//
//  State.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Location.hpp"

#ifndef State_hpp
#define State_hpp




template <typename T>
class State{
    
public:
    State(){
    }
    virtual void excute(T * /* obj */) =0;
    Location location;
    
};

template <typename T>
class StateMachine{
public:
    StateMachine(){
        pCurrentState = nullptr;
        pBeforeState = nullptr;
        
    }
    void excute(){
        this->pCurrentState->excute();
    }
    void changeState(State<T> * obj){
        pBeforeState = pCurrentState;
        pCurrentState = obj;
    }
private:
    State<T> * pCurrentState;
    State<T> * pBeforeState;
    
    
};


#endif /* State_hpp */
