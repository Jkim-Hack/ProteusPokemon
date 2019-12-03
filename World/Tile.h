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

    bool can_left, can_right, can_down, can_up;

    void set_origin(int, int);
    void draw_tile();
    void set_texture(Texture);
    void onPlayerEnter();
    void onPlayerExit();
private:

    unsigned int (*bar)[256];
    unsigned int (*rock)[256];
    unsigned int (*stairs)[256];
    unsigned int (*jumpable)[256];
    unsigned int (*green)[256];
    unsigned int (*gravel)[256];

    void init_tiles();

    Texture texture;
    void draw_two_path_rect(int, int);
    void draw_tall_grass_quarter(int,int);
    void draw_bar(int, int);
    void draw_rock(int, int);
    void draw_stairs(int, int);
    void draw_jumpable(int,int);
    void draw_green(int,int);
    void draw_gravel(int,int);
};


#endif //PROTEUSPOKEMON_TILE_H
