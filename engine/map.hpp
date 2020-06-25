#ifndef MAP_H
#define MAP_H

#include "tile.hpp"

class Map
{
public:
    Map();
    void setSize(int row,int col);
    void reset();
    void show();
    void cursorTile(int row,int col);
    void emptyTile(int row,int col);

private:
    vector<Tile> tiles;
    bool boundaryCheck(int row, int col);
    int ROW, COL;
    int tileNum(int row, int col);
};

#endif // MAP_H
