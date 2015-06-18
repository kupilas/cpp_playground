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

bool TestingSceneOne::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setAnchorPoint(Vec2(0, 0));
    sprite->setPosition(0, 0);
    
    this->addChild(sprite, 0);
    
    return true;
}
