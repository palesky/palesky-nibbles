//
//  Dot.cpp
//  nibbles
//
//  Created by xujunyu on 2016/11/21.
//
//

#include "Dot.hpp"
bool Dot::init(){
    color = Color3B(0,0,0);
    Sprite::initWithFile("res/circle.png");
    this->setColor(color);
    log("add dot to areaLayer");
    

    return true;
}
