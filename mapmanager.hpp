#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

enum { ROW = 24, COL = 20, BIT = 2};

class MapManager
{
    public:
        MapManager();

        void isExist();
        void New();
        void Update();
        void Load();
        void Draw();

        string unit[ROW][COL];
    private:
        string filepath = "map/save.txt";
};

#endif // MAPMANAGER_HPP
