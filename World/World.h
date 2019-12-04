//
// Created by johnk on 11/28/2019.
//

#ifndef PROTEUSPOKEMON_WORLD_H
#define PROTEUSPOKEMON_WORLD_H


#include "Tile.h"

class World {
public:
    Tile* map[18][36];
    World(); //Instantiate the tile set map and world
};


#endif //PROTEUSPOKEMON_WORLD_H
