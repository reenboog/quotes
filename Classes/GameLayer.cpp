
#include "GameLayer.h"
#include "SimpleAudioEngine.h"
#include "UILayer.h"
#include "Localized.h"
#include "Constants.h"

#include "Quotes.h"


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
    
    _visibleSize = Director::getInstance()->getVisibleSize();
    
    GameLayer::initBackground();
    
    
    Quotes::load();
    
    GameLayer::initLabel();
    
    return true;
}

void GameLayer::initBackground(){
    _back = Sprite::create("back.png");
    _back->setPosition({static_cast<float>(_visibleSize.width / 2.0), static_cast<float>(_visibleSize.height / 2.0)});
    
    Size backSize = _back->getContentSize();
    
    _back->setScale(_visibleSize.width / backSize.width, _visibleSize.height / backSize.height);
    
    this->addChild(_back, zBack);
}

void GameLayer::initLabel(){
    _quoteLabel = Label::createWithBMFont("font.fnt", Quotes::getCurrent());
    _quoteLabel->setPosition(_visibleSize.width/2, _visibleSize.height/2);
    _quoteLabel->setMaxLineWidth(kQuoteLineWidth);
    _quoteLabel->setAlignment(TextHAlignment::CENTER);
    this->addChild(_quoteLabel);
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
    _quoteLabel->setPosition(_visibleSize.width/2 + (touch->getLocation().x - _touchBeganCoords.x), _quoteLabel->getPosition().y);
}

void GameLayer::onTouchEnded(Touch *touch, Event *event)
{
    Vec2 touchEnd = touch->getLocation();
    
    int difference = touchEnd.x - _touchBeganCoords.x;
    
    _quoteLabel->setOpacity(0);
    
    if(difference >= 0){
        _quoteLabel->setString(Quotes::getPrev());
    }else{
        _quoteLabel->setString(Quotes::getNext());
    }
    
    _quoteLabel->setPosition(_visibleSize.width/2, _visibleSize.height/2);
    
    auto fadeIn = FadeIn::create(1.0f);
    _quoteLabel->runAction(fadeIn);
}

void GameLayer::onTouchCancelled(Touch *touch, Event *event)
{
    CCLOG("cancel!");
}

void GameLayer::shareToVkontakte()
{
    printf("Vkontakte\n");
}
