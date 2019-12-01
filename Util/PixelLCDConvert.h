//
// Created by johnk on 11/30/2019.
//

#ifndef PROTEUSPOKEMON_PIXELLCDCONVERT_H
#define PROTEUSPOKEMON_PIXELLCDCONVERT_H

enum SCREENTYPE {
    COPYRIGHT,
    INTRO
};

class PixelLCDConvert {

private:
    int sizeX, sizeY;
    int** map;

public:
    PixelLCDConvert(int, int);
    void pixelarr_to_lcd(char [50], SCREENTYPE);

private:
    void addToMap(char [50]);
    void showtoscreen(const char*[]);
    void getDelims(char *, int);
};


#endif //PROTEUSPOKEMON_PIXELLCDCONVERT_H
