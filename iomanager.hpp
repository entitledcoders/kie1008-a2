#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

enum eMenu
{
    START = 0,
    HELP = 1,
    EXIT = 2,

    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77,
    ENTER = 13,
    ESC = 27,
    SPACE = 32
};

class IOManager
{
public:
    void gotoxy(int x,int y);
    void clearscreen();
    int getInput();

private:
    void ShowConsoleCursor(bool showFlag);
};

#endif // IOMANAGER_H
