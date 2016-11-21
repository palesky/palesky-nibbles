//
//  SceneManager.cpp
//  AirHockey
//
//  Created by xujunyu on 2016/11/17.
//
//

#include "SceneManager.hpp"
#include "LoadLayer.hpp"
#include "GameLayer.hpp"
#include "OpenLayer.hpp"
void SceneManager::createLoadScene(){
    
    loadScene = Scene::create();
    LoadLayer * layer = LoadLayer::create();
    layer->tsm = this;
    loadScene->addChild(layer);
    
}
void SceneManager::goOpenScene(){
    
    openScene = Scene::create();
    OpenLayer * layer = OpenLayer::create();
    layer->tsm = this;
    openScene->addChild(layer);
    
    Director::getInstance()->replaceScene(openScene);
}
void SceneManager::goGameScene(){
    
    gameScene = Scene::create();
    GameLayer * layer = GameLayer::create();
    layer->tsm = this;
    gameScene->addChild(layer);
    
    Director::getInstance()->replaceScene(gameScene);
}

void SceneManager::createScene(){
    
    scene = Scene::create();
    GameLayer * layer = GameLayer::create();
    layer->tsm = this;
    scene->addChild(layer);
    
}
