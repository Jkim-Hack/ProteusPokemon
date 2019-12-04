#include <iostream>
#include "Libraries/FEHLCD.h"
#include "Player/Player.h"
#include "Util/PixelLCDConvert.h"
#include "Libraries/FEHUtility.h"
#include "Libraries/FEHSD.h"
#include "Music/Music.cpp"

//Instantiate global variables
int pokemon_captured = 0;
int pokemon_defeated = 0;
int your_losses = 0;

//Instantiate void functions
void playIntro();
void LoadStats();
void displayMenu();
void newStats();
void ShowInstructions();

//Shows the copyright and intro
void playIntro() {
    PixelLCDConvert plc(160);
    plc.pixelarr_to_lcd("c.txt", COPYRIGHT);
    Sleep(2000);
    plc.pixelarr_to_lcd("i.txt", INTRO);
    //Music
}

//Loads all the stats into global variables
void LoadStats() {

    //The count aka the row
    int count = 0;
    int line; //The line of the row
    char filename[] = "s.txt"; //The file name
    //Load into the global variables from the file
    while(SD.fscanf(filename, count, "%i", line) != EOF) {
        switch (count) {
            case 0:
                pokemon_captured = line;
                break;
            case 1:
                pokemon_defeated = line;
                break;
            case 2:
                your_losses = line;
                break;
        }
        count++;
    }
    //Clear, and clear buffer
    LCD.Clear();
    LCD.CLearBuffer();

    //Print the stats onto the screen
    LCD.WriteLine("Pokemon captured: "); LCD.Write(pokemon_captured);
    LCD.WriteLine("Pokemon defeated: "); LCD.Write(pokemon_defeated);
    LCD.WriteLine("Your defeats: "); LCD.Write(your_losses);
    Sleep(5000); //Wait for 5 seconds
    //Go back to displaying the menu
    displayMenu();
}

void displayMenu(){

    //Clears the buffer and anything on screen
    LCD.Clear();
    LCD.CLearBuffer();

    //Set a button for the continue button
    FEHIcon::Icon cont_button;
    cont_button.SetProperties("BUTTON", 120, 10, 80, 40, SCARLET, GRAY);
    cont_button.ChangeLabelString("CONTINUE");
    cont_button.Draw();

    //Set a button for the new game button
    FEHIcon::Icon new_button;
    new_button.SetProperties("BUTTON", 120, 60, 80, 40, SCARLET, GRAY);
    new_button.ChangeLabelString("NEW GAME");
    new_button.Draw();

    //Set a button for the show stats button
    FEHIcon::Icon stats_button;
    stats_button.SetProperties("BUTTON", 120, 110, 80, 40, SCARLET, GRAY);
    stats_button.ChangeLabelString("SHOW STATS");
    stats_button.Draw();

    //Set a button for the show stats button
    FEHIcon::Icon instructions_button;
    stats_button.SetProperties("BUTTON", 120, 150, 80, 40, SCARLET, GRAY);
    stats_button.ChangeLabelString("INSTRUCTIONS");
    stats_button.Draw();

    float x, y;
    while(true) { //While loop
        LCD.Touch(&x, &y); //Get the touch x, y positions
        if(cont_button.Pressed(x,y,0)) { //On continue pressed, break the loop //Also if else ladder
            break;
        } else if(new_button.Pressed(x, y, 0)) { //On new game button pressed, write new stats and break the loop.
            newStats();
            break;
        } else if(stats_button.Pressed(x, y, 0)) { //On stats button pressed, load the stats and show to screen.
            LoadStats();
            break;
        } else if(instructions_button.Pressed(x,y,0)){
            ShowInstructions();
            break;
        }
    }

    Music music();
    do { //do while
        Music::playRoute1();
    } while(true);

}

void newStats() {
    //Writes to the s.txt file with 0s to simulate a new game.
    FEHFile *fptr = SD.FOpen("s.txt","w");

    SD.FPrintf(fptr, "%i\n", 0);
    SD.FPrintf(fptr, "%i\n", 0);
    SD.FPrintf(fptr, "%i\n", 0);
    //Close the file
    SD.FClose(fptr);
}

void ShowInstructions() {
    //Clear, and clear buffer
    LCD.Clear();
    LCD.CLearBuffer();

    //Print the instructions onto the screen
    LCD.WriteLine("Use the left side of the screen to move left.");
    LCD.WriteLine("Use the right side of the screen to move right.");
    LCD.WriteLine("Use the bottom center of the screen to move down.");
    LCD.WriteLine("Use the top center of the screen to move up.");
    LCD.WriteLine("All buttons will be shown that shows instructions.");

    Sleep(7000); //Wait for 7 seconds
    //Go back to displaying the menu
    displayMenu();
}

int main()
{
    //Set background color to kind of white
    LCD.SetBackgroundColor(0xF8F8F8);

    //Clear buffers
    LCD.Clear();
    LCD.ClearBuffer();

    //Play the intro
    playIntro();
    //Display the menu
    displayMenu();

    //Clear buffer and set background
    LCD.SetBackgroundColor(0xF8F8F8);
    LCD.Clear();
    LCD.ClearBuffer();

    //Create the player on the center of the screen
    Player player;

    float x, y;
    while (true)
    {
        LCD.Touch(&x,&y); //Set touch of x and y positions
        if (x < 106) { //On left side of screen touched, move player left
            player.move_left();
        } else if (x > 212) { //On right side of screen touched, move player right
            player.move_right();
        } else if (x > 106 && x < 212 && y < 120) { //On bottom center of screen touched, move player down
            player.move_down();
        } else if (x > 106 && x < 212 && y > 120) { //On top center of screen touched, move player up
            player.move_up();
        }
    }
}

