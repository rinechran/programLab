//
//  main.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 15..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <iostream>
#include "EntryManage.hpp"
#include "CharacterState.hpp"
//class Message{
//    uint to;
//    uint from;
//};
//class MessageSander{
//    
//};
//
//class MessageGetter{
//    
//};
//



int main(int argc, const char * argv[]) {
  
    EntryManage entryManage;
    
    Tom * tom = new Tom(SingTon<TomInHouse>::getInstance());
//    Jerry * jerry = new Jerry(SingTon<JerryInHouse>::getInstance());
    
    entryManage.newEntryObject(tom);
//     entryManage.newEntryObject(jerry);
    //
    
    for(int i=0;i<30;i++){
        entryManage.update();
    }
    entryManage.entryEarse(0);
    
    return 0;
}
