//
//  GameScene.cpp
//  flappy
//
//  Created by Macbook on 2014. 10. 4..
//
//

#include "GameScene.h"
#include "NewScene.h"

USING_NS_CC;


Scene* GameScene::createScene()
{
    // scene as autorelease object
    auto scene = Scene::create();
    
    // layer is autorelease
    auto layer = GameScene::create();
    
    // add layer to scene
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init() {
    
    // 1. super inti
    if (!Layer::init()) {
        return false;
    }
//    skyColor = SKColor(red: 81.0/255.0, green: 192.0/255.0, blue: 201.0/255.0, alpha: 1.0)
    
    this->setColor(Color3B(255, 255, 255));
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    printf("%f, %f", visibleSize.width, visibleSize.height);
    
    // 2. add a menu item with 'X' image
    // add close button
//    auto img = new Image;
//    img->initWithImageFile("land");
//    auto groundTexture = new Texture2D;
//    groundTexture->initWithImage(img);
//
    
//    auto land = Sprite::create("land.png");
//    land->setPosition(visibleSize.width/2, visibleSize.height/2);
//    this->addChild(land, 1);
    
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2, origin.y + closeItem->getContentSize().height/2));
    
    // create menu (autorelease)
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
    
    // 3. add your codes below
    // add a label shows "Hello World"
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
    //    Rect::containsPoint(<#const cocos2d::Vec2 &point#>)
    
    // add label as child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(visibleSize.width/2, visibleSize.height/2);
    
    // add the sprite to layer
    this->addChild(sprite, 0);


    // Moving
//    ccBezierConfig bezier;
//    bezier.controlPoint_1 = Point(0, visibleSize.height / 2);
//    bezier.controlPoint_2 = Point(300, -visibleSize.height / 2);
//    bezier.endPosition = Point(200, 100);
//    auto action = MoveBy::create(3, Point(100, 0));
//    auto action = JumpBy::create(3, Point(100, 0), 50, 5);
//    auto action = JumpTo::create(3, Vec2(100, 0), 50, 5);
//    auto action = BezierBy::create(3, bezier);
//    auto action = BezierTo::create(3, bezier);
//    auto action = Place::create(Point(50,200));
    // Scaling
//    auto action = ScaleBy::create(3, 2, 2);
//    auto action = ScaleTo::create(3, 2);
    // Rotation
//    auto action = RotateBy::create(3, 270);
//    auto action = RotateTo::create(3, 270);
    // Tinting
//    auto action = TintBy::create(3, -255, 0, 0);
//    auto action = TintTo::create(3, -255, 0, 0);
    // Fade
//    auto action = FadeTo::create(3, 0.0);
//    auto action = FadeIn::create(3);
//    auto action = FadeOut::create(3);
    // Repeat
//    auto action = Repeat::create(RotateBy::create(2, 45), 5);
//    auto action = RepeatForever::create(RotateBy::create(1, 45));
    // Sequence
//    auto action = Sequence::create(RotateBy::create(2, 45), MoveBy::create(5, Point(100, -50)), NULL);
    // Skew
//    auto action = SkewBy::create(2, 70, 50);
//    auto action = SkewTo::create(2, 70, 50);
    // sprite animations
    auto action = MoveBy::create(3, Point(100, 0));
    sprite->runAction(EaseElasticInOut::create(action, 0.5));
    
//    sprite->runAction(action);
    
    // Sound
//    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Collide.wav"); //preload
//    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio/Collide.wav");
    // Repeated Sound
//    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio");
//    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio", true);
    // Volume
//    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    // Stop Sound
//    soundInt = CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("audio", true);
//    this->schedule(schedule_selector(GameScene::StopEffect), 5.0);
//    CocosDenshion::SimpleAudioEngine::getInstance()->stopEffect(soundInt);
//    CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects()
    // Music
//    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
//    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/music.mp3");
//    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/music.mp3", true); // true loops
//    this->schedule(schedule_selector(GameScene::StopEffect), 5.0);
//    this->schedule(schedule_selector(GameScene::PauseMusic), 5);
//    this->schedule(schedule_selector(GameScene::ResumeMusic), 5);
    
    // Touch Events (Single)
//    auto listener = EventListenerTouchOneByOne::create();
//    listener->setSwallowTouches(true);
//    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
//    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
//    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    // Touch Events (Multi)
//    auto listener = EventListenerTouchAllAtOnce::create();
//    listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
//    listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
//    listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    // Menu
//    auto menuItem1 = MenuItemFont::create("Play", CC_CALLBACK_1(GameScene::Play, this));
//    auto menuItem2 = MenuItemFont::create("HighScore", CC_CALLBACK_1(GameScene::HighScores, this));
//    auto menuItem3 = MenuItemFont::create("Settings", CC_CALLBACK_1(GameScene::Settings, this));
//    auto menuItem4 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameScene::ImageButton, this));
//
//    menuItem1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 4));
//    menuItem2->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 3));
//    menuItem3->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 2));
//    menuItem4->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 5) * 1));
//    
//    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, NULL);
//    menu->alignItemsVertically();
//    menu->setPosition(Point(0, 0));
//    this->addChild(menu);
    
    
    // Scene
    // in Android Change Android.mk
    // add the new file
    
//    Device::setAccelerometerEnabled(true);
//    auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(GameScene::onAcceleration, this));
//    
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}
// Menus
void GameScene::Play(cocos2d::Ref *pSender) {
    CCLOG("Play");
    
    auto scene = NewScene::createScene();
    Director::getInstance()->pushScene(scene);
}
void GameScene::HighScores(cocos2d::Ref *pSender) {
    CCLOG("Highscores");
    
    auto scene = NewScene::createScene();
    Director::getInstance()->replaceScene(scene);
}
void GameScene::Settings(cocos2d::Ref *pSender) {
    CCLOG("Settings");
}
void GameScene::ImageButton(cocos2d::Ref *pSender) {
    CCLOG("ImageButton");
}
// Touch Events
bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
    return true;
}
void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    CCLOG("onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}
void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    CCLOG("onTouchEnded x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}
void GameScene::onTouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *unused_event) {
    CCLOG("onTouchesBegan");
}
void GameScene::onTouchesMoved(const std::vector<Touch *> &touches, cocos2d::Event *unused_event) {
    CCLOG("onTouchesMoved");
}
void GameScene::onTouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event) {
    CCLOG("onTouchesEnded");
}
// Music
void GameScene::PauseMusic(float dt) {
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}
void GameScene::ResumeMusic(float dt) {
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
void GameScene::StopMusic(float dt) {
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

// Effect
void GameScene::StopEffect(float dt) {
    CocosDenshion::SimpleAudioEngine::getInstance()->stopEffect(dt);
}

// accelerometer
//void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event) {
//    CCLOG("%f", acc->z);
//}

void GameScene::menuCloseCallback(Ref *pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
