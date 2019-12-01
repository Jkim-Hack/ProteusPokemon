//
// Created by johnk on 11/26/2019.
//

#include "../Libraries/FEHBuzzer.h"
#include "../Libraries/FEHUtility.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
class Music {

public:
    static void playIntro();
    static void playRoute1();
};

void Music::playIntro() {
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

void Music::playRoute1() {

    int s = 125;
    int e = 250;
    int q = 500;
    int h = 1000;
    int w = 2000;

    while(true) {
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);

        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);

        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::G5, (int)(e*1.5));
        Buzzer.Tone(FEHBuzzer::Fs5, s);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::A5, e);
        Buzzer.Tone(FEHBuzzer::A5, e);
        Buzzer.Tone(FEHBuzzer::Cs5, s);
        Buzzer.Tone(FEHBuzzer::D5, s);

        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::Cs5, s);
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::Cs5, s);
        Buzzer.Tone(FEHBuzzer::D5, s);

        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);
        Buzzer.Tone(FEHBuzzer::Fs5, s);
        Buzzer.Tone(FEHBuzzer::D5, e);
        Buzzer.Tone(FEHBuzzer::A5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);

        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, s);
        Buzzer.Tone(FEHBuzzer::E5, s);

        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::G5, (int)(e*1.5));
        Buzzer.Tone(FEHBuzzer::Fs5, s);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::A5, e);
        Buzzer.Tone(FEHBuzzer::A5, e);
        Buzzer.Tone(FEHBuzzer::Cs5, s);
        Buzzer.Tone(FEHBuzzer::D5, s);

        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::G5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::E5, e);
        Buzzer.Tone(FEHBuzzer::D5, e);
        Buzzer.Tone(FEHBuzzer::Cs5, e);
        Buzzer.Tone(FEHBuzzer::B5, e);
        Buzzer.Tone(FEHBuzzer::Cs5, e);

        Buzzer.Tone(FEHBuzzer::A6, q);
        Buzzer.Tone(FEHBuzzer::E5, q);
        Buzzer.Tone(FEHBuzzer::Fs5, (int)(q*1.5));
        Buzzer.Tone(FEHBuzzer::E5, s);
        Buzzer.Tone(FEHBuzzer::Fs5, s);

        Buzzer.Tone(FEHBuzzer::A6, e);
        Buzzer.Tone(FEHBuzzer::A6, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, e);
        Buzzer.Tone(FEHBuzzer::D6, e);
        Buzzer.Tone(FEHBuzzer::Cs6, e);
        Buzzer.Tone(FEHBuzzer::B5, e);
        Buzzer.Tone(FEHBuzzer::Cs6, e);

        Buzzer.Tone(FEHBuzzer::A6, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::E5, (int)(q*1.5));
        Buzzer.Tone(FEHBuzzer::E5, s);
        Buzzer.Tone(FEHBuzzer::Fs5, s);

        Buzzer.Tone(FEHBuzzer::A6, e);
        Buzzer.Tone(FEHBuzzer::A6, e);
        Buzzer.Tone(FEHBuzzer::Fs5, e);
        Buzzer.Tone(FEHBuzzer::D5, e);
        Buzzer.Tone(FEHBuzzer::D6, e);
        Buzzer.Tone(FEHBuzzer::Cs6, e);
        Buzzer.Tone(FEHBuzzer::B5, e);
        Buzzer.Tone(FEHBuzzer::Fs5, s);
        Buzzer.Tone(FEHBuzzer::G5, s);

        Buzzer.Tone(FEHBuzzer::A6, e);
        Buzzer.Tone(FEHBuzzer::D6, e);
        Buzzer.Tone(FEHBuzzer::Cs6, e);
        Buzzer.Tone(FEHBuzzer::E6, e);
        Buzzer.Tone(FEHBuzzer::D6, e);
        Buzzer.Tone(FEHBuzzer::D6, e);
        Buzzer.Tone(FEHBuzzer::D6, e);
    }


}

#pragma clang diagnostic pop