
# 🃏 CardGame 卡牌对战游戏

## 📖 项目简介
本项目是基于 Cocos2d-x 引擎开发的 2D 卡牌对战游戏，采用 **MVC 架构**，实现了卡牌管理、游戏逻辑控制、视图渲染与资源加载等核心功能。

## 🛠️ 技术栈
- **开发语言**：C++
- **游戏引擎**：Cocos2d-x v4.0
- **构建工具**：CMake + Visual Studio 2022
- **核心设计**：MVC 分层架构

## 📁 目录结构
```
CardGame/
├── Classes/               # 游戏核心代码
│   ├── controllers/       # 控制器（GameController、StackController 等）
│   ├── models/           # 数据模型（CardModel、GameModel 等）
│   ├── views/            # 视图层（CardView、GameView 等）
│   ├── utils/            # 工具类（JSON 解析等）
│   ├── configs/          # 配置文件/加载器
│   └── AppDelegate.cpp   # 游戏入口
├── Resources/             # 游戏资源（图片、配置文件等）
├── proj.win32/           # Windows 平台项目文件
├── cocos2d/              # Cocos2d-x 引擎库
└── CMakeLists.txt        # CMake 构建配置
```

## 🎮 核心功能
- 卡牌对象创建与属性管理
- 牌堆、手牌等场景视图渲染与交互
- 游戏状态控制与逻辑调度
- 配置文件解析与动态资源加载

## 🚀 编译与运行（Windows 平台）
1.  **环境准备**
    - 安装 Visual Studio 2022
    - 安装 CMake 3.16+
    - 下载 Cocos2d-x v4.0 并配置好环境

2.  **构建项目**
    ```bash
    # 生成 CMake 缓存（VS 中直接右键 CMakeLists.txt 即可）
    cmake -S . -B out/build/x64-Debug -G "Visual Studio 17 2022" -A x64
    ```

3.  **编译运行**
    - 在 VS 中打开项目，设置 `CardGame` 为启动项目
    - 点击「本地 Windows 调试器」即可运行

## 📌 项目亮点
- 采用 MVC 架构，将数据、视图、逻辑完全解耦，便于后续扩展
- 所有卡牌与游戏数据通过配置文件管理，支持快速修改与扩展
- 利用 Cocos2d-x 渲染管线实现流畅的 2D 卡牌交互效果

## 📝 后续扩展方向
- 实现玩家对战与回合制逻辑
- 添加卡牌特效与动画系统
- 接入简单的 AI 对手
- 支持存档与游戏进度管理
