//
//  main.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>


#include "Character.hpp"

enum class Location{
    kitchen,hall,TomHouse,JerryHouse
};


class Message{
    uint to;
    uint from;
};
class MessageSander{
    
};

class MessageGetter{
    
};


class EntryManage{
public:
    template <typename T>
    void newEntryObject(T * obj){
        arrObj.push_back(obj);
    }
    void entryEarse(uint uid){
        std::vector<BaseObject*>::iterator it = std::find_if(arrObj.begin(),arrObj.end(),
                                                          [uid](BaseObject* obj){
                                                              return obj->getUid() == uid;
                                                          });
        if (it != arrObj.end()){
            delete *it;
            arrObj.erase(it);
        }
        
        
    }
private:
    std::vector<BaseObject*> arrObj;
    std::set<int,BaseObject*> message;
    
    
    
};

int main(int argc, const char * argv[]) {
    EntryManage entryManage;
    entryManage.newEntryObject(new Tom);
    entryManage.newEntryObject(new Jerry);
    entryManage.entryEarse(0);
    return 0;
}
