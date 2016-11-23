//
//  GameLayer.cpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#include "GameLayer.hpp"
bool GameLayer::init(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    //在左上角放置信息面板
//    auto infoList = Layer::create();
    auto infoList = LayerColor::create(Color4B(255, 100, 100, 128), visibleSize.width*infoList_width, visibleSize.height*infoList_height);
    infoList->setIgnoreAnchorPointForPosition(false);
    infoList->setAnchorPoint(Vec2(0,1));
    infoList->setPosition(Vec2(origin.x ,
                               origin.y + visibleSize.height ));
    this->addChild(infoList,9999);
    
    //在信息面板中加入分数
    auto score = Label::createWithTTF("分数:0", "fonts/Marker Felt.ttf", 12);
    score->setAnchorPoint(Vec2(0,1));
    score->setPosition(Vec2(0 ,
                            visibleSize.height*infoList_height ));
    infoList->addChild(score);
    score->setString("分数:100");
    
    
    
    //在右上角放置排行榜
    auto rankingList = LayerColor::create(Color4B(255, 100, 100, 128), visibleSize.width*rankingList_width, visibleSize.height*rankingList_height);
    rankingList->ignoreAnchorPointForPosition(false);
    rankingList->setAnchorPoint(Vec2(1,1));
    rankingList->setPosition(Vec2(origin.x + visibleSize.width,
                          origin.y + visibleSize.height));
    this->addChild(rankingList,9999);
    
//    //放上gameover
//    auto gameover = GameOverLayer::create();
//    gameover->setPosition(Vec2(origin.x + visibleSize.width/2,
//                               origin.y + visibleSize.height/2));
//    gameover->setVisible(true);
//    this->setColor(Color3B(100,100,100));
//    this->addChild(gameover,100);
    
    
    
//    在屏幕中放上蛇运动的区域
    auto areaLayer = AreaLayer::create();
    this->addChild(areaLayer,0);
    
    
    //放上触控球
    auto joystick = Joystick::create();
    this->addChild(joystick, 9999);
    
//    auto _listener = EventListenerCustom::create(JoystickEvent::EVENT_JOYSTICK, [=](EventCustom* event){
//        JoystickEvent* jsevent = static_cast<JoystickEvent*>(event->getUserData());
//        log("--------------got joystick event, %p,  angle=%f", jsevent, jsevent->mAnagle);
//        
//        // do your business you'd like to
//    });

    
    
    
    

    return true;
}
void GameLayer::menuCallBack(Ref * pSender){
    
}
