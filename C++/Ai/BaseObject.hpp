//
//  BaseObject.hpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 14..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef BaseObject_hpp
#define BaseObject_hpp

class BaseObject{
public:
    BaseObject();
    int getUid();
    virtual void update() = 0;
    virtual ~BaseObject() = 0;
protected:
    int mUid;
    static int mObjectCount;
    
};

#endif /* BaseObject_hpp */
