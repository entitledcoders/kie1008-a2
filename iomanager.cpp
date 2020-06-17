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

// Recursors
void recursor(int x,int y)
{
	ShowConsoleCursor(false);
	gotoxy(x,y);
}

// Get input
int getInput()
{
    int ch = _getch();

    if (ch == 0 || ch == 224)
        ch = _getch();

    return ch;
}

File::File(string filePath)
{
    path = filePath;
    load();
}

void File::load()
{
    ifstream file;

    file.open(path);
    if(file.fail()){ perror(path.c_str()); }

    string line;

    //Load each line
    while(getline(file,line))
    {
        fileData.push_back(line);
    }

    file.close();
}

void File::print()
{
    for(int i = 0; i < fileData.size(); i++)
    {
        cout << fileData[i] << endl;
    }
}
