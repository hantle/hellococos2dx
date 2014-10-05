#include "NewScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* NewScene::createScene()
{
    // scene as autorelease object
    auto scene = Scene::create();
    
    // layer is autorelease
    auto layer = NewScene::create();
    
    // add layer to scene
    scene->addChild(layer);
    
    return scene;
}

// init your instance
bool NewScene::init()
{
    // 1. super inti
    if (!Layer::init()) {
        return false;
    }
    this->setColor(Color3B(255, 255, 255));
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    // Menu
    auto menuItem1 = MenuItemFont::create("GoBack", CC_CALLBACK_1(NewScene::GoBack, this));
    auto menuItem2 = MenuItemFont::create("Repalce", CC_CALLBACK_1(NewScene::Replace, this));
    
    auto menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->alignItemsVertically();
//    menu->setPosition(Point(0, 0));
    this->addChild(menu);
    
    
    return true;
}

void NewScene::GoBack(Ref *pSender) {
    Director::getInstance()->popScene();
}
void NewScene::Replace(Ref *pSender) {
    auto scene = GameScene::createScene();
//    Director::getInstance()->replaceScene(scene);
    // Transitions
    Director::getInstance()->replaceScene(TransitionFlipX::create(2, scene));
}

void NewScene::menuCloseCallback(Ref *pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void NewScene::spawnPipes() {
    return;
}
