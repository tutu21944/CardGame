#ifndef UNDO_MODEL_H
#define UNDO_MODEL_H

#include "cocos2d.h"
#include "CardModel.h"

/**
 * 单条回退操作数据
 */
struct UndoAction {
    int cardId = 0;
    cocos2d::Vec2 fromPos;
    cocos2d::Vec2 toPos;
    bool isFromPlayField = false;
    CardModel oldStackCard;
};

/**
 * 回退操作列表模型
 */
class UndoModel {
public:
    std::vector<UndoAction> actionList;
};

#endif#pragma once
