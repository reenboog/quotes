#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

class UILayer;

class GameLayer: public cocos2d::Layer {
public:
    GameLayer();
    ~GameLayer();
    
    virtual bool init();
    
    static cocos2d::Scene* scene();
    
    void setUILayer(UILayer *uiLayer);
    
    CREATE_FUNC(GameLayer);
private:
    cocos2d::Sprite *_back;
    
    UILayer *_uiLayer;
};

#endif // __HELLOWORLD_SCENE_H__
