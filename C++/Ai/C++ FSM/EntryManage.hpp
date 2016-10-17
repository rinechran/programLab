//
//  EntryManage.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef EntryManage_hpp
#define EntryManage_hpp
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>
#include "Character.hpp"

class EntryManage{
public:
    template <typename T>
    void newEntryObject(T * obj);
    void entryEarse(uint uid);
    void update();
private:
    std::vector<BaseObject*> arrObj;
    std::set<int,BaseObject*> message;
    
    
    
};


template <typename T>
void EntryManage::newEntryObject(T * obj){
    arrObj.push_back(obj);
}


void EntryManage::update(){
    std::for_each(arrObj.begin(), arrObj.end(),[](BaseObject * obj){
        obj->update();
        
    });
}

void EntryManage::entryEarse(uint uid){
    std::vector<BaseObject*>::iterator it = std::find_if(arrObj.begin(),arrObj.end(),
                                                         [uid](BaseObject* obj){
                                                             return obj->getUid() == uid;
                                                         });
    if (it != arrObj.end()){
        delete *it;
        arrObj.erase(it);
    }
    
}
#endif /* EntryManage_hpp */
