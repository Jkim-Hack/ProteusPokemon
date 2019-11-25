//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_PLAYER_H
#define PROTEUSPOKEMON_PLAYER_H

#include <vector>
#include "Item.h"

class Player {

public:

    int tile_pos_r, tile_pos_c;
    int center_x, center_y;

    Player();
    Player(int, int);

    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void draw_player();

private:
    std::vector<Item> bag;
};


#endif //PROTEUSPOKEMON_PLAYER_H
