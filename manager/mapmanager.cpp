#include "mapmanager.hpp"

void MapManager::isExist()
{
    ifstream mapfile;
    mapfile.open(filepath);
    if(mapfile.fail()){
        cerr << "(E0) " << filepath << " does not exist, creating new map" << endl;
        this->New(filepath, ROW, COL, 0);
    }
}

void MapManager::New(string path, int r, int c, bool load)
{
    ROW = r;
    COL = c;
    filepath = path;
    if(!load)
    {
    ofstream mapfile;
    system("mkdir map");
    mapfile.open(filepath);
    for(int row = 0; row < ROW; row++)
        {
            for(int col = 0; col < COL; col++)
            {mapfile << " ";}
        mapfile << endl;
        }
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
        //cout << temp;                             //Probing point (test for line copy)
        for(int col = 0; col < COL; col++)
        {
            unit[row][col] = temp[col];
        }
    }
    getline(mapfile, temp);
    stringstream(temp) >> time;
    getline(mapfile, temp);
    stringstream(temp) >> balance;
}

void MapManager::Update(unsigned int elapsed, int money)
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
    mapfile << elapsed << endl;
    mapfile << money;
}

void MapManager::Draw(int x, int y)
{
    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        {
            bool cursor;
            ((row==x)&&(col==y))? cursor = true : cursor = false ;

            {
            switch (unit[row][col])
                {
                    case 'a':   textColor(DARK_GRAY, LIGHT_GREEN);
                                cursor? cout << "> <": cout << "   ";
                                textColorRestore();
                                break;
                    case 'd':   textColor(DARK_GRAY, LIGHT_BLUE);
                                cursor? cout << "> <": cout << "   ";
                                textColorRestore();
                                break;
                    case 'g':   textColor(DARK_GRAY, LIGHT_RED);
                                cursor? cout << "> <": cout << "   ";
                                textColorRestore();
                                break;
                    default:    cursor? cout << "> <": cout << "[ ]";
                }
            }
            // Cursor


        }
        cout << endl;
    }
}
