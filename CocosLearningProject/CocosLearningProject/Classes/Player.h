//
//  Player.h
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#ifndef __CocosLearningProject__Player__
#define __CocosLearningProject__Player__

#include "cocos2d.h"

USING_NS_CC;

class Player : public cocos2d::Sprite
{
    
public:
    static Player* createWithFileName(const std::string& filename);
    void initPlayer();
    void update();
    
    /**
     *     getters and setters
     **/
    EventListenerKeyboard* getKeyboardListener(){
        return keyboardListener;
    }
    
private:
    bool rightDown, leftDown, upDown, downDown;
    EventListenerKeyboard* keyboardListener;
    
    void resetDownBools();
    void runFadeToAction();
    EventListenerKeyboard* createKeyboardListener();
    
};



#endif /* defined(__CocosLearningProject__Player__) */
