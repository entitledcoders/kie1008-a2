#include "tile.hpp"
#include "../manager/iomanager.hpp"

Tile::Tile()
{
    emptyTile();
    occupied = false;
}

void Tile::print()
{
    cout << bracket[0] << tile << bracket[1];
}

void Tile::emptyTile()
{
    bracket[0] = '[';
    bracket[1] = ']';
    tile       = ' ';
    occupied = false;
}

void Tile::cursorTile()
{
    bracket[0] = '>';
    bracket[1] = '<';
    tile       = ' ';
    occupied = false;
}

void Tile::residentTile()
{
    bracket[0] = ' ';
    bracket[1] = ' ';
    tile       = 'R';
    occupied = true;
}

void Tile::commercialTile()
{
    bracket[0] = ' ';
    bracket[1] = ' ';
    tile       = 'C';
    occupied = true;
}

void Tile::industrialTile()
{
    bracket[0] = ' ';
    bracket[1] = ' ';
    tile       = 'I';
    occupied = true;
}

bool Tile::isEmpty()
{
    return occupied;
}
