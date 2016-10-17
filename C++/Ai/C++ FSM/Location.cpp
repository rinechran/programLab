//
//  Location.cpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#include "Location.hpp"
std::string to_string(Location &obj){
        switch(obj){
            case Location::kitchen:
                return "kitchen";
                break;
            case Location::hall:
                return "hall";
                break;
            case Location::TomHouse:
                return "TomHouse";
                break;
            case Location::JerryHouse:
                return "JerryHouse";
                break;
    
        }
        return "";
    
}
