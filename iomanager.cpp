#include "iomanager.hpp"

// Sets cursor to x, y
void gotoxy(int x,int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

// Enable cursor visibility
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Clears screen
void clearScreen()
{
	ShowConsoleCursor(false);
	gotoxy(0,0);
}

// Get input
int getInput()
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
        ch = _getch();

    return ch;
}
