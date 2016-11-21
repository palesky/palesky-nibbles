//
//  Snake.hpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class Snake:public CCNode{
public:
    virtual bool init();
    CREATE_FUNC(Snake)
private:
    bool isDead = false;
    float angle ;
    float angleDest ;
    float speed ;
    Color3B color;
    bool isEnemy ;
    Sprite * head;
public:
    bool addBody();
    
    
};
#endif /* Snake_hpp */
