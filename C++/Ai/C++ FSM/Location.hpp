//
//  Location.hpp
//  C++ FSM
//
//  Created by Eun Sik Jung on 2016. 10. 17..
//  Copyright © 2016년 Eun Sik Jung. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp
#include <string>
enum class Location{
    kitchen,hall,TomHouse,JerryHouse
};
//
std::string getLocationString(Location &obj);

#endif /* Location_hpp */
