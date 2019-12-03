#include <iostream>
#include "Libraries/FEHLCD.h"
#include "Player/Player.h"

int main()
{
    FEHIcon::Icon top_button;
    top_button.SetProperties("BUTTON", 0, 150, 30, 30, GRAY, GRAY);
    top_button.ChangeLabelString("UP");
    top_button.Draw();
    FEHIcon::Icon bot_button;
    bot_button.SetProperties("BUTTON", 0, 210, 30, 30, GRAY, GRAY);
    bot_button.ChangeLabelString("DOWN");
    bot_button.Draw();
    FEHIcon::Icon right_button;
    right_button.SetProperties("BUTTON", 30, 170, 30, 30, GRAY, GRAY);
    right_button.ChangeLabelString("RIGHT");
    right_button.Draw();
    FEHIcon::Icon left_button;
    left_button.SetProperties("BUTTON", 30, 170, 30, 30, GRAY, GRAY);
    left_button.ChangeLabelString("LEFT");
    left_button.Draw();

    FEHIcon::Icon A_button;
    A_button.SetProperties("BUTTON", 270, 170, 30, 30, GRAY, GRAY);
    A_button.ChangeLabelString("A");
    A_button.Draw();

    FEHIcon::Icon B_button;
    B_button.SetProperties("BUTTON", 310, 170, 30, 30, GRAY, GRAY);
    B_button.ChangeLabelString("B");
    B_button.Draw();

    Player player;

    float x, y;
    while (true)
    {
        LCD.Touch(&x,&y);
        if (top_button.Pressed(x,y,0)) {
            player.move_up();
        } else if (bot_button.Pressed(x,y,0)) {
            player.move_down();
        } else if (left_button.Pressed(x,y,0)) {
            player.move_left();
        } else if (right_button.Pressed(x,y,0)) {
            player.move_right();
        }
    }

    return 0;
}