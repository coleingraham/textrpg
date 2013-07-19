#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "json.h"
#include "TerminalFormatting.h"

class GameApp
{
public:
    GameApp();

    void gameLoop();
    void handleInput(std::string input);

    // commands
    void move(std::string direction);
    void quit();
    void look();

    void help();

    Json::Value currentMap;
    Json::Value character;

    bool running;
};

#endif // GAMEAPP_H
