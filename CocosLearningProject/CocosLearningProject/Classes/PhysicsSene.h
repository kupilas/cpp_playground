//
//  PhysicsSene.h
//  CocosLearningProject
//
//  Created by Matt on 05.07.15.
//
//

#ifndef __CocosLearningProject__PhysicsSene__
#define __CocosLearningProject__PhysicsSene__

USING_NS_CC;


#include "cocos2d.h"

class PhysicsSene : public cocos2d::Layer{
    
private:
    // bla
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(PhysicsSene);
    
};

#endif /* defined(__CocosLearningProject__PhysicsSene__) */
