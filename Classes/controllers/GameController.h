#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "cocos2d.h"
#include "../views/GameView.h"
#include "../models/GameModel.h"
#include "../managers/UndoManager.h"
#include "PlayFieldController.h"
#include "StackController.h"
#include "../configs/loaders/LevelConfigLoader.h"
#include "../services/GameModelGenerator.h"

class GameController {
private:
    GameModel* _gameModel;
    GameView* _gameView;
    UndoManager* _undoManager;
    PlayFieldController* _playFieldCtrl;
    StackController* _stackCtrl;

public:
    GameController() {
        _undoManager = new UndoManager();
        _playFieldCtrl = new PlayFieldController();
        _stackCtrl = new StackController();
    }

    ~GameController() {
        delete _undoManager;
        delete _playFieldCtrl;
        delete _stackCtrl;
        delete _gameModel;
    }

    static cocos2d::Scene* createScene() {
        auto scene = cocos2d::Scene::create();
        auto ctrl = new GameController();
        ctrl->initGame();
        scene->addChild(ctrl->_gameView);
        scene->setUserData(ctrl);
        return scene;
    }

    void initGame() {
        _gameView = GameView::create();
        auto cfg = LevelConfigLoader::loadFromJson("level.json");
        _gameModel = GameModelGenerator::generate(cfg);

        _stackCtrl->init(_gameModel, _gameView->stackView);
        _playFieldCtrl->init(_gameModel, _gameView->playFieldView, _undoManager, _stackCtrl);

        // 初始化主牌区
        for (auto& card : _gameModel->playFieldCards) {
            _gameView->playFieldView->addCardView(card);
        }

        // 初始化底牌
        if (!_gameModel->stackCards.empty()) {
            _gameView->stackView->setTopCard(_gameModel->currentTopCard);
        }

        // 按钮绑定
        _gameView->stackView->onUndoClick = [=]() { handleUndo(); };
        _gameView->stackView->onSpareClick = [=]() {
            _stackCtrl->drawSpareCard();
            _gameView->stackView->setTopCard(_gameModel->currentTopCard);
            };
    }

    void handleUndo() {
        if (!_undoManager->hasRecord()) return;
        auto act = _undoManager->popLast();

        _stackCtrl->undoReplaceCard(act.oldStackCard);
        _gameView->stackView->setTopCard(act.oldStackCard);
        _gameView->playFieldView->runUndoAnimation(act.cardId, act.fromPos);
    }
};

#endif