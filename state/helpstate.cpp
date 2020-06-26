#include "helpstate.hpp"
#include <fstream>

HelpState HelpState::m_HelpState;

void HelpState::Init()
{
    system("CLS");
    currentPage = 1;
    loadHelp();
}

void HelpState::Draw(StateManager* game)
{
    recursor(0, 2);
    cout << "      ------------------------------" << endl;
    cout << "                Help (" << currentPage << "/" << page << ")" << endl;
    cout << "      ------------------------------" << endl;
    textColor(WHITE);
    helpPage[currentPage - 1].print();
    textColorRestore();
}

void HelpState::HandleEvents(StateManager* game)
{
    // Change pages on key input
    switch(getInput())
    {
        case RIGHT: currentPage++;
                    system("CLS");
                        break;
        case LEFT:  currentPage--;
                    system("CLS");
                        break;
        case ESC:   game->PopState();
                        break;
    }
}

void HelpState::Update(StateManager* game)
{
    // Limits currentPage to available pages.
    if(currentPage < 1) { currentPage=1; }
    if(currentPage > page) { currentPage=page; }
}

void HelpState::loadHelp()
{
    string tempPath;

    for(int i = 0; i < page; i++)
    {
        string tempPath = "help/help_";
        tempPath.append(to_string(i+1));
        tempPath.append(".txt");
        File newPage(tempPath);
        helpPage.push_back(newPage);
    }

}
