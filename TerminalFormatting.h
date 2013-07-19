#ifndef TERMINALFORMATTING_H
#define TERMINALFORMATTING_H

#include <iostream>
#include <string>
#include <map>

namespace tf
{

inline void clear()
{
    for(int i=0; i<100; i++)
    {
        std::cout << std::endl;
    }
}

inline std::string formatModifier(std::string value)
{
    return std::string("\033[") + value + "m";;
}

inline std::string resetAll()
{
    return tf::formatModifier("0");
}

inline std::string resetTextColor()
{
    return tf::formatModifier("39");
}

inline std::string resetBackgroundColor()
{
    return tf::formatModifier("49");
}

inline std::string bold()
{
    return tf::formatModifier("1");
}

inline std::string boldOff()
{
    return tf::formatModifier("22");
}

inline std::string underline()
{
    return tf::formatModifier("4");
}

inline std::string underlineOff()
{
    return tf::formatModifier("24");
}

inline std::string textColor(std::string color)
{
    return tf::formatModifier(std::string("3") + color);
}

inline std::string backgroundColor(std::string color)
{
    return tf::formatModifier(std::string("4") + color);
}

inline std::string black()
{
    return "0";
}

inline std::string red()
{
    return "1";
}

inline std::string green()
{
    return "2";
}

inline std::string yellow()
{
    return "3";
}

inline std::string blue()
{
    return "4";
}

inline std::string magenta()
{
    return "5";
}

inline std::string cyan()
{
    return "6";
}

inline std::string white()
{
    return "7";
}

inline std::string defaultColor()
{
    return "9";
}

inline std::string formatString(std::string string)
{
    std::map<std::string,std::string> txtMods;
    txtMods["<b>"] = tf::bold();
    txtMods["</b>"] = tf::boldOff();
    txtMods["<u>"] = tf::underline();
    txtMods["</u>"] = tf::underlineOff();
    txtMods["<default>"] = tf::resetAll();

    std::map<std::string,std::string> colors;
    colors["black>"] = tf::black();
    colors["red>"] = tf::red();
    colors["green>"] = tf::green();
    colors["yellow>"] = tf::yellow();
    colors["blue>"] = tf::blue();
    colors["magenta>"] = tf::magenta();
    colors["cyan>"] = tf::cyan();
    colors["white>"] = tf::white();
    colors["default>"] = tf::defaultColor();

    std::size_t tagStart;

    // handle all non-color formatting
    for(std::map<std::string,std::string>::iterator i = txtMods.begin(); i != txtMods.end(); i++)
    {
        tagStart = string.find( (*i).first );
        while(tagStart!=std::string::npos)
        {
            string.replace( string.find( (*i).first ), std::string( (*i).first ).length(), (*i).second );
            tagStart = string.find( (*i).first );
        }
    }

    // handle all colors
    for(std::map<std::string,std::string>::iterator i = colors.begin(); i != colors.end(); i++)
    {
        tagStart = string.find( (*i).first );
        while(tagStart!=std::string::npos)
        {
            string.replace( string.find( (*i).first ), std::string( (*i).first ).length(), (*i).second + "m" );
            tagStart = string.find( (*i).first );
        }
    }

    // handle all text color formatting
    tagStart = string.find( "<txt:" );
    while(tagStart!=std::string::npos)
    {
        string.replace( string.find( "<txt:" ), std::string( "<txt:" ).length(), "\033[3" );
        tagStart = string.find( "<txt:" );
    }

    // handle all background color formatting
    tagStart = string.find( "<bg:" );
    while(tagStart!=std::string::npos)
    {
        string.replace( string.find( "<bg:" ), std::string( "<bg:" ).length(), "\033[4" );
        tagStart = string.find( "<bg:" );
    }

    return string;
}

}

#endif // TERMINALFORMATTING_H
