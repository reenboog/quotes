
#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "UILayer.h"
#include "Localized.h"



#define zBack 0

using namespace cocos2d;

GameLayer::~GameLayer() {
    
}

GameLayer::GameLayer(): Layer() {
    this->_back = nullptr;
    this->_uiLayer = nullptr;
}

Scene* GameLayer::scene() {
    Scene *scene = Scene::create();

    GameLayer *gameLayer = GameLayer::create();
    UILayer *uiLayer = UILayer::create();
    
    uiLayer->setGameLayer(gameLayer);
    gameLayer->setUILayer(uiLayer);

    // add layer as a child to scene
    scene->addChild(gameLayer);
    scene->addChild(uiLayer);

    // return the scene
    return scene;
}

bool GameLayer::init() {
    if(!Layer::init()) {
        return false;
    }
    
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(GameLayer::onTouchCancelled, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // back
    {
        _back = Sprite::create("back.png");
        _back->setPosition({static_cast<float>(visibleSize.width / 2.0), static_cast<float>(visibleSize.height / 2.0)});
        
        Size backSize = _back->getContentSize();
        
        _back->setScale(visibleSize.width / backSize.width, visibleSize.height / backSize.height);
        
        this->addChild(_back, zBack);
        
    }
    
    //
    
    _quotesVec = Localized::getVectorWithQuotes();
    
    _countOfQuotesInVector = _quotesVec.size();
    
    _curIndex = 0; // нет ничего более бостоянного, чем временное решение
    
    
    _lab = Label::createWithBMFont("font.fnt", _quotesVec[_curIndex]);
    _lab->setPosition(visibleSize.width/2, visibleSize.height/2);
    this->addChild(_lab);
    
    return true;
}

void GameLayer::setUILayer(UILayer *uiLayer) {
    this->_uiLayer = uiLayer;
}

bool GameLayer::onTouchBegan(Touch *touch, Event *event)
{
    _touchBeganCoords = touch->getLocation();
   
    return true;
}

void GameLayer::onTouchMoved(Touch *touch, Event *event)
{
    //CCLOG("move");
}

void GameLayer::onTouchEnded(Touch *touch, Event *event)
{
    Vec2 touchEnd = touch->getLocation();
    
    int difference = touchEnd.x - _touchBeganCoords.x;
    
    if(difference >= 0)    {_curIndex--;}
    else                {_curIndex++;}
    
    if(_curIndex > _countOfQuotesInVector - 1)  {_curIndex = 0;}
    else if (_curIndex < 0)                     {_curIndex = _countOfQuotesInVector - 1;}
    
    _lab->setString(_quotesVec[_curIndex]);
    
    //CCLOG("End!");
}

void GameLayer::onTouchCancelled(Touch *touch, Event *event)
{
    //CCLOG("cancel!");
}
