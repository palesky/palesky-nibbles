//
//  AreaLayer.hpp
//  nibbles
//  蛇运动的层
//  Created by xujunyu on 2016/11/20.
//
//

#ifndef AreaLayer_hpp
#define AreaLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.hpp"
#include "Snake.hpp"
#include "Joystick.hpp"
#include <cmath>
USING_NS_CC;
class AreaLayer:public LayerColor{
public:
    CREATE_FUNC(AreaLayer);
    virtual bool init();
    void addEnemy();
    void onUpdate(float dt);
public:
    SceneManager * tsm;
private:
    float width=5000;
    float height=3000;
    double mAnagle = 0;
    Snake * snake;
};
#endif /* AreaLayer_hpp */
