//
//  Player.cpp
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#include "Player.h"
#include "Constants.h"

// just testing some macros for education purposes
# define LEFT_ARROW EventKeyboard::KeyCode::KEY_LEFT_ARROW
///////////////////////////////////////////////////////////


void Player::initPlayer()
{
    resetDownBools();
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(0, 0);
    
    keyboardListener = createKeyboardListener();
    
}

void Player::runFadeToAction()
{
    auto fadeToAction = FadeTo::create(1.5, 30);
    this->runAction(fadeToAction);
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

void Player::update(){
    if(rightDown){
        setPositionX(getPositionX() + PLAYER_SPEED);
    }
    if(leftDown){
        setPositionX(getPositionX() - PLAYER_SPEED);
    }
    if(upDown){
        setPositionY(getPositionY() + PLAYER_SPEED);
    }
    if(downDown){
        setPositionY(getPositionY() - PLAYER_SPEED);
    }
}

EventListenerKeyboard* Player::createKeyboardListener(){
    auto eventListener = EventListenerKeyboard::create();
    
    eventListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event){
        
        switch(keyCode){
            case EventKeyboard::KeyCode::KEY_SPACE:
                this->runFadeToAction();
                break;
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                leftDown = true;
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                rightDown = true;
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                upDown = true;
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                downDown = true;
                break;
        }
    };

    eventListener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event){
        
        switch(keyCode){
            case LEFT_ARROW: // macro test
            case EventKeyboard::KeyCode::KEY_A:
                leftDown = false;
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                rightDown = false;
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                upDown = false;
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                downDown = false;
                break;
        }
    };
    
    return eventListener;
}

void Player::resetDownBools(){
    rightDown = false;
    leftDown = false;
    upDown = false;
    downDown = false;
}







