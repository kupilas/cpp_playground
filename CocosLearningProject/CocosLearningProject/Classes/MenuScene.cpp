//
//  MenuScene.cpp
//  CocosLearningProject
//
//  Created by Matt on 23.06.15.
//
//

#include "MenuScene.h"
#include "TestingSceneOne.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    
    auto label = Label::createWithSystemFont("my simple menu", "Arial", 20);
    label->setPosition(500, 500);
    scene->addChild(label);
    
    
    
    auto button = ui::Button::create("CloseNormal.png", "CloseSelected.png", "CloseNormal.png");
    
    button->setTitleText("Button Text");
    
    button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                Director::getInstance()->replaceScene(TestingSceneOne::createScene());
                break;
            default:
                break;
        }
    });
    button->cocos2d::Node::setPosition(300, 300);
    scene->addChild(button);
    
    return scene;
}
