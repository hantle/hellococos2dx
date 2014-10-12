//
//  GameScene.h
//  flappy
//
//  Created by Macbook on 2014. 10. 4..
//
//

#ifndef __flappy__GameScene__
#define __flappy__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void spawnPipes();
    
    // Menus
    void Play(cocos2d::Ref *pSender);
    void HighScores(cocos2d::Ref *pSender);
    void Settings(cocos2d::Ref *pSender);
    void ImageButton(cocos2d::Ref *pSender);
    // Effects & Music
    void StopEffect(float dt);
    void StopMusic(float dt);
    void ResumeMusic(float dt);
    void PauseMusic(float dt);
    unsigned int soundInt;
    
    // Touches
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    // Multi Touches
    void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event);
    void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event);
    void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event);
    
//    void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};
#endif /* defined(__flappy__GameScene__) */
