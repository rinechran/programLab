//
//  CharacterState.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef CharacterState_hpp
#define CharacterState_hpp
#include "Character.hpp"
#include "State.hpp"



class TomInHouse : public State<Tom> {
public:
    TomInHouse() : State<Tom>() {
        
    }
    virtual void excute(Tom *  obj ){
        location = Location::TomHouse;
        std::cout<<"Tom house"<<std::endl;
        
        //  std::cout<<"Tom Location : " << getLocationString(location)<<std::endl;
    }
    
    
    
    
};


class JerryInHouse : public State<Jerry>{
public:
    JerryInHouse() : State<Jerry>() {
        
    }
    virtual void excute(Jerry * obj){
        
    }
    
};


#endif /* CharacterState_hpp */
