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

bool TestingSceneOne::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto sprite = Player::createWithFileName("HelloWorld.png");
//    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setAnchorPoint(Vec2(0, 0));
    sprite->setPosition(0, 0);
    
    this->addChild(sprite, 0);
    
    auto eventListener = EventListenerKeyboard::create();
    
    
    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event){
        
        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch(keyCode){
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                event->getCurrentTarget()->setPosition(--loc.x,loc.y);
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                event->getCurrentTarget()->setPosition(++loc.x,loc.y);
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                event->getCurrentTarget()->setPosition(loc.x,++loc.y);
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                event->getCurrentTarget()->setPosition(loc.x,--loc.y);
                break;
        }
    };
    
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);
    
    return true;
}
