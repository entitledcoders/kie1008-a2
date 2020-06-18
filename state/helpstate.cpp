#include "helpstate.hpp"
#include <fstream>

HelpState HelpState::m_HelpState;

void HelpState::Init()
{
    system("CLS");
    currentPage = 1;
    loadHelp();
}

void HelpState::Draw(GameEngine* game)
{
    recursor(0, 2);
    cout << "   ------------------------------" << endl;
    cout << "            Help (" << currentPage << "/" << page << ")" << endl;
    cout << "   ------------------------------" << endl;
    helpPage[currentPage - 1].print();
}

void HelpState::HandleEvents(GameEngine* game)
{
    // Change pages on key input
    switch(getInput())
    {
        case RIGHT: currentPage++;
                        break;
        case LEFT:  currentPage--;
                        break;
        case ESC:   game->PopState();
                        break;
    }
}

void HelpState::Update(GameEngine* game)
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
