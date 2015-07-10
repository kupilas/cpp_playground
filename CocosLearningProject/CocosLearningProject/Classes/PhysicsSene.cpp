//
//  PhysicsSene.cpp
//  CocosLearningProject
//
//  Created by Matt on 05.07.15.
//
//

#include "PhysicsSene.h"

Scene* PhysicsSene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    auto layer = PhysicsSene::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    
    return scene;
}


bool PhysicsSene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCLOG("PhysicsSene::init()");
    
    return true;
}
