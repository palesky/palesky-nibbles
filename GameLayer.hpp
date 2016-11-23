//
//  GameLayer.hpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.hpp"
#include "AreaLayer.hpp"
#include "Joystick.hpp"
#include "GameOverLayer.hpp"
USING_NS_CC;
class GameLayer:public Layer{
public:
    CREATE_FUNC(GameLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
public:
    SceneManager * tsm;
private:
    float rankingList_width=0.25;
    float rankingList_height=0.4;
    float infoList_width=0.1;
    float infoList_height=0.1;
};
#endif /* GameLayer_hpp */
