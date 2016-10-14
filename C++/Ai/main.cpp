//
//  main.cpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 6..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <memory>
#include "BaseObject.hpp"

class State{
public:
    virtual void Excute() = 0;
};
class StateMusin{
public:
    State * mPtrStage;
    
};



class Miner : BaseObject{
public:
    Miner() : BaseObject(){
        std::cout<<"Miner :"<< this->getUid()<<std::endl;
    }
    void update(){
        
    }

    
};
class MinerWife : BaseObject{
public:
    MinerWife() : BaseObject(){
        std::cout<<"MinerWife :"<< this->getUid()<<std::endl;
    }
    void update(){
    }
    
};
int main(){
    
    Miner miner;
    MinerWife minerWife;
}
