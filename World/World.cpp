//
// Created by johnk on 11/28/2019.
//

#include <cstdio>
#include "World.h"
#include "../Libraries/FEHSD.h"
#include "../Libraries/FEHLCD.h"
#include "Tile.h"

World::World() {

    char line[19];
    int count = 0;
    while(SD.fscanf("route1.txt", count, "%s", line) != EOF) {
        for (int i = 0; i < 18; ++i) {
            char c = line[i];
            switch (c) {
                case '!':
                    Texture texture;
                    texture.tiletype = GRAVEL;
                    texture.encounterRate = 0;
                    Tile tile(count * 16, i * 16, texture);
                    map[count][i] = &tile;
                    break;
                case '@':
                    Texture texture1;
                    texture1.tiletype = BAR;
                    texture1.encounterRate = 0;
                    Tile tile1(count * 16, i * 16, texture1);
                    map[count][i] = &tile1;
                    break;
                case '#':
                    Texture texture2;
                    texture2.tiletype = GREEN1;
                    texture2.encounterRate = 0;
                    Tile tile2(count * 16, i * 16, texture2);
                    map[count][i] = &tile2;
                    break;
                case '$':
                    Texture texture3;
                    texture3.tiletype = ROCK;
                    texture3.encounterRate = 0;
                    Tile tile3(count * 16, i * 16, texture3);
                    map[count][i] = &tile3;
                    break;
                case '%':
                    Texture texture4;
                    texture4.tiletype = JUMPABLE;
                    texture4.encounterRate = 0;
                    Tile tile4(count * 16, i * 16, texture4);
                    map[count][i] = &tile4;
                    break;
                case '*':
                    Texture texture5;
                    texture5.tiletype = TALLGRASS;
                    texture5.encounterRate = 50;
                    Tile tile5(count * 16, i * 16, texture5);
                    map[count][i] = &tile5;
                    break;
            }
        }
        count++;
    }

}

void World::move_up() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 36; ++j) {
            int x = map[i][j]->originX;
            int y = map[i][j]->originY;
            y--;
            if(map[i][j]->can_down)
                map[i][j]->set_origin(x,y);
        }
    }
}

void World::move_down() {

    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 36; ++j) {
            int x = map[i][j]->originX;
            int y = map[i][j]->originY;
            y++;
            if(map[i][j]->can_up)
                map[i][j]->set_origin(x,y);
        }
    }
}

void World::move_left() {

    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 36; ++j) {
            int x = map[i][j]->originX;
            int y = map[i][j]->originY;
            x++;
            if(map[i][j]->can_right)
                map[i][j]->set_origin(x,y);
        }
    }
}

void World::move_right() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 36; ++j) {
            int x = map[i][j]->originX;
            int y = map[i][j]->originY;
            x--;
            if(map[i][j]->can_left)
                map[i][j]->set_origin(x,y);
        }
    }
}