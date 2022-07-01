#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;

#include "funciones_cerdo.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    srand (time(NULL));
    int pdvTotal[2]={};
    string jugadores[2];
    bool continuar = true;
    while(continuar){
    cargarMenu(jugadores, pdvTotal);
    system("cls");
    }

}

