#include "map.hpp"
#include "../manager/iomanager.hpp"

Map::Map()
{
    reset();
}

void Map::setSize(int row,int col)
{
    ROW = row;
    COL = col;
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
            tiles[tileNum(i,j)].print();
        }
        cout << endl;
    }
}

void Map::cursorTile(int row,int col)
{
    if(boundaryCheck(row,col))
    {
        tiles[tileNum(row,col)].cursorTile();
    }
}

void Map::emptyTile(int row,int col)
{
    if(boundaryCheck(row,col))
    {
        tiles[tileNum(row,col)].emptyTile();
    }
}

int Map::tileNum(int row,int col)
{
    return col + (row*ROW);
}


bool Map::boundaryCheck(int row, int col)
{
    return (row >= 0 && col >= 0 && row < ROW && col < COL);
}
