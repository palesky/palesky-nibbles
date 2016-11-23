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
#include <vector>
#include "cocos2d.h"
#include "Joystick.hpp"
USING_NS_CC;
class Snake:public Node{
public:
    virtual bool init();
    CREATE_FUNC(Snake);
private:
    bool isDead = false;
    float angle ;
    float angleDest ;
    float speed ;
    //蛇头旋转的速度
    float rotationSpeed = 500;
    int score;
    int length;
   
    Color3B color;
    bool isEnemy ;
    
    Sprite * head;
    
    Vector<Sprite *> body;
    
    float path[100][2];
    int idx_path = 0;
    int size_path = 0;
public:
    bool addBody();
    bool initBody();
public:
    void onUpdate(float dt);
    
};
#endif /* Snake_hpp */
