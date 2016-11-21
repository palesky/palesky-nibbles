//
//  OpenLayer.hpp
//  AirHockey
//
//  Created by xujunyu on 2016/11/17.
//
//

#ifndef OpenLayer_hpp
#define OpenLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.hpp"
USING_NS_CC;
class OpenLayer:public Layer{
public:
    CREATE_FUNC(OpenLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
public:
    SceneManager * tsm;
};
#endif /* OpenLayer_hpp */
