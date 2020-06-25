#ifndef TILE_H
#define TILE_H

#include "../manager/iomanager.hpp"

class Tile
{
public:
    Tile();
    void print();
    void emptyTile();
    void cursorTile();
    void residentTile();
    void commercialTile();
    void industrialTile();
    bool isEmpty();

private:
    string current;
    bool occupied;
    char bracket[2];
    char tile;

};

#endif // TILE_H
