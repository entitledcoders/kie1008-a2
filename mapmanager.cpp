#include "mapmanager.hpp"

MapManager::MapManager()
{}

void MapManager::isExist()
{
    ifstream mapfile;
    mapfile.open(filepath);
    if(mapfile.fail()){
        cerr << "(E0) " << filepath << " does not exist, creating new map" << endl;
        this->New();
    }
}

void MapManager::New()
{
    ofstream mapfile;
    system("mkdir map");
    mapfile.open(filepath);
    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL*BIT; col++)
        {mapfile << "0";}
    mapfile << endl;
    }
}

void MapManager::Load()
{
    ifstream mapfile;
    this->isExist();
    mapfile.open(filepath);
    string temp;
    for(int row = 0; row < ROW; row++)
    {
        getline(mapfile, temp);
        //cout << temp;                             Probing point (test for line copy)
        for(int col = 0; col < COL; col++)
        {
            this->unit[row][col] = temp.substr(col*BIT, BIT);
        }
    }
}

void MapManager::Update()
{
    ofstream mapfile;
    mapfile.open(filepath, ios::out | ios::trunc);
    mapfile.close();
    mapfile.open(filepath, ios::app);
    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        { mapfile << unit[row][col]; }
        mapfile << endl;
    }
}

void MapManager::Draw()
{
    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        {
            cout << "[" << unit[row][col] << "]";
        }
        cout << endl;
    }
}
