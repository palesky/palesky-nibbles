//
//  LoadLayer.hpp
//  Nibbles
//
//  Created by xujunyu on 2016/11/17.
//
//

#ifndef LoadLayer_hpp
#define LoadLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.hpp"
USING_NS_CC;
class LoadLayer:public Layer{
public:
    CREATE_FUNC(LoadLayer);
    virtual bool init();
    void onScheduleOnce(float dt);
public:
    SceneManager * tsm;
};
#endif /* LoadLayer_hpp */
