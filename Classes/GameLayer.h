#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"
#include <vector>

class UILayer;

class GameLayer: public cocos2d::Layer {
public:
    GameLayer();
    ~GameLayer();
    
    virtual bool init();
    
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    
    static cocos2d::Scene* scene();
    
    void setUILayer(UILayer *uiLayer);
    
    void shareToFacebook();
    void shareToTwitter();
    
    CREATE_FUNC(GameLayer);
private:
    cocos2d::Sprite *_back;
    
    UILayer *_uiLayer;
    
    cocos2d::Label *_lab;
    
    std::vector<std::string> _quotesVec;
    
    int _curIndex;
    int _countOfQuotesInVector;
    
    cocos2d::Vec2 _touchBeganCoords;
};

#endif // __HELLOWORLD_SCENE_H__
