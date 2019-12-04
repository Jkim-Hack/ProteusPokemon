//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_TEXTURE_H
#define PROTEUSPOKEMON_TEXTURE_H

//Texture enums
enum TILETYPE {
    TALLGRASS,
    PATH,
    NORMAL,
    BAR,
    ROCK,
    STAIRS,
    JUMPABLE,
    GREEN1,
    GRAVEL,
    PLAYER,
};

struct Texture {
    TILETYPE tiletype;
    int encounterRate;
};


#endif //PROTEUSPOKEMON_TEXTURE_H
