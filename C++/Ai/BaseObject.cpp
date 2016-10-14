//
//  BaseObject.cpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 14..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//


#include "BaseObject.hpp"

BaseObject::BaseObject(){
    this->mUid = mObjectCount++;
}
BaseObject::~BaseObject(){}

int BaseObject::getUid(){
    return mUid;
}


int BaseObject::mObjectCount =0;
