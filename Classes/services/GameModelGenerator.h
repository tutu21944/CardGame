#ifndef GAME_MODEL_GENERATOR_H
#define GAME_MODEL_GENERATOR_H

#include "../models/GameModel.h"
#include "../configs/models/LevelConfig.h"

/**
 * 游戏模型生成服务，将静态配置转换为运行时数据
 */
class GameModelGenerator {
public:
    static GameModel* generate(const LevelConfig& cfg) {
        auto model = new GameModel();

        // 生成主牌区卡牌
        for (auto& c : cfg.playFieldCards) {
            CardModel m;
            m.cardId = rand();
            m.face = (CardFaceType)c.face;
            m.suit = (CardSuitType)c.suit;
            m.originPos = c.pos;
            m.isCovered = true;
            model->playFieldCards.push_back(m);
        }

        // 生成底牌堆卡牌
        for (auto& c : cfg.stackCards) {
            CardModel m;
            m.cardId = rand();
            m.face = (CardFaceType)c.face;
            m.suit = (CardSuitType)c.suit;
            m.isInStack = true;
            model->stackCards.push_back(m);
        }

        // 生成备用牌堆卡牌
        for (int i = 0; i < 20; i++) {
            CardModel m;
            m.cardId = rand();
            m.face = (CardFaceType)(rand() % CFT_NUM_CARD_FACE_TYPES);
            m.suit = (CardSuitType)(rand() % CST_NUM_CARD_SUIT_TYPES);
            model->spareCards.push_back(m);
        }

        if (!model->stackCards.empty()) {
            model->currentTopCard = model->stackCards.back();
        }

        return model;
    }
};

#endif#pragma once
