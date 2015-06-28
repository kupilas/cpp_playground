//
//  MenuScene.h
//  CocosLearningProject
//
//  Created by Matt on 23.06.15.
//
//

#ifndef __CocosLearningProject__MenuScene__
#define __CocosLearningProject__MenuScene__

#include "cocos2d.h"
#include "network/HttpClient.h"

class MenuScene : public cocos2d::Layer{
private:
    void onHttpRequestCompleted();
    void makeHttpRequest();
    void initHttpButton();
    void initNewSceneButton();
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
};



#endif /* defined(__CocosLearningProject__MenuScene__) */
