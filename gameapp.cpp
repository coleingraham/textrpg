#include "gameapp.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>

GameApp::GameApp()
{
}

void GameApp::gameLoop()
{
    tf::clear();

    Json::Reader reader;
    std::ifstream myfile ("./game_data/maps/Cave/map.json");
    bool parsingSuccessful = reader.parse( myfile, currentMap );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse JSON file" << std::endl
                   << reader.getFormattedErrorMessages();
    }
    myfile.close();

    look();

    std::string input;
    running = true;
    while(running)
    {
        ///
        std::cout << tf::bold() << tf::textColor(tf::cyan()) << "Location: " << currentMap["area"].asString() << std::endl;

        std::cout << "Exits: ";
        const Json::Value exits = currentMap["exits"];
        for ( int i = 0; i < exits.size(); i++ )
        {
            std::cout << exits[i].asString();

            if(i < exits.size()-1)
            {
                std::cout << ", ";
            }
        }
        std::cout << tf::resetAll() << std::endl;

        std::cout << ">>> ";
        std::cin >> input;
        handleInput( input );
    }
}

void GameApp::handleInput(std::string input)
{

    if(std::strcmp(input.c_str(),"quit") == 0) { quit(); }

    else if(std::strcmp(input.c_str(),"help") == 0) { help(); }

    else if(std::strcmp(input.c_str(),"attack") == 0)
    {
        std::cout << std::endl << "\t" << "you attack something!" << std::endl << std::endl;
    }

    else if( std::strcmp(input.c_str(),"north") == 0 ) { move("north"); }
    else if( std::strcmp(input.c_str(),"n") == 0 ) { move("north"); }

    else if(std::strcmp(input.c_str(),"south") == 0 ) { move("south"); }
    else if(std::strcmp(input.c_str(),"s") == 0 ) { move("south"); }

    else if(std::strcmp(input.c_str(),"east") == 0 ) { move("east");  }
    else if(std::strcmp(input.c_str(),"e") == 0 ) { move("east");  }

    else if(std::strcmp(input.c_str(),"west") == 0 ) { move("west"); }
    else if(std::strcmp(input.c_str(),"w") == 0 ) { move("west"); }

    else if(std::strcmp(input.c_str(),"look") == 0) { look(); }

    ////
    else
    {
        std::cout << std::endl << "\tInvalid command..." << std::endl << std::endl;
    }
}

void GameApp::move(std::string direction)
{
    std::string txt = tf::formatString( currentMap["direction_descriptions"].get(direction,"There is no way " + direction + " here.").asString() );

    if(txt.c_str()[0] == '.')
    {
        Json::Reader reader;
        std::ifstream myfile (txt.c_str());
        bool parsingSuccessful = reader.parse( myfile, currentMap );
        if ( !parsingSuccessful )
        {
            // report to the user the failure and their locations in the document.
            std::cout  << "Failed to parse JSON file" << std::endl
                       << reader.getFormattedErrorMessages();
        }
        myfile.close();

        look();

    } else
    {
        std::cout << std::endl << "\t" << txt << std::endl << std::endl;
    }
}

void GameApp::quit()
{
    std::cout << "\t" << "goodbye then" << std::endl;
    running = false;
}

void GameApp::look()
{
    std::cout << std::endl << "\t" << tf::formatString( currentMap["description"].asString() ) << std::endl << std::endl;
}

void GameApp::help()
{
    Json::Value help;
    Json::Reader reader;
    std::ifstream myfile ("./game_data/system/help.json");
    bool parsingSuccessful = reader.parse( myfile, help );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse JSON file" << std::endl
                   << reader.getFormattedErrorMessages();
    }
    myfile.close();

    std::cout << std::endl << "Help" << std::endl << std::endl;
    for ( int i = 0; i < help["commands"].size(); i++ )
    {
        std::cout << "\t" << tf::formatString( help["commands"][i].asString() ) << std::endl;
    }
    std::cout << std::endl;
}
