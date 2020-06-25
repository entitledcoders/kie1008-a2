#ifndef MAP_H
#define MAP_H

#include "tile.hpp"

class Map
{
public:
    Map();
    void reset();
    void show();

private:
    vector<Tile> tiles;
    int ROW, COL;
};

#endif // MAP_H
