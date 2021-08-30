#pragma once
#include "include.h"

using std::ios; using std::fstream;

class cityClass; 
class roadClass;
typedef cityClass* city;
typedef roadClass* road;

class cityClass {
public:
    int id = 0;// id de la ciudad
    string name = "";// nombre de la ciudad
    city sig = NULL;// apunta al nodo siguiente
    city ant = NULL;// apunta al nodo anterior
    road start = NULL;
    road end = NULL;
    city searchCity(string city);
    void addNewCity(city& worldStart, city& worldEnd, string cityName);
    void addNewRoad(city world, string name);
};

class  roadClass{
public:
    int idDestiny = 0;// id del destino
    string destiny = "";// valor campoN?
    roadClass* sig = NULL;// apunta al nodo siguiente
    roadClass* ant = NULL;// apunta al nodo anterior
};


city cityClass::searchCity(string cityName) { // verifica segun (i % n) en que lista de la tabla va
    while (this != NULL) {
        if (name == cityName) {//verifica si el valor de la tabla  
            return this;// regresa el nodo de la tabla que contiene el inicio de la lista que corresponde a h
        }else return sig->searchCity(cityName);
    }
};
void cityClass::addNewRoad(city world, string destiny) { //ingresa un valor nuevo al la lista de caminos
    road z = new(roadClass);
    z->idDestiny = (int)world->id;
    z->destiny = (string)destiny;
    if (start != NULL) {
        z->ant = end;
        end->sig = z;
    }
    else {
        z->ant = NULL;
        start = z;
    }
    end = z;
};

void cityClass::addNewCity(city& worldStart, city& worldEnd, string cityName) { //ingresa un valor nuevo al la lista
    //ingreso de un nodo nuevo a la lista
    city z = new(cityClass);
    z->name = cityName;
    if (worldStart != NULL) {
        z->id = (int)worldEnd->id + 1;
        worldEnd->sig = z;
        z->ant = worldEnd;
    }
    else {
        z->id = 0;
        z->ant = NULL;
        worldStart = z;
    }
    worldEnd = z;
};
void readCitys(string fileName, city worldStart, city worldEnd) {// lee un archivo .txt y lo ingresa en memoria dinamica
    fstream file;// sirve para abrir el archivo
    string cod;// variable temporal para valor de texto que se obtiene del archivo
    file.open(fileName + "txt", ios::in);// intenta abrir el archivo .txt
    if (file.fail()) {// si el archivo falla al abrir
        cout << "error abriendo el archivo " << fileName << "\n";
        pause();
    }
    else {
            while (!file.eof()) {// mientras que el archivo no este en el final
                file >> cod;// lee los datos del archivo
                worldEnd->addNewCity(worldStart,worldEnd,cod);// verifica en que parte de la tabla va
                
            }
        file.close();// cierra el archivo
    }
};
void readRoads(string fileName,city world) {// lee un archivo .txt y lo ingresa en memoria dinamica
    fstream file;// sirve para abrir el archivo
    city cursor;// varible temporal para la creacion de la tabla
    string readed;// variable temporal para valor de texto que se obtiene del archivo
    file.open(fileName + "txt", ios::in);// intenta abrir el archivo .txt
    if (file.fail()) {// si el archivo falla al abrir
        cout << "error abriendo el archivo " << fileName << "\n";
        pause();
    }
    else {
            while (!file.eof()) {// mientras que el archivo no este en el final
                file >> readed;// lee los datos del archivo
                cursor = world->searchCity(readed);
                do {
                    file >> readed;// lee los datos del archivo
                    cursor->addNewRoad(world->searchCity(readed),readed);
                } while (readed != "\n");
            }
        }
        file.close();// cierra el archivo
};