//
// Created by johnk on 11/28/2019.
//

#ifndef PROTEUSPOKEMON_WORLD_H
#define PROTEUSPOKEMON_WORLD_H


#include "Tile.h"

class World {
public:
    Tile* map[18][36];
    World();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
};


#endif //PROTEUSPOKEMON_WORLD_H
