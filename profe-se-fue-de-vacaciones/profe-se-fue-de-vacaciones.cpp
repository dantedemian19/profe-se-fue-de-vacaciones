#include "graphos.h"
#include "includeMenu.h"

void menuMain() {
    const int options = 4;
    menuVars menuv;
    city worldStart;
    city worldEnd;
    readCitys("cities", worldStart, worldEnd);
    readRoads("roads", worldStart);
    string menuText[options + 1] = {
        "start",
        "ver ciudades",
        "ver rutas desde una ciudad",
        "ver ruta entre dos ciudades",
        "end"
    };
    menuv.declare(options, 0, "Programa graphos");
    menuv.menu(menuText);
    switch (menuv.w)
    {
    case 1:

        pause();
        break;
    case 2:

        pause();
        break;
    case 3:

        pause();
        break;
    default:
        if (menuv.w == menuv.exit) pause();
        else errormens();
        break;
    }
};

int main()
{
    menuMain();
};

