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
    State() = default;
    virtual void excute(T * /* obj */) =0;
    Location location;
};


template <typename T>
class StateMachine{
public:
    StateMachine();
    void excute(T * /* obj */);
    void changeState(State<T> * obj);
private:
    State<T> * pCurrentState;
    State<T> * pBeforeState;
        
};


template <typename T>
StateMachine<T>::StateMachine(){
    pCurrentState = nullptr;
    pBeforeState = nullptr;
}
template <typename T>
void StateMachine<T>::excute(T * obj ){
    if(!pCurrentState)
        return;
    this->pCurrentState->excute(obj);
}
template <typename T>
void StateMachine<T>::changeState(State<T> * obj){
    pBeforeState = pCurrentState;
    pCurrentState = obj;
}

#endif /* State_hpp */
