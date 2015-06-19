//
//  Player.cpp
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#include "Player.h"

void Player::initPlayer()
{
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(0, 0);
}

Player* Player::createWithFileName(const std::string& filename) {
    auto sprite = new Player;
    if(sprite && sprite->initWithFile(filename)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

EventListenerKeyboard* Player::createKeyboardListener(){
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
    
    return eventListener;
}







