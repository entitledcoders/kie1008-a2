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

//--------------------- INPUT FILE --------------------

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

//------------------ INPUT KEYBOARD --------------------

int getInput();

// All keys decoded from _getch
#define    UP      72
#define    DOWN    80
#define    LEFT    75
#define    RIGHT   77
#define    ENTER   13
#define    ESC     27
#define    SPACE   32

//------------------ OUTPUT CURSOR ---------------------

void gotoxy(int x,int y);
void recursor(int, int);
void showConsoleCursor(bool showFlag);

//------------------ OUTPUT COLOUR ---------------------
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define YELLOW			6
#define LIGHT_GRAY	    7
#define DARK_GRAY		8
#define LIGHT_BLUE		9
#define LIGHT_GREEN		10
#define LIGHT_CYAN		11
#define LIGHT_RED		12
#define PURPLE      	13
#define LIGHT_YELLOW 	14
#define WHITE			15

void consoleColor(int foreground, int backround);
void textColor(int foreground);
void textColor(int foreground, int backround);
void textColorRestore();

#endif  // IOMANAGER_HPP
