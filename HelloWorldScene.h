#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
};

#endif // __HELLOWORLD_SCENE_H__
