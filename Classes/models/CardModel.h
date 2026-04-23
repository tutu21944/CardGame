#ifndef CARD_MODEL_H
#define CARD_MODEL_H

#include "cocos2d.h"
#include "../CardDef.h"

/**
 * 单张卡牌的运行时数据模型
 */
class CardModel {
public:
    int cardId;
    CardSuitType suit;
    CardFaceType face;
    cocos2d::Vec2 originPos;
    bool isInStack;
    bool isCovered;

    CardModel()
        : cardId(-1),
        suit(CST_NONE),
        face(CFT_NONE),
        isInStack(false),
        isCovered(true) {
    }
};

#endif#pragma once
