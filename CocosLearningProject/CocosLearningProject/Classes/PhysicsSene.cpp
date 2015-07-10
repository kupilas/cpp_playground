//
//  PhysicsSene.cpp
//  CocosLearningProject
//
//  Created by Matt on 05.07.15.
//
//

#include "PhysicsSene.h"

#define BITMASK_SHAPE1 1
#define BITMASK_SHAPE2 2

Scene* PhysicsSene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -200));
    
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
    edgeNode ->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    
    this->addChild(edgeNode);
    
    {
        auto sprite = Sprite::create("CloseNormal.png");
        sprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
        
        auto spriteBody = PhysicsBody::createBox( sprite->getContentSize( ), PhysicsMaterial( 0, 1, 0 ) );
        spriteBody->setCollisionBitmask(BITMASK_SHAPE1);
        spriteBody->setContactTestBitmask(true);
        
        sprite->setPhysicsBody(spriteBody);
        
        this->addChild(sprite);
    }
    
    {
        auto sprite = Sprite::create("CloseNormal.png");
        sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 200));
        
        auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));
        spriteBody->setCollisionBitmask(BITMASK_SHAPE2);
        spriteBody->setContactTestBitmask(true);
        
        sprite->setPhysicsBody(spriteBody);
        
        this->addChild(sprite);
    }
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(PhysicsSene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    CCLOG("PhysicsSene::init()");
    
    return true;
}

bool PhysicsSene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    // check if the bodies have collided
    if (( BITMASK_SHAPE1 == a->getCollisionBitmask() && BITMASK_SHAPE2 == b->getCollisionBitmask()) || (BITMASK_SHAPE2 == a->getCollisionBitmask() && BITMASK_SHAPE1 == b->getCollisionBitmask()))
    {
        CCLOG( "COLLISION HAS OCCURED" );
    }
    
    return true;
}
