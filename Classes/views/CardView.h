#ifndef CARD_VIEW_H
#define CARD_VIEW_H

#include "cocos2d.h"

/**
 * 单张卡牌的视图组件，仅负责显示和接收点击事件
 */
class CardView : public cocos2d::Sprite {
public:
    int cardId;
    std::function<void(int)> onCardClick;

    static CardView* create(int cardId, const std::string& res) {
        auto ref = new CardView();
        if (ref->init(cardId, res)) {
            ref->autorelease();
            return ref;
        }
        delete ref;
        return nullptr;
    }

    bool init(int cardId, const std::string& res) {
        if (!Sprite::initWithFile(res)) return false;
        this->cardId = cardId;

        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = [=](cocos2d::Touch* t, cocos2d::Event* e) {
            if (getBoundingBox().containsPoint(t->getLocation())) {
                if (onCardClick) onCardClick(cardId);
                return true;
            }
            return false;
            };
        getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
        return true;
    }
};

#endif#pragma once
