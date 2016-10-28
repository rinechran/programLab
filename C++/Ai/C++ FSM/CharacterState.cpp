//
//  CharacterState.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include "CharacterState.hpp"


TomInHouse::TomInHouse() : State<Tom>(){
    location = Location::TomHouse;
}

void TomInHouse::excute(Tom *obj){
    
    std::cout<<"Tom house"<<std::endl;
    obj->SetStamina(obj->getStamina()-1);
    
    if(obj->getStamina()<=0){
        obj->stateMachine.changeState(SingTon<TomSleep>::getInstance());
//
        
    }
    else{
        obj->stateMachine.changeState(SingTon<TomTakeMoney>::getInstance());
    }

    
    
    
}

TomSleep::TomSleep() : State<Tom>(){
}

void TomSleep::excute(Tom *  obj ){
    std::cout<<"Tom Sleep"<<std::endl;
//    obj->printStatus();
    obj->SetStamina(obj->getStamina()+1);
    if(obj->getStamina()>=5){
        obj->stateMachine.changeState(SingTon<TomInHouse>::getInstance());
    }
}

TomTakeMoney::TomTakeMoney(): State<Tom>(){
}
void TomTakeMoney::excute(Tom *  obj ){
    std::cout<<"Tom Work"<<std::endl;
    
    obj->setMoney(obj->GetMoney()+100);
    obj->SetStamina(obj->getStamina()-1);
    
    if(obj->getStamina()<=2){
        obj->stateMachine.changeState(SingTon<TomInHouse>::getInstance());
//        return;
    }
    
    
}

JerryInHouse::JerryInHouse() : State<Jerry>() {
  
}

void JerryInHouse::excute(Jerry *obj){
      std::cout<<"Jerry house"<<std::endl;
}

JerryTomSerch::JerryTomSerch() : State<Jerry>(){
    
}
void JerryTomSerch::excute(Jerry *obj){
    
}
