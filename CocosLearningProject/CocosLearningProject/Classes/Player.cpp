//
//  Player.cpp
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#include "Player.h"



Player* Player::createWithFileName(const std::string& filename) {
    auto sprite = new Player;
    if(sprite && sprite->initWithFile(filename)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


// initPlayerWithFile


//
//Sprite* Sprite::create(const std::string& filename)
//{
//    Sprite *sprite = new (std::nothrow) Sprite();
//    if (sprite && sprite->initWithFile(filename))
//    {
//        sprite->autorelease();
//        return sprite;
//    }
//    CC_SAFE_DELETE(sprite);
//    return nullptr;
//}
