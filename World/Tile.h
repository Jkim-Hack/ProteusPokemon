//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_TILE_H
#define PROTEUSPOKEMON_TILE_H


#include "Texture.h"
#include "../Player/Player.h"
#include "../World/World.h"

class Tile {
public:
    //Instantiate the objects
    Tile();
    Tile(int, int, Texture);
    Tile(int, int, int, int, Texture);

    //The size and origin
    int sizeX, sizeY;
    int originX, originY;

    //Can the left, right, down, and up
    bool can_left, can_right, can_down, can_up;

    void set_origin(int, int); //Set the origin
    void draw_tile(); //Draws the tile
    void set_texture(Texture); //Sets the texture
    void onPlayerEnter(Player*); //On player enter
    void onPlayerExit(); //On player exit
private:

    unsigned short int (*bar)[256];
    unsigned short int (*rock)[256];
    unsigned short int (*stairs)[256];
    unsigned short int (*jumpable)[256];
    unsigned short int (*green)[256];
    unsigned short int (*gravel)[256];

    void init_tiles(); //Initialize all tiles

    //Draws all textures
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
