//
//  main.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <iostream>
#include "EntryManage.hpp"

class Message{
    uint to;
    uint from;
};
class MessageSander{
    
};

class MessageGetter{
    
};





int main(int argc, const char * argv[]) {
    EntryManage entryManage;
    entryManage.newEntryObject(new Tom);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Jerry);
    entryManage.newEntryObject(new Tom);
    entryManage.newEntryObject(new Tom);
    entryManage.newEntryObject(new Tom);
    //new  TomInHouse();
    //
    
    for(int i=0;i<10;i++){
        entryManage.update();
    }
    entryManage.entryEarse(0);
    
    return 0;
}
