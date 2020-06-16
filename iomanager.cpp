#include "iomanager.hpp"

void gotoxy(int x,int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void clearscreen()
{
	ShowConsoleCursor(false);
	gotoxy(0,0);
}

int getInput()
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
        ch = _getch();

    return ch;
}
