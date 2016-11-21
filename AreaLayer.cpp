//
//  AreaLayer.cpp
//  nibbles
//
//  Created by xujunyu on 2016/11/20.
//
//

#include "AreaLayer.hpp"
bool AreaLayer::init(){
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithColor(Color4B(0, 100, 0, 255), width, height);
    
    //猜测这一行和python的center是一样的，如有问题请删去，
    //或查看python-cocos2的文档并修改
    //this->setAnchorPoint(Vec2(visibleSize.width / 2,
    //                          visibleSize.height / 2));
    
    this->setIgnoreAnchorPointForPosition(false);
    this->setAnchorPoint(Vec2(0.5,0.5));
    this->setPosition(Vec2(origin.x+visibleSize.width / 2 ,
                           origin.y+visibleSize.height / 2));
    
    auto _listener = EventListenerCustom::create(JoystickEvent::EVENT_JOYSTICK, [=](EventCustom* event){
        JoystickEvent* jsevent = static_cast<JoystickEvent*>(event->getUserData());
        log("--------------got joystick event, %p,  angle=%f", jsevent, jsevent->mAnagle);
        mAnagle=jsevent->mAnagle;
        // do your business you'd like to
    });
    _eventDispatcher->addEventListenerWithFixedPriority(_listener, 1);
    schedule(CC_SCHEDULE_SELECTOR(AreaLayer::onUpdate), 1.0/60);
    
    
    snake = Snake::create();
    snake->setPosition(Vec2(width/2,
                            height/2));
    this->addChild(snake,1000);
    
    
    
   
    
    return true;
}

void AreaLayer::onUpdate(float dt){
    //可能成为性能瓶颈
//    log("angle:%f",mAnagle);
//    log("x:%f y:%f",this->getPositionX()+140*sin(mAnagle),this->getPositionY()+140*cos(mAnagle));
    this->setPosition(this->getPositionX()-140*cos(mAnagle*3.1415926/180)/60,this->getPositionY()-140*sin(mAnagle*3.1415926/180)/60);
    snake->setPosition(snake->getPositionX()+140*cos(mAnagle*3.1415926/180)/60,snake->getPositionY()+140*sin(mAnagle*3.1415926/180)/60);

    }
