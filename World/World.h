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

    bool move_right(int, int);
    bool move_left(int, int);
    bool move_up(int, int);
    bool move_down(int, int);
};


#endif //PROTEUSPOKEMON_WORLD_H
