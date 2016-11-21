//
//  SceneManager.hpp
//  Nibbles
//
//  Created by xujunyu on 2016/11/17.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class SceneManager{
public:
    Scene * loadScene;
    Scene * openScene;
    Scene * gameScene;
    
    void createLoadScene();
    void goOpenScene();
    void goGameScene();
    
    Scene * scene;
    void createScene();
};
#endif /* SceneManager_hpp */
