//
//  TestingSceneOne.h
//  CocosLearningProject
//
//  Created by Matt on 18.06.15.
//
//

#ifndef __CocosLearningProject__TestingSceneOne__
#define __CocosLearningProject__TestingSceneOne__

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC; 

class TestingSceneOne : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float) override;
    CREATE_FUNC(TestingSceneOne);
};

#endif /* defined(__CocosLearningProject__TestingSceneOne__) */
