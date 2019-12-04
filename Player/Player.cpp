//
// Created by johnk on 11/22/2019.
//

#include "Player.h"
#include "../Libraries/FEHLCD.h"
#include "../Libraries/FEHUtility.h"

#define LENGTH 320
#define WIDTH 240

Player::Player() { //One class

    //Set player tile position to (9,7) (x,y)
    this->tile_pos_r = 7;
    this->tile_pos_c = 9;

    //Set the texture type to PLAYER
    this->playerTexture.tiletype = PLAYER;

    //Generate a new world
    this->world = World();

    //Set the origin to center of the screen then center of the tile system
    this->originX = LENGTH/2 - 16;
    this->originY = WIDTH/2 - 16;

    //The sprite pixel numbers of each position:

    //0 = face down
    //1 = face up
    //2 = face left
    //3 = walk down
    //4 = walk up
    //5 = walk horiz
    short int sprite_0[] = {
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_1[] = {
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_2[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_3[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_4[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_5[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01,
    };

    //Copy each sprite to the object's sprite arrays
    for (int i = 0; i < 256; ++i) {
        this->sprite0[i] = sprite_0[i];
        this->sprite1[i] = sprite_1[i];
        this->sprite2[i] = sprite_2[i];
        this->sprite3[i] = sprite_3[i];
        this->sprite4[i] = sprite_4[i];
        this->sprite5[i] = sprite_5[i];
    }

    //Draw the players in the down position
    draw_player(0);

}

Player::Player(int tile_pos_r, int tile_pos_c) {

    //Set player tile position to the given arguments (x,y)
    this->tile_pos_r = tile_pos_r;
    this->tile_pos_c = tile_pos_c;

    //Set the texture type to PLAYER
    this->playerTexture.tiletype = PLAYER;

    //Generate a new world
    this->world = World();

    //Set the origin to center of the screen then center of the tile system
    this->originX = LENGTH/2 - 16;
    this->originY = WIDTH/2 - 16;

    //The sprite pixel numbers of each position:

    //0 = face down
    //1 = face up
    //2 = face left
    //3 = walk down
    //4 = walk up
    //5 = walk horiz

    short int sprite_0[] = {
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_1[] = {
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_2[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_3[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_4[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    };

    short int sprite_5[] = {

            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x01, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x02, 0x03, 0x03, 0x03, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x02, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01,
    };

    //Copy each sprite to the object's sprite arrays
    for (int i = 0; i < 256; ++i) {
        this->sprite0[i] = sprite_0[i];
        this->sprite1[i] = sprite_1[i];
        this->sprite2[i] = sprite_2[i];
        this->sprite3[i] = sprite_3[i];
        this->sprite4[i] = sprite_4[i];
        this->sprite5[i] = sprite_5[i];
    }

    //Draw player in the downward position
    draw_player(0);

}

void Player::draw_player(int type) {

    //0 = face down
    //1 = face up
    //2 = face left
    //3 = walk down
    //4 = walk up
    //5 = walk horiz

    //0 = black 20 22 20
    //1 = green 4 254 4 change to transparent
    //2 = gray 156 154 156
    //3 = white 236 234 236
    //4 = light gray 180 178 180

    short int(*pixels)[256];
    switch (type){
        case 0: //face down
            pixels = &this->sprite0;
            break;
        case 1: //face up
            pixels = &this->sprite1;
            break;
        case 2: //face left
            pixels = &this->sprite2;
            break;
        case 3: //walk down
            pixels = &this->sprite3;
            break;
        case 4: //walk up
            pixels = &this->sprite4;
            break;
        case 5: //walk left
            pixels = &this->sprite5;
            break;
        case 6: //face right
            pixels = &this->sprite2;
            reverse_pixels(pixels);
            break;
        case 7: //walk right
            pixels = &this->sprite5;
            reverse_pixels(pixels);
            break;
        default:
            pixels = &this->sprite0;
            break;
    }

    //i = height //j = width
    //Draws the player using the LCD draw pixel with the according pixel type
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = (*pixels)[j + (i*16)];
            switch (pixel) { //Switch case
                case 0:
                    LCD.SetFontColor(0x141614);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    break;
                case 2:
                    LCD.SetFontColor(0x9C9A9C);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 3:
                    LCD.SetFontColor(0xECEAEC);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 4:
                    LCD.SetFontColor(0xB4B2B4);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }

}

void Player::reverse_pixels(short int (*pixels)[256]) {

    //Reverse the pixels vertically so that the horizontal orientation is correct
    for (int i = 0; i < 16; ++i) { //For loop
        for (int j = 0; j < 8; ++j) {
            int temp = *pixels[(i*16)+j];
            *pixels[(i*16) + j] = *pixels[(i*16) + (8-j-1)];
            *pixels[(i*16) + (8-j-1)] = temp;
        }
    }
}

//Move the player down
void Player::move_down() {

    draw_player(0); //Draw player in the down position
    Sleep(143); //Wait before next frame
    if(this->originY + 16 < 240){ //Check if player is at the bottom
        this->originY += 16; //Move down origin
    }
    draw_player(3); //Draw player in the moving down position
    if(this->originY + 16 < 240) {
        this->world.map[this->tile_pos_r][this->tile_pos_c]->onPlayerExit(); //Tile should redraw after the player exits
        this->tile_pos_r += 1; //Move tile position
    }
    Sleep(143); //Wait for next frame

}

//Move the player up
void Player::move_up() {

    draw_player(1);//Draw player in the up position
    Sleep(143);//Wait before next frame
    if(this->originY - 16 > 0){//Check if player is at the bottom
        this->originY -= 16;//Move down origin
    }
    draw_player(4);//Draw player in the moving up position
    if(this->originY - 16 > 0) {
        this->world.map[this->tile_pos_r][this->tile_pos_c]->onPlayerExit();//Tile should redraw after the player exits
        this->tile_pos_r -= 1;//Move tile position
    }
    Sleep(143);//Move tile position

}

//Move the player right
//Same as above
void Player::move_right() {

    draw_player(6);
    Sleep(143);
    if(this->originX + 16 < 320){
        this->originX += 16;
    }
    draw_player(7);
    if(this->originX + 16 < 320){
        this->world.map[this->tile_pos_r][this->tile_pos_c]->onPlayerExit();
        this->tile_pos_c += 1;
    }
    Sleep(143);

}

//Move the player left
//Same as above
void Player::move_left() {

    draw_player(2);
    Sleep(143);
    if(this->originX - 16 > 0) {
        this->originX -= 16;
    }
    draw_player(5);
    if(this->originX - 16 > 0) {
        this->world.map[this->tile_pos_r][this->tile_pos_c]->onPlayerExit();
        this->tile_pos_c -= 1;
    }
    Sleep(143);

}
