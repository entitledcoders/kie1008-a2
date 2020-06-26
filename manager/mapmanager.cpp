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
    unit.resize(ROW, vector<char>(COL));
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
                    case '0':   textColor(WHITE, BLACK);
                                cursor? cout << "[]": cout << "--";
                                textColorRestore();
                                break;
                    case 'a':   textColor(WHITE, GREEN);
                                cursor? cout << "[]": cout << "  ";
                                textColorRestore();
                                break;
                    case 'd':   textColor(WHITE, BLUE);
                                cursor? cout << "[]": cout << "  ";
                                textColorRestore();
                                break;
                    case 'g':   textColor(WHITE, RED);
                                cursor? cout << "[]": cout << "  ";
                                textColorRestore();
                                break;
                    default:    textColor(GREEN, LIGHT_GREEN);
                                cursor? cout << "[]": cout << "^^";
                                textColorRestore();
                }
            }
        }
        cout << endl;
    }
}

int MapManager::sum(char type)
{
    int sum = 0;
    for(int i = 0; i<ROW; i++)
    {
        for(int j = 0; j<COL; j++)
        {
            if(unit[i][j]==type) {sum++;}
        }
    }
    return sum;
}

bool MapManager::isRoadside(int x, int y)
{
    if(x!=0) {if(unit[x-1][y]=='0') {return true;}}
    if(y!=0) {if(unit[x][y-1]=='0') {return true;}}
    if(x!=ROW) {if(unit[x+1][y]=='0') {return true;}}
    if(y!=COL) {if(unit[x][y+1]=='0') {return true;}}
    return false;
}
