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
#include "SingTon.hpp"



class TomInHouse : public State<Tom>{
public:
    TomInHouse() ;
    virtual void excute(Tom *  obj);
};


class TomSleep : public State<Tom> {
public:
    TomSleep();
    virtual void excute(Tom *  obj );
};

class TomTakeMoney : public State<Tom> {
public:
    TomTakeMoney();
    virtual void excute(Tom *  obj );
};







class JerryInHouse : public State<Jerry>{
public:
    JerryInHouse() ;
    virtual void excute(Jerry * obj);
    
};

class JerryTomSerch : public State<Jerry>{
public:
    JerryTomSerch();
    virtual void excute(Jerry * obj);
    
};

class JerryTomMoney : public State<Jerry>{
public:
};

#endif /* CharacterState_hpp */
