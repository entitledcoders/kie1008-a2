#include "iomanager.hpp"



//--------------------- INPUT FILE --------------------

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

//------------------ INPUT KEYBOARD --------------------

int getInput()
{
    if(kbhit())
    {
        int ch = getch();

        if (ch == 0 || ch == 224)
        ch = getch();

        return ch;
    }

}

//------------------ OUTPUT CURSOR ---------------------

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Sets cursor to x, y
void gotoxy(int x,int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole,pos);
}

// Enable cursor visibility
void showConsoleCursor(bool showFlag)
{
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// Recursors
void recursor(int x,int y)
{
	showConsoleCursor(false);
	gotoxy(x,y);
}

//------------------ OUTPUT COLOUR ---------------------

int defaultFG = WHITE;
int defaultBG = BLACK;

void consoleColor(int foreground, int backround)
{
    defaultFG = foreground;
    defaultBG = backround;

    string colorCMD = "color ";
    if(backround > 9)
    {
        switch(backround)
        {
        case 10:
            colorCMD.append("A");
            break;

        case 11:
            colorCMD.append("B");
            break;

        case 12:
            colorCMD.append("C");
            break;

        case 13:
            colorCMD.append("D");
            break;

        case 14:
            colorCMD.append("E");
            break;

        case 15:
            colorCMD.append("F");
            break;
        }
    }
    else
    {
        colorCMD.append(to_string(backround));
    }

    if(foreground > 9)
    {
        switch(foreground)
        {
        case 10:
            colorCMD.append("A");
            break;

        case 11:
            colorCMD.append("B");
            break;

        case 12:
            colorCMD.append("C");
            break;

        case 13:
            colorCMD.append("D");
            break;

        case 14:
            colorCMD.append("E");
            break;

        case 15:
            colorCMD.append("F");
            break;
        }
    }
    else
    {
        colorCMD.append(to_string(foreground));
    }

    system(colorCMD.c_str());
}

void textColor(int foreground)
{
    SetConsoleTextAttribute(hConsole, foreground + (defaultBG*16));
}

void textColor(int foreground, int backround)
{
    int colourCombo = foreground + (backround*16);
    SetConsoleTextAttribute(hConsole, colourCombo);
}

void textColorRestore()
{
    textColor(defaultFG,defaultBG);
}
