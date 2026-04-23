#ifndef PLAY_FIELD_CONTROLLER_H
#define PLAY_FIELD_CONTROLLER_H

#include "../models/GameModel.h"
#include "../views/PlayFieldView.h"
#include "../managers/UndoManager.h"
#include "StackController.h"

/**
 * 主牌区控制器，处理主牌点击、匹配逻辑
 */
class PlayFieldController {
private:
    GameModel* _gameModel;
    PlayFieldView* _view;
    UndoManager* _undoManager;
    StackController* _stackController;

    bool isMatch(CardFaceType a, CardFaceType b) {
        return abs((int)a - (int)b) == 1;
    }

public:
    void init(GameModel* model, PlayFieldView* view, UndoManager* undo, StackController* stackCtrl) {
        _gameModel = model;
        _view = view;
        _undoManager = undo;
        _stackController = stackCtrl;

        _view->onCardClick = [=](int cardId) {
            handleCardClick(cardId);
            };
    }

    void handleCardClick(int cardId) {
        CardModel* targetCard = nullptr;
        for (auto& c : _gameModel->playFieldCards) {
            if (c.cardId == cardId && !c.isCovered) {
                targetCard = &c;
                break;
            }
        }
        if (!targetCard) return;

        auto topFace = _stackController->getTopFace();
        if (!isMatch(topFace, targetCard->face)) return;

        // 记录回退操作
        UndoAction act;
        act.cardId = cardId;
        act.fromPos = targetCard->originPos;
        act.toPos = _stackController->getTopPosition();
        act.isFromPlayField = true;
        act.oldStackCard = _stackController->getCurrentTopCard();
        _undoManager->addRecord(act);

        // 执行动画和逻辑
        _view->runMoveAnimation(cardId, act.toPos, [=]() {
            _stackController->replaceTopCard(*targetCard);
            });
    }
};

#endif#pragma once
