//
//  MenuScene.cpp
//  CocosLearningProject
//
//  Created by Matt on 23.06.15.
//
//

#include "MenuScene.h"
#include "ui/CocosGUI.h"
#include "TestingSceneOne.h"


USING_NS_CC;


bool MenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    initHttpButton();
    initNewSceneButton();
    
    return true;
}

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    
    auto label = Label::createWithSystemFont("my simple menu", "Arial", 20);
    label->setPosition(500, 500);
    scene->addChild(label);
    
    return scene;
}

void MenuScene::makeHttpRequest(){
    auto request = new cocos2d::network::HttpRequest();
    request->setUrl("https://www.google.com");
    request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
    
    request->setResponseCallback( [&] (network::HttpClient* client, network::HttpResponse* response) {
        if (!response)
        {
            return;
        }
        // Dump the data
        std::vector<char>* buffer = response->getResponseData();
        for (unsigned int i = 0; i <buffer-> size (); i ++)
        {
            log ("% c", (* buffer) [i]);
        }
    });
    
    cocos2d::network::HttpClient::getInstance()->send(request);
    request->release();
}

void MenuScene::initNewSceneButton(){
    auto button2 = ui::Button::create("CloseNormal.png", "CloseSelected.png", "CloseNormal.png");
    
    button2->setTitleText("next scene");
    
    button2->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                Director::getInstance()->replaceScene(TestingSceneOne::createScene());
                CCLOG("btn lick");
                
                break;
            default:
                break;
        }
    });
    button2->cocos2d::Node::setPosition(600, 300);
    this->addChild(button2);
}

void MenuScene::initHttpButton(){
    auto button = ui::Button::create("CloseNormal.png", "CloseSelected.png", "CloseNormal.png");
    
    button->setTitleText("http request");
    
    button->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                //                Director::getInstance()->replaceScene(TestingSceneOne::createScene());
                CCLOG("btn lick");
                this->makeHttpRequest();
                break;
            default:
                break;
        }
    });
    button->cocos2d::Node::setPosition(300, 300);
    this->addChild(button);
}
