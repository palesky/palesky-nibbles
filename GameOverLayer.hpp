//
//  GameOverLayer.hpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#ifndef GameOverLayer_hpp
#define GameOverLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class GameOverLayer:public LayerColor{
public:
    CREATE_FUNC(GameOverLayer);
    virtual bool init();
};
#endif /* GameOverLayer_hpp */
