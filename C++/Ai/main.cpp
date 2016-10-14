//
//  main.cpp
//  C++ test
//
//  Created by Eun Sik Jung on 2016. 10. 6..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <memory>
#include "Character.hpp"





int main(){
    
    Miner miner;
    MinerWife minerWife;
    while(1){
        miner.update();
        minerWife.update();
        getchar();
    }
}
