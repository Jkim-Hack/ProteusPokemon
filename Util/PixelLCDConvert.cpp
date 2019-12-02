//
// Created by johnk on 11/30/2019.
//

#include <cstdio>
#include <stdio.h>
#include <string>
#include "PixelLCDConvert.h"
#include "../Libraries/FEHSD.h"
#include "../Libraries/FEHLCD.h"

PixelLCDConvert::PixelLCDConvert(int sizeX, int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    for (int i = 0; i < this->sizeY; ++i) {
        map[i] = (int*)malloc(this->sizeX* sizeof(int));
    }
}

void PixelLCDConvert::pixelarr_to_lcd(char filename[], SCREENTYPE type) {
    addToMap(filename);
    switch (type) {
        case COPYRIGHT:
            //0 = 040204
            //1 = dca294
            //2 = fcfefc
            //3 = acaaac
            for (int r = 0; r < this->sizeY; ++r) {
                for (int c = 0; c < this->sizeX; ++c) {
                    int elem = map[r][c];
                    switch (elem){
                        case 0:
                            LCD.SetFontColor(0x040204);
                            LCD.DrawPixel(c, r);
                            break;
                        case 1:
                            LCD.SetFontColor(0xDCA294);
                            LCD.DrawPixel(c,r);
                            break;
                        case 2:
                            LCD.SetFontColor(0xFCFEFC);
                            LCD.DrawPixel(c,r);
                            break;
                        case 3:
                            LCD.SetFontColor(0xACAAAC);
                            LCD.DrawPixel(c,r);
                            break;
                        default:
                            LCD.SetFontColor(BLACK);
                            LCD.DrawPixel(c, r);
                            break;
                    }
                }
            }
            break;
        case INTRO:
            //0 = 040204
            //1 = acaaac
            //2 = 2402ac
            //3 = fcfefc
            //4 = c4b2e4
            //5 = 646264
            for (int r = 0; r < this->sizeY; ++r) {
                for (int c = 0; c < this->sizeX; ++c) {
                    int elem = map[r][c];
                    switch (elem){
                        case 0:
                            LCD.SetFontColor(0x040204);
                            LCD.DrawPixel(c, r);
                            break;
                        case 1:
                            LCD.SetFontColor(0xACAAAC);
                            LCD.DrawPixel(c,r);
                            break;
                        case 2:
                            LCD.SetFontColor(0x2402AC);
                            LCD.DrawPixel(c,r);
                            break;
                        case 3:
                            LCD.SetFontColor(0xFCFEFC);
                            LCD.DrawPixel(c,r);
                            break;
                        case 4:
                            LCD.SetFontColor(0xC4B2E4);
                            LCD.DrawPixel(c,r);
                            break;
                        case 5:
                            LCD.SetFontColor(0x646264);
                            LCD.DrawPixel(c,r);
                            break;
                        default:
                            LCD.SetFontColor(BLACK);
                            LCD.DrawPixel(c,r);
                            break;
                    }
                }
            }
            break;
    }
}

void PixelLCDConvert::addToMap(char filename[]) {

    char line[this->sizeX + 1];
    int count = 0;
    while(SD.fscanf(filename, count, "%s", line) != EOF) {
        getDelims(line, count);
        count++;
    }
}

void PixelLCDConvert::getDelims(char* line, int linenum) {
    char * pch;
    pch = strtok (line,", ");
    int i = 0;
    while (pch != NULL && i < sizeX)
    {
        map[linenum][i] = (int)strtol(pch, NULL, 0);
        pch = strtok (NULL, ", ");
        ++i;
    }
}