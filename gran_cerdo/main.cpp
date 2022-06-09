#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

#include "funciones_cerdo.h"

int main()
{
    setlocale(LC_ALL, "Spanish");

    cout << "GRAN CERDO" << endl;
    cout << "--------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CERDITOS" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;

    /*DECLARACION DE VARIABLES */
    srand (time(NULL));
    int opcMenuPrin;
    const int CANT_JUGADORES=2;
    string jugadores[CANT_JUGADORES];

    /* INICIO DEL MENU PRINCIPAL */

    cout << "Ingrese una opción: ";
    cin >> opcMenuPrin;

    while(!(opcMenuPrin==1||opcMenuPrin==2||opcMenuPrin==3||opcMenuPrin==0)){
        cout << "El número ingresado es inválido por favor ingreselo nuevamente: ";
        cin >> opcMenuPrin;

    }
    switch(opcMenuPrin){
        case 1:
            cargarJugadores(jugadores, CANT_JUGADORES);
            cout << jugadores[0] << "-----" << jugadores[1];

        break;
        case 2:
            cout << "Eligio 2";
        break;
        case 3:
            cout << "Eligio 3";
        break;
        case 0:
            exit(0);
        break;

    }
    /*int dados [3] = {};
    int sumaDados;
    int cantDados = 2;
    for(int i=0; i<cantDados; i++){
        dados[i] = generarDado();
        sumaDados+=dados[i];
        cout<<dados[i]<< endl;
    }*/
}


