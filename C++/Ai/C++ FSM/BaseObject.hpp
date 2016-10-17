//
//  BaseObject.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef BaseObject_hpp
#define BaseObject_hpp
#include "State.hpp"



class BaseObject{
public:
    BaseObject() ;
    int getUid();
    virtual void update() = 0;
    virtual ~BaseObject(){};
    
private:
    const unsigned int uId;
    static unsigned int TotalUid;
    
    
};



#endif /* BaseObject_hpp */
