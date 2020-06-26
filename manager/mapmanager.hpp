#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include "iomanager.hpp"

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class MapManager
{
    public:
        MapManager() {};

        void isExist();
        void New(string, int, int, bool);
        void Update(unsigned int, int);
        void Load();
        void Draw(int, int);

        int sum(char);

        bool isRoadside(int, int);

        // member data
        vector<vector<char>> unit;
        int ROW, COL;

        // parameters loaded for engines
        unsigned int time;
        int balance;

    private:
        string filepath;
};

#endif // MAPMANAGER_HPP
