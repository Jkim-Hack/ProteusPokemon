//
// Created by johnk on 11/26/2019.
//

#include "../Libraries/FEHBuzzer.h"
using namespace FEHBuzzer;

class IntroMusic {

public:
    static void playIntro();

};

void IntroMusic::playIntro() {
    Buzzer.Tone(FEHBuzzer::G2, 113);
    Buzzer.Tone(FEHBuzzer::B3, 113);
    Buzzer.Tone(FEHBuzzer::D3, 113);
    Buzzer.Tone(FEHBuzzer::Fs3, 113);
    Buzzer.Tone(FEHBuzzer::G3, 451);
    Buzzer.Tone(FEHBuzzer::G3, 451);
    Sleep(226);
    Buzzer.Tone(FEHBuzzer::G3, 113);
    Buzzer.Tone(FEHBuzzer::G3, 113);
    Buzzer.Tone(FEHBuzzer::G3, 451);
    Buzzer.Tone(FEHBuzzer::G3, 451);
    Buzzer.Tone(FEHBuzzer::F3, 200);
    Buzzer.Tone(FEHBuzzer::F3, 200);
    Buzzer.Tone(FEHBuzzer::F3, 200);
    Buzzer.Tone(FEHBuzzer::F3, 200);
    Buzzer.Tone(FEHBuzzer::F3, 200);
    Buzzer.Tone(FEHBuzzer::Fs3, 200);
    Buzzer.Tone(FEHBuzzer::G3, 677);
    Buzzer.Tone(FEHBuzzer::B4, 226);
    Buzzer.Tone(FEHBuzzer::D4, 902);
    Sleep(902);
    Buzzer.Tone(FEHBuzzer::F4, 677);
    Buzzer.Tone(FEHBuzzer::E4, 113);
    Buzzer.Tone(FEHBuzzer::Ds4, 113);
    Buzzer.Tone(FEHBuzzer::D4, 902);
}