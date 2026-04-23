#ifndef CARD_RES_CONFIG_H
#define CARD_RES_CONFIG_H

#include "../../CardDef.h"

struct CardResConfig {
    static std::string getCardBackPath() {
        return "res/card_general.png";
    }

    static std::string getCardFacePath(CardFaceType face, CardSuitType suit) {
        std::string suitPrefix;
        if (suit == CST_CLUBS || suit == CST_SPADES) {
            suitPrefix = "black";
        }
        else {
            suitPrefix = "red";
        }

        std::string faceStr;
        switch (face) {
        case CFT_ACE: faceStr = "A"; break;
        case CFT_TWO: faceStr = "2"; break;
        case CFT_THREE: faceStr = "3"; break;
        case CFT_FOUR: faceStr = "4"; break;
        case CFT_FIVE: faceStr = "5"; break;
        case CFT_SIX: faceStr = "6"; break;
        case CFT_SEVEN: faceStr = "7"; break;
        case CFT_EIGHT: faceStr = "8"; break;
        case CFT_NINE: faceStr = "9"; break;
        case CFT_TEN: faceStr = "10"; break;
        case CFT_JACK: faceStr = "J"; break;
        case CFT_QUEEN: faceStr = "Q"; break;
        case CFT_KING: faceStr = "K"; break;
        default: faceStr = "A";
        }

        return "res/big_" + suitPrefix + "_" + faceStr + ".png";
    }
};

#endif