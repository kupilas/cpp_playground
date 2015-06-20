//
//  TestingSceneOne.cpp
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#include "TestingSceneOne.h"
#include "Player.h"

USING_NS_CC;

Scene* TestingSceneOne::createScene()
{
    auto scene = Scene::create();
    auto layer = TestingSceneOne::create();
    scene->addChild(layer);
    
    
    return scene;
}

void TestingSceneOne::update(float delta){
    CCLOG("update test");
}

bool TestingSceneOne::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto player = Player::createWithFileName("HelloWorld.png");
    player->initPlayer();
    
    // adding player as a child to the scene
    this->addChild(player, 0);
    
    // adding keyboard listener to player
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(player->getKeyboardListener(), player);
    
    // acces to game loop
    scheduleUpdate();
    
    return true;
}
