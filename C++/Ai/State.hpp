//
//  State.hpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 14..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef State_hpp
#define State_hpp


class State{
public:
    virtual void excute() = 0;
};

class MinerBag : State{
public:
    MinerBag();
    
    virtual void excute(){
        
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
