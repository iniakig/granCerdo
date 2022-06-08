#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

#include "funciones_cerdo.h"
//void cargarJugadores(string vec[], int cant); // DECLARACION DE FUNCION PARA INGRESAR EL NOMBRE DE LOS JUGADORES -- se le pasa por parametro el vector de jugadores y la cantidad

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

    /*DECLARACION DE VARIABLES GLOBALES*/
    srand (time(NULL));
    int opcMenuPrin;
    const int CANT_JUGADORES=2;
    string nombreJug1, nombreJug2;
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
            cout << "Ingrese el nombre del jugador 1:" << endl;
            cin >> nombreJug1;
            cout << "Ingrese el nombre del jugador 2:" << endl;
            cin >> nombreJug2;
            cout << "HOla mundo"
            //cargarJugadores(jugadores, CANT_JUGADORES);
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

    return 0;
}

/*void cargarJugadores(string vec[], int cant){
    int i;
    for(i=0; i<cant; i++){
        cout << "Ingrese el nombre del jugador " << i+1<< endl;
        cin >> vec[i];
    }
}*/
