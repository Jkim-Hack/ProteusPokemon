//
// Created by johnk on 11/22/2019.
//

#include "Tile.h"
#include "../Libraries/FEHLCD.h"
#include <time.h>
#include <cstdlib>

Tile::Tile() {
    Texture texture;
    texture.tiletype = PATH;
    texture.encounterRate = 0;

    this->texture = texture;
    this->sizeX = 16;
    this->sizeY = 16;
    this->originX = 0;
    this->originY = 0;
    this->draw_tile();
}

Tile::Tile(int originX, int originY, Texture texture) {
    this->texture = texture;
    this->originX = originX;
    this->originY = originY;
    this->sizeX = 0;
    this->sizeY = 0;
    this->draw_tile();
}

Tile::Tile(int sizeX, int sizeY, int originX, int originY, Texture texture) {
    this->texture = texture;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->originX = originX;
    this->originY = originY;
    this->draw_tile();
}

void Tile::set_origin(int x, int y) {
    this->originX = x;
    this->originY = y;
    draw_tile();
}

void Tile::draw_tile() {
    switch (this->texture.tiletype){
        case TALLGRASS:
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle(this->originX, this->originY, this->sizeX, this->sizeY);
            draw_tall_grass_quarter(this->originX, this->originY);
            draw_tall_grass_quarter(this->originX+8, this->originY);
            draw_tall_grass_quarter(this->originX, this->originY+8);
            draw_tall_grass_quarter(this->originX+8, this->originY+8);
            can_down = true; can_left = true; can_right = true; can_up = true;
            break;
        case PATH:
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle(this->originX, this->originY, this->sizeX, this->sizeY);
            draw_two_path_rect(this->originX+2, originY+1);
            draw_two_path_rect(this->originX+6, originY+2);
            draw_two_path_rect(this->originX+10, originY+1);
            draw_two_path_rect(this->originX+3, originY+5);
            draw_two_path_rect(this->originX+11, originY+5);
            draw_two_path_rect(this->originX+2, originY+9);
            draw_two_path_rect(this->originX+6, originY+10);
            draw_two_path_rect(this->originX+10, originY+9);
            draw_two_path_rect(this->originX+3, originY+13);
            draw_two_path_rect(this->originX+11, originY+13);
            can_down = true; can_left = true; can_right = true; can_up = true;
            break;
        case NORMAL:
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle(this->originX, this->originY, this->sizeX, this->sizeY);
            can_down = true; can_left = true; can_right = true; can_up = true;
            break;
        case BAR:
            draw_bar(this->originX, this->originY);
            can_down = false; can_left = false; can_right = false; can_up = false;
            break;
        case ROCK:
            draw_rock(this->originX, this->originY);
            can_down = false; can_left = false; can_right = false; can_up = false;
            break;
        case STAIRS:
            draw_stairs(this->originX, this->originY);
            can_down = true; can_left = false; can_right = false; can_up = true;
            break;
        case JUMPABLE:
            draw_jumpable(this->originX, this->originY);
            can_down = true; can_left = false; can_right = false; can_up = false;
            break;
        case GREEN1:
            draw_green(this->originX, this->originY);
            can_down = true; can_left = true; can_right = true; can_up = true;
            break;
        case GRAVEL:
            draw_gravel(this->originX, this->originY);
            can_down = true; can_left = true; can_right = true; can_up = true;
            break;
    }
}

void Tile::set_texture(Texture texture) {
    this->texture = texture;
    draw_tile();
}

void Tile::onPlayerEnter() {
    srand(time(NULL));
    int upper = 100;
    int lower = 0;
    int number = (rand() % (upper - lower + 1)) + lower;
    if(number < texture.encounterRate){
        //Encounter
    }
}

void Tile::onPlayerExit() {
    draw_tile();
}

void Tile::draw_two_path_rect(int originX, int originY) {
    LCD.SetFontColor(0xA8A8A8);
    LCD.DrawPixel(originX, originY);
    LCD.DrawPixel(originX, originY+1);
    LCD.DrawPixel(originX + 2, originY);
    LCD.DrawPixel(originX + 2, originY + 1);
}

void Tile::draw_tall_grass_quarter(int originX, int originY) {
    LCD.SetFontColor(0xA8A8A8);
    LCD.DrawPixel(originX, originY+2);
    LCD.DrawPixel(originX, originY+3);
    LCD.DrawPixel(originX, originY+4);
    LCD.DrawPixel(originX+1, originY+5);
    LCD.DrawPixel(originX+2, originY+6);
    LCD.DrawPixel(originX+3, originY+7);
    LCD.DrawPixel(originX+4, originY+7);
    LCD.DrawPixel(originX+4, originY+6);
    LCD.DrawPixel(originX+5, originY+6);
    LCD.DrawPixel(originX+4, originY+5);
    LCD.DrawPixel(originX+5, originY+5);
    LCD.DrawPixel(originX+5, originY+4);
    LCD.DrawPixel(originX+4, originY+4);
    LCD.DrawPixel(originX+3, originY+4);
    LCD.DrawPixel(originX+2, originY+3);
    LCD.DrawPixel(originX+1, originY+2);
    LCD.DrawPixel(originX+4, originY+3);
    LCD.DrawPixel(originX+4, originY+2);
    LCD.DrawPixel(originX+5, originY+1);
    LCD.DrawPixel(originX+6, originY);
    LCD.DrawPixel(originX+7, originY+1);
    LCD.DrawPixel(originX+7, originY+2);
    LCD.DrawPixel(originX+6, originY+3);
    LCD.DrawPixel(originX+6, originY+4);

    LCD.SetFontColor(0xD0D0D0);
    LCD.DrawPixel(originX, originY+6);
    LCD.DrawPixel(originX+1, originY+6);
    LCD.DrawPixel(originX+1, originY+7);
    LCD.DrawPixel(originX+2, originY+7);
    LCD.DrawPixel(originX+2, originY+4);
    LCD.DrawPixel(originX+3, originY+5);
    LCD.DrawPixel(originX+3, originY+6);
    LCD.DrawPixel(originX+5, originY+7);
    LCD.DrawPixel(originX+6, originY+5);
    LCD.DrawPixel(originX+5, originY+3);
    LCD.DrawPixel(originX+5, originY+2);
    LCD.DrawPixel(originX+6, originY+2);
    LCD.DrawPixel(originX+7, originY);
    LCD.DrawPixel(originX+7, originY+3);

}

void Tile::draw_bar(int originX, int originY) {
    //0 = 040204
    //1 = acaaac
    //2 = 646264
    //3 = fcfafc


    //i = height //j = width
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = this->bar[j + (i*16)];
            switch (pixel) {
                case 0:
                    LCD.SetFontColor(0x040204);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    LCD.SetFontColor(0xacaaac);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 2:
                    LCD.SetFontColor(0x646264);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 3:
                    LCD.SetFontColor(0xfcfafc);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                default:
                    LCD.SetFontColor(0xffffff);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }

}

void Tile::draw_rock(int originX, int originY) {
    //0 = 14121c
    //1 = acaaac
    //2 = 646264
    //3 = fceafc

    //i = height //j = width
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = this->rock[j + (i*16)];
            switch (pixel) {
                case 0:
                    LCD.SetFontColor(0x14121c);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    LCD.SetFontColor(0xacaaac);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 2:
                    LCD.SetFontColor(0x646264);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 3:
                    LCD.SetFontColor(0xfceafc);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                default:
                    LCD.SetFontColor(0xffffff);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }

}

void Tile::draw_stairs(int originX, int originY) {
    //0 = 646264
    //1 = fcfafc
    //2 = acaaac

    //i = height //j = width
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = this->stairs[j + (i*16)];
            switch (pixel) {
                case 0:
                    LCD.SetFontColor(0x646264);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    LCD.SetFontColor(0xfcfafc);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 2:
                    LCD.SetFontColor(0xacaaac);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                default:
                    LCD.SetFontColor(0xffffff);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }
}
void Tile::draw_jumpable(int originX, int originY) {
    //0 = 040204
    //1 = acaaac
    //2 = 646264
    //3 = fcfafc

    //i = height //j = width
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = this->jumpable[j + (i*16)];
            switch (pixel) {
                case 0:
                    LCD.SetFontColor(0x040204);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    LCD.SetFontColor(0xacaaac);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 2:
                    LCD.SetFontColor(0x646264);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 3:
                    LCD.SetFontColor(0xfcfafc);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                default:
                    LCD.SetFontColor(0xffffff);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }
}

void Tile::draw_green(int originX, int originY) {
    //0 = 54966c
    //1 = fcfafc
    //2 = acaaac


    //i = height //j = width
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = this->green[j + (i*16)];
            switch (pixel) {
                case 0:
                    LCD.SetFontColor(0x54966c);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    LCD.SetFontColor(0xfcfafc);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 2:
                    LCD.SetFontColor(0xacaaac);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                default:
                    LCD.SetFontColor(0xffffff);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }
}

void Tile::draw_gravel(int originX, int originY) {
    //0 = fcfafc
    //1 = acaaac

    //i = height //j = width
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int pixel = this->gravel[j + (i*16)];
            switch (pixel) {
                case 0:
                    LCD.SetFontColor(0xfcfafc);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                case 1:
                    LCD.SetFontColor(0xacaaac);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
                default:
                    LCD.SetFontColor(0xffffff);
                    LCD.DrawPixel(this->originX + j, this->originY + i);
                    break;
            }
        }
    }
}

