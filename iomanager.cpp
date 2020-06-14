#include "iomanager.h"

void IOManager::gotoxy(int x,int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void IOManager::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void IOManager::clearscreen()
{
	ShowConsoleCursor(false);
	gotoxy(0,0);
}

int IOManager::getInput()
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
        ch = _getch();

    return ch;
}
