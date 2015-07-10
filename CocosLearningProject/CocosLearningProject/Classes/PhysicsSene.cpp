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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    
    auto edgeNode = Node::create();
    edgeNode ->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    edgeNode->setPhysicsBody( edgeBody );
    
    this->addChild( edgeNode );
    
    CCLOG("PhysicsSene::init()");
    
    return true;
}
