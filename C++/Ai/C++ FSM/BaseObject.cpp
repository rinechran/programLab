//
//  BaseObject.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include "BaseObject.hpp"
unsigned BaseObject::TotalUid = 0;

int BaseObject::getUid(){
    return this->uId;
}
BaseObject::BaseObject(): uId(TotalUid++){
}
