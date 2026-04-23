#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "cocos2d.h"
#include "PlayFieldView.h"
#include "StackView.h"

/**
 * 游戏主视图，管理所有子视图和布局
 */
class GameView : public cocos2d::Node {
public:
    PlayFieldView* playFieldView;
    StackView* stackView;

    CREATE_FUNC(GameView);

    bool init() override {
        if (!Node::init()) return false;

        // 背景层
        auto bg = cocos2d::LayerColor::create(cocos2d::Color4B(34, 139, 34, 255));
        addChild(bg, -1);

        // 主牌区（上半部分，1080x1500）
        playFieldView = PlayFieldView::create();
        playFieldView->setPosition(0, 580);
        addChild(playFieldView);

        // 底牌区（下半部分，1080x580）
        stackView = StackView::create();
        stackView->setPosition(0, 0);
        stackView->createButtons();
        addChild(stackView);

        return true;
    }
};

#endif#pragma once
