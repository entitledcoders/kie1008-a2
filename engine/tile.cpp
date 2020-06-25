#include "tile.hpp"


Tile::Tile()
{
    emptyTile();
    occupied = false;
    current = "empty";
}

void Tile::print()
{
    if(current == "cursor")
    {
        textColor(RED);
    }
    cout << bracket[0] << tile << bracket[1];
    textColorRestore();
}

void Tile::emptyTile()
{
    bracket[0] = '[';
    bracket[1] = ']';
    tile       = ' ';
    current = "empty";
    occupied = false;
}

void Tile::cursorTile()
{
    bracket[0] = '>';
    bracket[1] = '<';
    tile       = ' ';
    current = "cursor";
    occupied = false;
}

void Tile::residentTile()
{
    bracket[0] = ' ';
    bracket[1] = ' ';
    tile       = 'R';
    current = "resident";
    occupied = true;
}

void Tile::commercialTile()
{
    bracket[0] = ' ';
    bracket[1] = ' ';
    tile       = 'C';
    current = "commercial";
    occupied = true;
}

void Tile::industrialTile()
{
    bracket[0] = ' ';
    bracket[1] = ' ';
    tile       = 'I';
    current = "industrial";
    occupied = true;
}

bool Tile::isEmpty()
{
    return occupied;
}
