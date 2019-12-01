//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_PLAYER_H
#define PROTEUSPOKEMON_PLAYER_H

#include "Item.h"
#include "../World/Texture.h"
#include "../World/World.h"

class Player {

public:
    int tile_pos_r, tile_pos_c;
    int originX, originY;
    Texture playerTexture;
    World world;

    Player();
    Player(int, int);

    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void draw_player(int);

private:
    void reverse_pixels(int(*)[256]);
    int sprite0[256];
    int sprite1[256];
    int sprite2[256];
    int sprite3[256];
    int sprite4[256];
    int sprite5[256];
};


#endif //PROTEUSPOKEMON_PLAYER_H
