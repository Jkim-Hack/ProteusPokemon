//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_TILE_H
#define PROTEUSPOKEMON_TILE_H


#include "Texture.h"
#include "../Player/Player.h"

class Tile {
public:
    Tile();
    Tile(int, int, Texture);
    Tile(int, int, int, int, Texture);
    int sizeX, sizeY;
    int originX, originY;
    Player *player;

    void draw_tile();
    void set_texture(Texture);
    void onPlayerEnter(Player*);
    void onPlayerExit();
private:
    Texture texture;
    void draw_two_path_rect(int, int);
    void draw_tall_grass_quarter(int,int);

};


#endif //PROTEUSPOKEMON_TILE_H
