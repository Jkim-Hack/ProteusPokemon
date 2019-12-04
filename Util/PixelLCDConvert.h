//
// Created by johnk on 11/30/2019.
//

#ifndef PROTEUSPOKEMON_PIXELLCDCONVERT_H
#define PROTEUSPOKEMON_PIXELLCDCONVERT_H

//The enums of SCREENTYPE
enum SCREENTYPE {
    COPYRIGHT,
    INTRO
};

class PixelLCDConvert {

private:
    //Initialize sizes
    int sizeX;

public:
    PixelLCDConvert(int);
    void pixelarr_to_lcd(char [50], SCREENTYPE); //Changes the pixel array into LCD pixels

private:
    void addToMapCopyright(char [50]); //Adds the copyright
    void addToMapIntro(char [50]); //Adds the intro
};


#endif //PROTEUSPOKEMON_PIXELLCDCONVERT_H
