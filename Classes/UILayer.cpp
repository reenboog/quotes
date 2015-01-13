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
    
    return true;
}

void UILayer::setGameLayer(GameLayer *gameLayer) {
    this->_gameLayer = gameLayer;
}