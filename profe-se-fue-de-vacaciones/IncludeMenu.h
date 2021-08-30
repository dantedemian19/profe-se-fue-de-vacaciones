#pragma once
#include <conio.h>
#include "consoleComands.h"
#include "include.h"

// keyboard id's
#define space 32
#define up 72
#define down 80
#define entr 13
#define esc 27
#define back 8

class menuVars {
public:
    string name = "";
    int w = 1;
    int exit = 0, program = 0;
    bool enter = false;
    string namef = "";
    void detection();
    void menu(string menuText[]);
    void declare(int numberOfOptions, int numberProgram, string nameOfMenu);
};

void menuVars::detection() { // mueve el cursor dependiendo la decision del usuario
    int c = 0;
    while (c != 's' && c != 'w' && c != 'f' && c != entr && c != up && c != down && c != esc && c != back) {
        c = _getch();
    }
    if (c == 'w' || c == up) {// if the user press up or W
        if (w > 1) {
            w = w - 1;
        }
        else {
            w = exit;
        }
    }
    if (c == 's' || c == down) {// if the user press down or S
        if (w < exit) {
            w = w + 1;
        }
        else {
            w = 1;
        }
    }
    if (c == 'f' || c == entr) {// if the user press enter or F
        enter = !enter;
    }
    if (c == back || c == esc) {// if the user press DELETE or ESC
        w = exit;
        enter = !enter;
    }
};
void menuVars::menu(string menuText[]) {
    while (w != exit) { // its a easy menu
        enter = false;
        while (!enter) {
            cls();//cursor appears only in selected option 
            cout << "  " << name << "  \n";
            for (int i = 1; i <= exit; i += 1) {
                if (i != exit) {
                    if (w == i) { cout << "  >>"; } cout << "\t" << menuText[i] << "\n";
                }
                else { if (w == i) { cout << "  >>"; } cout << "\t" << "volver" << "\n"; }
            }
            //detection of the cursor
            detection();
            //detection of the cursor
        }
    }
};

void menuVars::declare(int numberOfOptions, int numberProgram, string nameOfMenu) {
    exit    = numberOfOptions;
    program = numberProgram;
    name    = nameOfMenu;
};