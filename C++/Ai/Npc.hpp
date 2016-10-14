//
//  Npc.hpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 14..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef Npc_hpp
#define Npc_hpp
#include "Character.hpp"
#include <iostream>
#include "SingleTon.hpp"


class Miner : BaseObject{
private:
    int mGold;
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
#endif /* Npc_hpp */
