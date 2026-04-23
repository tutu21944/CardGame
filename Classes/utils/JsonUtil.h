#ifndef JSON_UTIL_H
#define JSON_UTIL_H

#include "cocos2d.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

class JsonUtil {
public:

    // 从文件加载 JSON
    static bool loadJsonFromFile(const std::string& path, rapidjson::Document& doc) {
        std::string jsonStr = cocos2d::FileUtils::getInstance()->getStringFromFile(path);
        if (jsonStr.empty()) {
            return false;
        }

        doc.Parse(jsonStr.c_str());
        return !doc.HasParseError();
    }

    // 判断是否存在某个 key
    static bool hasMember(const rapidjson::Value& root, const char* key) {
        return root.HasMember(key) && !root[key].IsNull();
    }

    // 获取 int
    static int getInt(const rapidjson::Value& root, const char* key, int def = 0) {
        if (!hasMember(root, key) || !root[key].IsInt()) return def;
        return root[key].GetInt();
    }

    // 获取 string
    static std::string getString(const rapidjson::Value& root, const char* key, const std::string& def = "") {
        if (!hasMember(root, key) || !root[key].IsString()) return def;
        return root[key].GetString();
    }

    // 获取 float
    static float getFloat(const rapidjson::Value& root, const char* key, float def = 0.0f) {
        if (!hasMember(root, key) || !root[key].IsNumber()) return def;
        return root[key].GetFloat();
    }

    // 获取 Vec2
    static cocos2d::Vec2 getVec2(const rapidjson::Value& root, const char* key, cocos2d::Vec2 def = cocos2d::Vec2::ZERO) {
        if (!hasMember(root, key) || !root[key].IsObject()) return def;
        auto& obj = root[key];
        float x = getFloat(obj, "x");
        float y = getFloat(obj, "y");
        return cocos2d::Vec2(x, y);
    }
};

#endif#pragma once
