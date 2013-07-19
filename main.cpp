#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "json.h"
#include "TerminalFormatting.h"

int main()
{
    tf::clear();

    std::cout << tf::backgroundColor(tf::white()) << tf::bold() << tf::textColor(tf::red()) << "bold red" << tf::resetBackgroundColor() << " text" << tf::resetAll() << std::endl;

    Json::Value root;
    Json::Reader reader;
    std::ifstream myfile ("map.txt");
    bool parsingSuccessful = reader.parse( myfile, root );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse configuration\n"
                   << reader.getFormattedErrorMessages();
    }

    std::cout << std::endl << "\t" << tf::formatString( root["description"].asString() ) << std::endl << std::endl;

    std::string input;
    while(true)
    {
        ///
        std::cout << tf::bold() << tf::textColor(tf::cyan()) << "Location: " << root["area"].asString() << std::endl;

        std::cout << "Exits: ";
        const Json::Value exits = root["exits"];
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
        ///

        if(std::strcmp(input.c_str(),"quit") == 0)
        {
            std::cout << "\t" << "goodbye then" << std::endl;
            break;
        }

        else if(std::strcmp(input.c_str(),"attack") == 0)
        {
            std::cout << std::endl << "\t" << "you attack something!" << std::endl << std::endl;
        }

        else if(std::strcmp(input.c_str(),"north") == 0)
        {
            std::cout << std::endl << "\t" << root["direction_descriptions"]["north"].asString() << std::endl << std::endl;
        }

        else if(std::strcmp(input.c_str(),"south") == 0)
        {
            std::cout << std::endl << "\t" << root["direction_descriptions"]["south"].asString() << std::endl << std::endl;
        }

        else if(std::strcmp(input.c_str(),"east") == 0)
        {
            std::cout << std::endl << "\t" << root["direction_descriptions"]["east"].asString() << std::endl << std::endl;
        }

        else if(std::strcmp(input.c_str(),"west") == 0)
        {
            std::cout << std::endl << "\t" << root["direction_descriptions"]["west"].asString() << std::endl << std::endl;
        }

        else if(std::strcmp(input.c_str(),"look") == 0)
        {
            std::string desc = tf::formatString( root["description"].asString() );

            std::cout << std::endl << "\t" << desc << std::endl << std::endl;
        }
    }

    return 0;
}

