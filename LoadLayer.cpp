//
//  LoadLayer.cpp
//  Nibbles
//
//  Created by xujunyu on 2016/11/17.
//
//

#include "LoadLayer.hpp"
#include "iostream"
bool LoadLayer::init(){
    Size winSize = Director::getInstance()->getWinSize();
    Label * label = Label::createWithTTF("loading...", "fonts/Marker Felt.ttf", 32);
    label->setPosition(Vec2(winSize.width/2,winSize.height/2));
    this->addChild(label);
    
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
    //    std::cout<<"hello world\n";
    
    return true;
}
void LoadLayer::onScheduleOnce(float dt){
    tsm->goOpenScene();
}
