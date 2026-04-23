#ifndef APP_DELEGATE_H
#define APP_DELEGATE_H

#include "cocos2d.h"

class AppDelegate : public cocos2d::Application {
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual bool applicationDidFinishLaunching() override;
    virtual void applicationDidEnterBackground() override;
    virtual void applicationWillEnterForeground() override;
};

#endif