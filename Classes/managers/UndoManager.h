#ifndef UNDO_MANAGER_H
#define UNDO_MANAGER_H

#include "../models/UndoModel.h"

/**
 * 回退操作管理器，处理撤销/重做逻辑
 */
class UndoManager {
private:
    UndoModel* _undoModel;

public:
    UndoManager() {
        _undoModel = new UndoModel();
    }

    ~UndoManager() {
        delete _undoModel;
    }

    void addRecord(const UndoAction& action) {
        _undoModel->actionList.push_back(action);
    }

    UndoAction popLast() {
        if (_undoModel->actionList.empty()) return UndoAction();
        auto act = _undoModel->actionList.back();
        _undoModel->actionList.pop_back();
        return act;
    }

    bool hasRecord() const {
        return !_undoModel->actionList.empty();
    }
};

#endif#pragma once
