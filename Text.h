//
// Created by johnk on 11/30/2019.
//

#ifndef PROTEUSPOKEMON_TEXT_H
#define PROTEUSPOKEMON_TEXT_H

#include <string>

class Text {

private:
    std::string text;
    unsigned int topleft[64];
    unsigned int botleft[64];
    unsigned int topright[64];
    unsigned int midleft[64];
    unsigned int midright[64];
    unsigned int botright[64];
    unsigned int mid[64];
public:
    Text(std::string);

};


#endif //PROTEUSPOKEMON_TEXT_H
