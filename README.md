This is a simple command line program for a text-based game. The main goal is to (eventually) read all important data (maps, characters, etc.) from JSON files allowing for easy editing and possibly dynamic worlds.

At the moment it is mostly a functionality test. Once it starts the only commands that currently do anything are:

attack
north
south
east
west
look
quit

but that will change soon =).

The project uses Qt Creator for the moment but does not currently use any Qt specific code. It requires jsoncpp as well. For now you'll have to edit the .pro file to have the path to your jsoncpp, or create your own Makefile if you don't have/want Qt Creator. This will probably change in the future but right now I'm too lazy =).