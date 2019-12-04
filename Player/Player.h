//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_PLAYER_H
#define PROTEUSPOKEMON_PLAYER_H

#include "../World/Texture.h"
#include "../World/World.h"

class Player {

public:
    //Instantiate tile positions, textures and world
    int tile_pos_r, tile_pos_c;
    int originX, originY;
    Texture playerTexture;
    World world;

    Player();
    Player(int, int);

    void move_right(); //Moves player right
    void move_left(); //Moves player left
    void move_up(); //Moves player up
    void move_down(); //Moves player down
    void draw_player(int); //Draw the player

private:
    void reverse_pixels(short int(*)[256]); //Reverses the pixels
    short int sprite0[256];
    short int sprite1[256];
    short int sprite2[256];
    short int sprite3[256];
    short int sprite4[256];
    short int sprite5[256];
};


#endif //PROTEUSPOKEMON_PLAYER_H
