#ifndef STACK_VIEW_H
#define STACK_VIEW_H

#include "cocos2d.h"
#include "CardView.h"
#include "../configs/models/CardResConfig.h"
#include "../models/CardModel.h"

class StackView : public cocos2d::Node {
public:
    CardView* topCardView;
    std::function<void()> onUndoClick;
    std::function<void()> onSpareClick;

    CREATE_FUNC(StackView);

    void setTopCard(CardModel& cardModel) {
        if (topCardView) {
            topCardView->removeFromParent();
        }

        std::string resPath = CardResConfig::getCardFacePath(cardModel.face, cardModel.suit);
        topCardView = CardView::create(cardModel.cardId, resPath);
        topCardView->setPosition(getTopPosition());
        addChild(topCardView);
    }

    cocos2d::Vec2 getTopPosition() const {
        return cocos2d::Vec2(540, 100);
    }

    void createButtons() {
        auto undoBtn = cocos2d::MenuItemLabel::create(
            cocos2d::Label::createWithSystemFont("UNDO", "Arial", 40),
            [=](...) { if (onUndoClick) onUndoClick(); });
        undoBtn->setPosition(900, 100);

        auto spareBtn = cocos2d::MenuItemLabel::create(
            cocos2d::Label::createWithSystemFont("SPARE", "Arial", 40),
            [=](...) { if (onSpareClick) onSpareClick(); });
        spareBtn->setPosition(100, 100);

        auto menu = cocos2d::Menu::create(undoBtn, spareBtn, nullptr);
        menu->setPosition(0, 0);
        addChild(menu);
    }
};

#endif