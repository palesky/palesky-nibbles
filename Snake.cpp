//
//  Snake.cpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#include "Snake.hpp"
bool Snake::init(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->setScale(1.5);
    this->setPosition(Vec2(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height/2));
//    this->setPosition(Vec2(2500,1500));
    
    isDead = false ;
    angle = 180 ;
    angleDest = angle ;
    color = Color3B(123,132,123);
    speed = 150;
    
    //添加头部
    head= new Sprite();
    head->initWithFile("res/circle.png");
    head->setScale(2);
    head->setAnchorPoint(Vec2(0.5,0.5));
    head->setColor(color);
    log("head position:%f %f",head->getPositionX(),head->getPositionY());
    
    //添加眼珠
    Sprite * leye = new Sprite();
    leye->initWithFile("res/circle.png");
    leye->setColor(Color3B(0,0,0));
    leye->setPosition(Vec2(0,2.5));
    leye->setScale(0.5);
    Sprite * reye = new Sprite();
    reye->initWithFile("res/circle.png");
    reye->setColor(Color3B(0,0,0));
    reye->setPosition(Vec2(3.5,2.5));
    reye->setScale(0.5);
    
    head->addChild(leye);
    head->addChild(reye);
    this->addChild(head,50);
    
    log("-------add snake--------");
    
    
    
    
    
    return true;
}
