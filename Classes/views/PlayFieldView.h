#ifndef PLAY_FIELD_VIEW_H
#define PLAY_FIELD_VIEW_H

#include "cocos2d.h"
#include "CardView.h"
#include "../configs/models/CardResConfig.h"
#include "../models/CardModel.h"

class PlayFieldView : public cocos2d::Node {
public:
    std::vector<CardView*> cardViews;
    std::function<void(int)> onCardClick;

    CREATE_FUNC(PlayFieldView);

    void addCardView(CardModel& cardModel) {
        std::string resPath;
        if (cardModel.isCovered) {
            resPath = CardResConfig::getCardBackPath();
        }
        else {
            resPath = CardResConfig::getCardFacePath(cardModel.face, cardModel.suit);
        }

        auto card = CardView::create(cardModel.cardId, resPath);
        card->setPosition(cardModel.originPos);
        addChild(card);
        cardViews.push_back(card);

        card->onCardClick = [=](int id) {
            if (onCardClick) onCardClick(id);
            };
    }

    CardView* findCardViewById(int cardId) {
        for (auto c : cardViews) {
            if (c->cardId == cardId) return c;
        }
        return nullptr;
    }

    void runMoveAnimation(int cardId, const cocos2d::Vec2& to, std::function<void()> callback) {
        auto card = findCardViewById(cardId);
        if (!card) return;
        auto move = cocos2d::MoveTo::create(0.2f, to);
        auto call = cocos2d::CallFunc::create(callback);
        card->runAction(cocos2d::Sequence::create(move, call, nullptr));
    }

    void runUndoAnimation(int cardId, const cocos2d::Vec2& to) {
        auto card = findCardViewById(cardId);
        if (!card) return;
        card->runAction(cocos2d::MoveTo::create(0.2f, to));
    }

    void updateCardSprite(int cardId, bool isCovered, CardFaceType face, CardSuitType suit) {
        auto card = findCardViewById(cardId);
        if (!card) return;

        std::string resPath;
        if (isCovered) {
            resPath = CardResConfig::getCardBackPath();
        }
        else {
            resPath = CardResConfig::getCardFacePath(face, suit);
        }
        card->setTexture(resPath);
    }
};

#endif