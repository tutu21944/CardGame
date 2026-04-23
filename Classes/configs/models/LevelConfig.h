#ifndef LEVEL_CONFIG_H
#define LEVEL_CONFIG_H

#include "cocos2d.h"
#include "../../CardDef.h"

/**
 * 单张卡牌的关卡配置数据
 */
struct LevelCardConfig {
    int face;       // 牌面数值
    int suit;       // 花色
    cocos2d::Vec2 pos; // 初始位置
};

/**
 * 整个关卡的配置数据
 */
struct LevelConfig {
    std::vector<LevelCardConfig> playFieldCards; // 主牌区卡牌配置
    std::vector<LevelCardConfig> stackCards;     // 底牌堆卡牌配置
};

#endif#pragma once
