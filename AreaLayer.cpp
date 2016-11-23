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
    
    //设置背景板颜色
    this->initWithColor(Color4B(0, 100, 0, 255), width, height);
    
    //设置中心点到屏幕中央，那么每次初始化时，背景板都会居中显示
    this->setIgnoreAnchorPointForPosition(false);
    this->setAnchorPoint(Vec2(0.5,0.5));
    this->setPosition(Vec2(origin.x+visibleSize.width / 2 ,
                           origin.y+visibleSize.height / 2));
    
    //未使用图片初始化，不知道会不会有问题
    this->batch = SpriteBatchNode::create("");
    
    
    
    //设置joystick摇杆监听器
    auto _listener = EventListenerCustom::create(JoystickEvent::EVENT_JOYSTICK, [=](EventCustom* event){
        JoystickEvent* jsevent = static_cast<JoystickEvent*>(event->getUserData());
        log("--------------got joystick event, %p,  angle=%f", jsevent, jsevent->mAnagle);
        mAnagle=jsevent->mAnagle;
        // do your business you'd like to
    });
    _eventDispatcher->addEventListenerWithFixedPriority(_listener, 1);
    
    schedule(CC_SCHEDULE_SELECTOR(AreaLayer::onUpdate), 1.0/60);
    
    //添加一条蛇
    snake = Snake::create();
    snake->setPosition(Vec2(width/2,
                            height/2));
    this->addChild(snake,1000);
    
//    //添加一个点
//    Dot * d1 = Dot::create();
//    d1->setPosition(Vec2(width/2,
//                         height/2));
//    d1->setPositionZ(10000);
//    
    
    
   
    
    return true;
}

SpriteBatchNode * AreaLayer::getBatchNode(){
    return this->batch;
}

void AreaLayer::onUpdate(float dt){
    //可能成为性能瓶颈
//    log("angle:%f",mAnagle);
//    log("x:%f y:%f",this->getPositionX()+140*sin(mAnagle),this->getPositionY()+140*cos(mAnagle));
//    this->setPosition(this->getPositionX()-140*cos(mAnagle*3.1415926/180)/60,this->getPositionY()-140*sin(mAnagle*3.1415926/180)/60);

    }
