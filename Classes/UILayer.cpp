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
    
    _vk_btn = MenuItemImage::create("vk_btn.png", "vk_btn_pressed.png", CC_CALLBACK_0(UILayer::shareToVk, this));
    _vk_btn->setPosition(visibleSize.width * 0.5, visibleSize.height * 0.1);
    _shareMenu->cocos2d::Node::addChild(_vk_btn);
    
    
    return true;
}

void UILayer::setGameLayer(GameLayer *gameLayer) {
    this->_gameLayer = gameLayer;
}

void UILayer::shareToVk()
{
    _gameLayer->shareToVkontakte();
}
