#ifndef STACK_CONTROLLER_H
#define STACK_CONTROLLER_H

#include "../models/GameModel.h"
#include "../views/StackView.h"
#include "../managers/UndoManager.h"

/**
 * 底牌堆控制器，处理底牌替换、抽备用牌逻辑
 */
class StackController {
private:
    GameModel* _gameModel;
    StackView* _stackView;

public:
    void init(GameModel* model, StackView* view) {
        _gameModel = model;
        _stackView = view;
    }

    CardFaceType getTopFace() const {
        return _gameModel->currentTopCard.face;
    }

    cocos2d::Vec2 getTopPosition() const {
        return _stackView->getTopPosition();
    }

    void replaceTopCard(const CardModel& newCard) {
        _gameModel->stackCards.push_back(newCard);
        _gameModel->currentTopCard = newCard;
    }

    void undoReplaceCard(const CardModel& oldCard) {
        _gameModel->stackCards.pop_back();
        _gameModel->currentTopCard = oldCard;
    }

    CardModel getCurrentTopCard() const {
        return _gameModel->currentTopCard;
    }

    void drawSpareCard() {
        if (_gameModel->spareCards.empty()) return;
        auto newCard = _gameModel->spareCards.back();
        _gameModel->spareCards.pop_back();
        replaceTopCard(newCard);
    }
};

#endif#pragma once
