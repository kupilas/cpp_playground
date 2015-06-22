//
//  TestingSceneOne.cpp
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#include "TestingSceneOne.h"


USING_NS_CC;

Scene* TestingSceneOne::createScene()
{
    auto scene = Scene::create();
    auto layer = TestingSceneOne::create();
    scene->addChild(layer);
    
    
    return scene;
}

bool TestingSceneOne::spritesCollide(Sprite *s1, Sprite* s2){
    return s1->getBoundingBox().intersectsRect(s2->getBoundingBox());
}

void TestingSceneOne::update(float delta){
    player->update();
    
    // collision test
    if(spritesCollide(player, colidingSprite)){
        CCLOG("collision");
    }
}


bool TestingSceneOne::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    player = Player::createWithFileName("HelloWorld.png");
    player->initPlayer();
    
    // adding player as a child to the scene
    this->addChild(player, 0);
    
    colidingSprite = Sprite::create("HelloWorld.png");
    colidingSprite->setAnchorPoint(Vec2(0, 0));
    colidingSprite->setPosition(500, 500);
    this->addChild(colidingSprite);
    
    // adding keyboard listener to player
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(player->getKeyboardListener(), player);
    
    // acces to game loop
    scheduleUpdate();
    
    return true;
}
