//
// Created by johnk on 11/22/2019.
//

#include "Tile.h"
#include "../Libraries/FEHLCD.h"

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

void Tile::draw_tile() {
    if(this->texture.tiletype == TALLGRASS){
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(this->originX, this->originY, this->sizeX, this->sizeY);
        draw_tall_grass_quarter(this->originX, this->originY);
        draw_tall_grass_quarter(this->originX+8, this->originY);
        draw_tall_grass_quarter(this->originX, this->originY+8);
        draw_tall_grass_quarter(this->originX+8, this->originY+8);
    } else if (this->texture.tiletype == PATH) {
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
    } else if (this->texture.tiletype == NORMAL){
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(this->originX, this->originY, this->sizeX, this->sizeY);
    }
}

void Tile::set_texture(Texture texture) {
    this->texture = texture;
    draw_tile();
}

void Tile::onPlayerEnter(Player *player) {
    this->player = player;
    set_texture(player->playerTexture);
}

void Tile::onPlayerExit() {
    this->player = nullptr;
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



