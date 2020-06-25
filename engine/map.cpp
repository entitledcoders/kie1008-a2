#include "map.hpp"
#include "../manager/iomanager.hpp"

Map::Map()
{
    ROW = 10;
    COL = 10;
    reset();
}

void Map::reset()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            Tile newTile;
            tiles.push_back(newTile);
        }
    }
}

void Map::show()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            int currentTile = i + (j*10);
            tiles[currentTile].print();
        }
        cout << endl;
    }
}
