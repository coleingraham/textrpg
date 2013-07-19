#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "json.h"
#include "TerminalFormatting.h"
#include "gameapp.h"

int main()
{
    GameApp game;

    game.gameLoop();

    return 0;
}

