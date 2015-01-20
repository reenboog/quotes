//
//  UILayer.h
//  quotes
//
//  Created by Alex Gievsky on 13.01.15.
//
//

#ifndef __quotes__UILayer__
#define __quotes__UILayer__

#include "cocos2d.h"

class GameLayer;

class UILayer: public cocos2d::Layer {
public:
    UILayer();
    ~UILayer();

    virtual bool init();
    
    void setGameLayer(GameLayer *gameLayer);
    
    void shareToVk();
    
    CREATE_FUNC(UILayer);
private:
    GameLayer *_gameLayer;
    
    cocos2d::MenuItemImage *_vk_btn;
    
    cocos2d::Menu *_shareMenu;
};


#endif /* defined(__quotes__UILayer__) */
