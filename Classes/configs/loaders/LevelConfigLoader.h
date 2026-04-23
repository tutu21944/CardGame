#ifndef LEVEL_CONFIG_LOADER_H
#define LEVEL_CONFIG_LOADER_H

#include "cocos2d.h"
#include "../models/LevelConfig.h"
#include "json/document.h"

/**
 * 关卡配置加载器，负责从JSON文件解析关卡数据
 */
class LevelConfigLoader {
public:
    static LevelConfig loadFromJson(const std::string& path) {
        LevelConfig cfg;

        auto data = cocos2d::FileUtils::getInstance()->getDataFromFile(path);
        std::string jsonStr((const char*)data.getBytes(), data.getSize());
        rapidjson::Document doc;
        doc.Parse(jsonStr.c_str());

        if (doc.HasMember("Playfield")) {
            auto& playfield = doc["Playfield"];
            for (auto& v : playfield.GetArray()) {
                LevelCardConfig c;
                c.face = v["CardFace"].GetInt();
                c.suit = v["CardSuit"].GetInt();
                c.pos.x = v["Position"]["x"].GetInt();
                c.pos.y = v["Position"]["y"].GetInt();
                cfg.playFieldCards.push_back(c);
            }
        }

        if (doc.HasMember("Stack")) {
            auto& stack = doc["Stack"];
            for (auto& v : stack.GetArray()) {
                LevelCardConfig c;
                c.face = v["CardFace"].GetInt();
                c.suit = v["CardSuit"].GetInt();
                cfg.stackCards.push_back(c);
            }
        }

        return cfg;
    }
};

#endif#pragma once
