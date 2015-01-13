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
    
    CREATE_FUNC(UILayer);
private:
    GameLayer *_gameLayer;
};


#endif /* defined(__quotes__UILayer__) */
