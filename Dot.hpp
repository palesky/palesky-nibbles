//
//  Dot.hpp
//  nibbles
//
//  Created by xujunyu on 2016/11/21.
//
//

#ifndef Dot_hpp
#define Dot_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Snake.hpp"
USING_NS_CC;
class Dot:public Sprite{
public:
    CREATE_FUNC(Dot);
    virtual bool init();
    void onUpdate(float dt);
    void checkKill(Snake * snake);
private:
    Color3B color;
    bool isKilled = false;
    Vec2 position ;
    //isBody 和 py中的isBig相同
    bool isBody ;
    float scale ;
    
};
#endif /* Dot_hpp */
