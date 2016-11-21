//
//  OpenLayer.cpp
//  AirHockey
//
//  Created by xujunyu on 2016/11/17.
//
//

#include "OpenLayer.hpp"
#include "iostream"
bool OpenLayer::init(){
    //    std::cout<<"in open scene\n";
    Size winSize = Director::getInstance()->getWinSize();
    
    Label * label = Label::createWithSystemFont("nibbles(tan chi she da zuo zhan", "", 20);
    label->setPosition(Vec2(winSize.width/2,winSize.height*3/4));
    this->addChild(label);
    
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("start", "", 20), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
    menuItem->setTag(101);
    menuItem->setPosition(Vec2(winSize.width/2,winSize.height* 0.3));
    
    MenuItemLabel * menuItem_2 = MenuItemLabel::create(Label::createWithSystemFont("cancer", "", 20), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(winSize.width/2,winSize.height* 0.15));
    
    auto menu = Menu::create(menuItem,menuItem_2,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true;
}

void OpenLayer::menuCallBack(Ref *pSender){
    
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
        {
            tsm->goGameScene();
        }
            break;
        case 102:
        {
            Director::getInstance()->end();
            exit(0);
        }
            break;
            
        default:
            break;
    }
}
