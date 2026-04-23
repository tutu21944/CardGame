#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <vector>
#include "CardModel.h"

/**
 * 游戏全局数据模型
 */
class GameModel {
public:
    std::vector<CardModel> playFieldCards; // 主牌区卡牌
    std::vector<CardModel> stackCards;      // 底牌堆卡牌
    std::vector<CardModel> spareCards;     // 备用牌堆卡牌
    CardModel currentTopCard;              // 当前顶部底牌
};

#endif#pragma once
