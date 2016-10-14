//
//  State.hpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 14..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef State_hpp
#define State_hpp
#include <random>
#include <iostream>
class State{
public:
    virtual void excute() = 0;
};

class MinerGoldPull : State{
public:
    MinerGoldPull(){};
    virtual void excute(){
        std::mt19937 mt;
        std::uniform_int_distribution<int> a(0,3);

    }
};




class StateMachine{
public:
    State * mCurrentStage;
    State * mNowStage;
    StateMachine(){
        mCurrentStage = nullptr;
        mNowStage = nullptr;
    }
    void inputStage(State * stage){
        mCurrentStage = mNowStage;
        mNowStage = stage;
    }
    void excute(){
        mNowStage->excute();
    }
};

#endif /* State_hpp */
