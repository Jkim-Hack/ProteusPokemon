//
// Created by johnk on 11/22/2019.
//

#ifndef PROTEUSPOKEMON_TEXTURE_H
#define PROTEUSPOKEMON_TEXTURE_H

enum TILETYPE {
    TALLGRASS,
    NORMAL,
};

struct Texture {
    TILETYPE tiletype;
    int encounterRate;
};


#endif //PROTEUSPOKEMON_TEXTURE_H
