//
//  Character.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//
#include <iostream>

#include <string>
#include "BaseObject.hpp"

#ifndef Character_hpp
#define Character_hpp


template <typename T>
class StateObject : public BaseObject{
public:
    StateMachine<T> stateMachine;
};

class Tom : public StateObject<Tom> {
public:
    Tom() {
        this->stamina = 0;
        this->money = 0;
        std::cout<<"hello Tom : " << this->getUid() <<std::endl;
    }
    Tom(State<Tom> * state) :Tom() {
        
        this->stateMachine.changeState(state);
    }
    void update(){
        stateMachine.excute(this);
    }
    int getStamina(){
        return stamina;
    }
    void SetStamina(int n){
        std::max(n,0);
        stamina = n;
    }
    void setMoney(int n){
        this->money = n;
    }
    int GetMoney(){
        return this->money;
    }
    void printStatus(){
        std::cout<<"Money : "<<money<<std::endl;
        std::cout<<"Stamina : "<<stamina<<std::endl;
    }
    
  private:
  
    int money;
    int stamina;
    

};

class Jerry : public StateObject<Jerry> {
public:
    Jerry() {
        stamina = 0;
        money = 0;
        std::cout<<"hello Jerry : " << this->getUid() <<std::endl;
    }
    
    Jerry(State<Jerry> * state) :Jerry() {
        
        this->stateMachine.changeState(state);
    }
    void update(){
        stateMachine.excute(this);
    }
    void setMoney(int n){
        this->money = n;
    }
    int GetMoney(){
        return this->money;
    }
    int getStamina(){
        return stamina;
    }
    void SetStamina(int n){
        std::max(n,0);
        stamina = n;
    }
    
    int stamina;
    int money;
};






#endif /* Character_hpp */
