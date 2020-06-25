#ifndef TILE_H
#define TILE_H


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
    bool occupied;
    char bracket[2];
    char tile;

};

#endif // TILE_H
