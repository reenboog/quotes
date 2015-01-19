//
//  UILayer.cpp
//  quotes
//
//  Created by Alex Gievsky on 13.01.15.
//
//

#include "UILayer.h"
#include "GameLayer.h"

using namespace cocos2d;

UILayer::~UILayer() {
    
}

UILayer::UILayer(): Layer() {
    this->_gameLayer = nullptr;
}

bool UILayer::init() {
    if(!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    _shareMenu = Menu::create();
    _shareMenu->setPosition(0,0);
    this->addChild(_shareMenu);
    
    _fb_btn = MenuItemImage::create("fb_btn.png", "fb_btn_pressed.png", CC_CALLBACK_0(UILayer::shareToFb, this));
    _fb_btn->setPosition(visibleSize.width * 0.35, visibleSize.height * 0.1);
    _shareMenu->cocos2d::Node::addChild(_fb_btn);
    
    _tw_btn = MenuItemImage::create("tw_btn.png", "tw_btn_pressed.png", CC_CALLBACK_0(UILayer::shareToTw, this));
    _tw_btn->setPosition(visibleSize.width * 0.65, visibleSize.height * 0.1);
    _shareMenu->cocos2d::Node::addChild(_tw_btn);
    
    return true;
}

void UILayer::setGameLayer(GameLayer *gameLayer) {
    this->_gameLayer = gameLayer;
}

void UILayer::shareToFb()
{
    _gameLayer->shareToFacebook();
}

void UILayer::shareToTw()
{
    _gameLayer->shareToTwitter();
}
