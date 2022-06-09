#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h> /* para funcion time*/
using namespace std;

#include "funciones_cerdo.h"

int generarDado(){
    int num;
    num = rand() % 6+1;
    return num;
}

void cargarJugadores(string arr[], int cant){
            string nombresJugadores[cant];
            int matDados [cant][2];
            int maxTiro = 0;
            int jugMaxPos;
            int bandEmpate = 0;
            for(int i=0; i<cant; i++){
                cout << "Ingrese el nombre del jugador" << i+1 << " " << endl;
                //cin.ignore();
                cin >> nombresJugadores[i];
                //cin.ignore();
            }
            for(int i=0; i<cant; i++){
                cout << nombresJugadores[i] << " presione ENTER para tirar sus dados" << endl;
                //cin.get();
                int sumaTiro;
                for(int j=0; j<2; j++){
                    matDados[i][j] = generarDado();
                    cout<<matDados[i][j]<<endl;
                    sumaTiro += matDados[i][j];
                }
                if(sumaTiro>maxTiro){
                    maxTiro = sumaTiro;
                    jugMaxPos = i;
                }
                cout << "Su tiro suma "<< sumaTiro << endl;
                cout << "-----------------------------"<< endl;
            }
            cout << "Empieza el juego tirando: " << nombresJugadores[jugMaxPos]<< endl;

            /*nombreJug1, nombreJug2;
            cout << "Ingrese el nombre del jugador 1:" << endl;
            cout << "Ingrese el nombre del jugador 2:" << endl;
            getline(cin, nombreJug2);
            for(int i=0; i<cant; i++){

            }*/
            /*cout << "Presiona ENTER para tirar el dado"<< endl;
            cin <<*/

}


