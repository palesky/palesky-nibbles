//
//  GameOverLayer.cpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#include "GameOverLayer.hpp"
bool GameOverLayer::init(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->setPosition(Vec2(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height/2));
    
    auto score = Label::createWithTTF("", "fonts/Marker Felt.ttf", 36);
    score->setPosition(Vec2(250,200));
    this->addChild(score);
    
    auto theScoreIs = Label::createWithTTF("Score:", "fonts/Marker Felt.ttf", 24);
    theScoreIs->setPosition(Vec2(50,200));
    this->addChild(theScoreIs);
    
    auto retry = Label::createWithTTF("click to retry", "fonts/Marker Felf.ttf", 24);
    retry->setPosition(50,100);
    this->addChild(retry);
    
    //要显示时，修改为true即可
    this->setVisible(false);
    
    return true;
}
