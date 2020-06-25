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

        char unit[24][20];
        int ROW, COL;

        unsigned int time;
        int balance;

    private:
        string filepath;
};

#endif // MAPMANAGER_HPP
