//
// Created by johnk on 11/30/2019.
//

#include <cstdio>
#include <stdio.h>
#include <string>
#include "PixelLCDConvert.h"
#include "../Libraries/FEHSD.h"
#include "../Libraries/FEHLCD.h"

PixelLCDConvert::PixelLCDConvert(int sizeX) {
    this->sizeX = sizeX;
}

void PixelLCDConvert::pixelarr_to_lcd(char filename[], SCREENTYPE type) {
    //If the type is copyright then the copyright will show, if intro, intro will show
    switch (type) {
        case COPYRIGHT:
            //0 = 040204
            //1 = dca294
            //2 = fcfefc
            //3 = acaaac
            addToMapCopyright(filename);
            break;
        case INTRO:
            //0 = 040204
            //1 = acaaac
            //2 = 2402ac
            //3 = fcfefc
            //4 = c4b2e4
            //5 = 646264
            addToMapIntro(filename);
            break;
    }
}

void PixelLCDConvert::addToMapIntro(char filename[]) {

    //Get the line
    char line[this->sizeX * 2 + 1];
    int count = 0; //Get the row count
    int j = 0; //Get the x column count
    while(SD.fscanf(filename, count, "%s", line) != EOF) {
        for (int i = 0; i < sizeX*2 + 1; ++i) {
            if(i % 2 == 0){
                int elem = line[i]; //Get the pixel number
                //Display based on number
                switch (elem){
                    case 0:
                        LCD.SetFontColor(0x040204);
                        LCD.DrawPixel(j, count);
                        break;
                    case 1:
                        LCD.SetFontColor(0xACAAAC);
                        LCD.DrawPixel(j,count);
                        break;
                    case 2:
                        LCD.SetFontColor(0x2402AC);
                        LCD.DrawPixel(j,count);
                        break;
                    case 3:
                        LCD.SetFontColor(0xFCFEFC);
                        LCD.DrawPixel(j,count);
                        break;
                    case 4:
                        LCD.SetFontColor(0xC4B2E4);
                        LCD.DrawPixel(j,count);
                        break;
                    case 5:
                        LCD.SetFontColor(0x646264);
                        LCD.DrawPixel(j,count);
                        break;
                    default:
                        break;
                }
                j++;
            }
        }
        count++;
    }
}

void PixelLCDConvert::addToMapCopyright(char filename[]) {

    //Get the line
    char line[this->sizeX * 2 + 1];
    int count = 0; //Row count y
    int j = 0; //Column count x
    while(SD.fscanf(filename, count, "%s", line) != EOF) {
        for (int i = 0; i < sizeX*2 + 1; ++i) {
            if(i % 2 == 0){
                int elem = line[i]; //Get the pixel int
                //Display based on number
                switch (elem){
                    case 0:
                        LCD.SetFontColor(0x040204);
                        LCD.DrawPixel(j, count);
                        break;
                    case 1:
                        LCD.SetFontColor(0xDCA294);
                        LCD.DrawPixel(j,count);
                        break;
                    case 2:
                        LCD.SetFontColor(0xFCFEFC);
                        LCD.DrawPixel(j,count);
                        break;
                    case 3:
                        LCD.SetFontColor(0xACAAAC);
                        LCD.DrawPixel(j,count);
                        break;
                    default:
                        break;
                }
                j++;
            }
        }
        count++;
    }
}
