//
// Created by johnk on 11/28/2019.
//

#include <cstdio>
#include "World.h"
#include "../Libraries/FEHSD.h"
#include "../Libraries/FEHLCD.h"
#include "Tile.h"

World::World() {

    char line[19]; //Get the line
    int count = 0; //The row position
    //r1.txt is the txt file with all the tile positions
    while(SD.fscanf("r1.txt", count, "%s", line) != EOF) {
        for (int i = 0; i < 18; ++i) {
            char c = line[i]; //Get each character
            //For each character within the txt tile set, draw the tile with the texture.
            switch (c) {
                case '!': {
                    Texture texture;
                    texture.tiletype = GRAVEL;
                    texture.encounterRate = 0;
                    Tile tile(i * 16, count * 16,texture);
                    map[count][i] = &tile;
                    break;
                }
                case '@': {
                    Texture texture1;
                    texture1.tiletype = BAR;
                    texture1.encounterRate = 0;
                    Tile tile1(i * 16, count * 16, texture1);
                    map[count][i] = &tile1;
                    break;
                }
                case '#': {
                    Texture texture2;
                    texture2.tiletype = PATH;
                    texture2.encounterRate = 0;
                    Tile tile2(i * 16, count * 16, texture2);
                    map[count][i] = &tile2;
                    break;
                }
                case '$': {
                    Texture texture3;
                    texture3.tiletype = GREEN1;
                    texture3.encounterRate = 0;
                    Tile tile3(i * 16, count * 16, texture3);
                    map[count][i] = &tile3;
                    break;
                }
                case '%': {
                    Texture texture4;
                    texture4.tiletype = GREEN1;
                    texture4.encounterRate = 0;
                    Tile tile4(i * 16, count * 16, texture4);
                    map[count][i] = &tile4;
                    break;
                }
                case '*': {
                    Texture texture5;
                    texture5.tiletype = ROCK;
                    texture5.encounterRate = 0;
                    Tile tile5(i * 16, count * 16, texture5);
                    map[count][i] = &tile5;
                    break;
                }
                case ')': {

                    Texture texture6;
                    texture6.tiletype = TALLGRASS;
                    texture6.encounterRate = 50;
                    Tile tile6(i * 16, count * 16, texture6);
                    map[count][i] = &tile6;
                    break;
                }
                case '+': {
                    Texture texture7;
                    texture7.tiletype = JUMPABLE;
                    texture7.encounterRate = 50;
                    Tile tile7(i * 16, count * 16, texture7);
                    map[count][i] = &tile7;
                    break;
                }
                case '~': {
                    Texture texture8;
                    texture8.tiletype = JUMPABLE;
                    texture8.encounterRate = 0;
                    Tile tile8(i * 16, count * 16, texture8);
                    map[count][i] = &tile8;
                    break;
                }
                case '&': {
                    Texture texture9;
                    texture9.tiletype = JUMPABLE;
                    texture9.encounterRate = 0;
                    Tile tile9(i * 16, count * 16, texture9);
                    map[count][i] = &tile9;
                    break;
                }
                case '=': {
                    Texture texture10;
                    texture10.tiletype = JUMPABLE;
                    texture10.encounterRate = 0;
                    Tile tile10(i * 16, count * 16, texture10);
                    map[count][i] = &tile10;
                    break;
                }
                default: {
                    Texture texture11;
                    texture11.tiletype = PATH;
                    texture11.encounterRate = 0;
                    Tile tile11(i * 16, count * 16, texture11);
                    map[count][i] = &tile11;
                    break;
                }
            }
        }
        count++;
    }

}

