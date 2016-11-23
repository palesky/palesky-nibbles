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
//    this->setPosition(Vec2(origin.x + visibleSize.width/2,
//                           origin.y + visibleSize.height/2));
//    this->setPosition(Vec2(25,15));
    
    isDead = false ;
    angle = 180 ;
    angleDest = angle ;
    color = Color3B(123,132,123);
    speed = 150;
    length = 5 ;
    score = 0 ;
    
    //添加头部
    head= new Sprite();
    head->initWithFile("res/circle.png");
    head->setScale(2);
    head->setAnchorPoint(Vec2(0.5,0.5));
    head->setColor(color);
    log("head position:%f %f",head->getPositionX(),head->getPositionY());
    this->addChild(head,50);
    //添加眼珠
    Sprite * leye = new Sprite();
    leye->initWithFile("res/circle.png");
    leye->setColor(Color3B(50,50,50));
    leye->setPosition(Vec2(4.5,0));
    leye->setScale(0.5);
    Sprite * reye = new Sprite();
    reye->initWithFile("res/circle.png");
    reye->setColor(Color3B(50,50,50));
    reye->setPosition(Vec2(4.5,7));
    reye->setScale(0.5);
    
    head->addChild(leye);
    head->addChild(reye);
    
    //添加身体
    for(int i = 0; i < length;i++){
        addBody();
    }
    
    //设置joystick摇杆监听器
    auto _listener = EventListenerCustom::create(JoystickEvent::EVENT_JOYSTICK, [=](EventCustom* event){
        JoystickEvent* jsevent = static_cast<JoystickEvent*>(event->getUserData());
        log("--------------got joystick event, %p,  angle=%f", jsevent, jsevent->mAnagle);
        angleDest=jsevent->mAnagle;
    });
    _eventDispatcher->addEventListenerWithFixedPriority(_listener, 1);
    
    schedule(CC_SCHEDULE_SELECTOR(Snake::onUpdate));
    
    log("-------add snake--------position %f %f",this->getPositionX(),this->getPositionY());

    return true;
}

bool Snake::addBody(){
    Sprite * d = Sprite::create("res/circle.png");
    d->setScale(1.5);
    addChild(d);
    body.pushBack(d);
}

void Snake::onUpdate(float dt){
    //获得头部旋转角度
    angle = fmodf(angle + 360, 360 );
    angleDest = fmodf(angleDest + 360, 360 );
    log("pre angle:%f \n des angle:%f",angle,angleDest);
    if(abs(angle-angleDest)<2){
        angle=angleDest;
    }else{
        if((angle - angleDest > 0 && angle -angleDest <180)|| (angle - angleDest < -180)){
            angle -= rotationSpeed * dt;
        }else{
            angle += rotationSpeed * dt;
        }
    }
    //设置头部旋转角度
    head->setRotation(-angle);
    float dx = speed*cos(angle*3.1415926/180)/60;
    float dy = speed*sin(angle*3.1415926/180)/60;
    float x = head->getPositionX()+speed*cos(angle*3.1415926/180)/60;
    float y = head->getPositionY()+speed*sin(angle*3.1415926/180)/60;
    
    head->setPosition(Vec2(x,y));
    Vec2 parentVec2 = this->getParent()->getPosition();
    log("snk  (%f,%f)",x,y);
    log("area (%f,%f)",parentVec2.x,parentVec2.y);
    this->getParent()->setPosition(Vec2(parentVec2.x-dx,parentVec2.y-dy));
    
    path[size_path][0] = x;
    path[size_path][1] = y;
    size_path++;
    
    
    int lag = int(1100.0 / speed);
    for (int i =0 ;i<length ; i++){
        int idx = ( i + 1 ) * lag + 1;
        idx = MIN(idx, size_path);
        Vec2 pos = Vec2(path[size_path-idx][0],
                        path[size_path-idx][1]);
        body.at(i)->setPosition(pos);
        if(body.at(i)->getPositionX() == 0)
            log("self.body[i].position %f",body.at(i)->getPositionX());
    }
    
    //删去老路径
    int m_l = MAX(length * lag * 2, 60);
    if(size_path > m_l){
        //对于下面这一句：最好用一个环链实现（但是不是说最优的方案是使用环链，因为还需要考虑别的因素）
        int pathsize = int( size_path - m_l * 2 ) - 1;
        //将m_l*2开始的元素复制到新数组中
        float newPath[100][2];
        for(int i = 0;i <= size_path-m_l * 2;i++){
            path[i][0]=path[i+size_path][0];
            path[i][1]=path[i+size_path][1];
        }
        size_path=size_path-m_l;
    }

    
//     snake->setPosition(snake->getPositionX()+140*cos(mAnagle*3.1415926/180)/60,snake->getPositionY()+140*sin(mAnagle*3.1415926/180)/60);
}
