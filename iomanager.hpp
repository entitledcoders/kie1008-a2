#ifndef IOMANAGER_HPP
#define IOMANAGER_HPP

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// All keys decoded from _getch
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

void gotoxy(int x,int y);
void recursor(int, int);
int getInput();
void ShowConsoleCursor(bool showFlag);

//Load text from .txt file
class File
{
public:
    File(string filePath);
    void print();

private:
    void load();
    string path;
    vector <string> fileData;
};



#endif  // IOMANAGER_HPP
