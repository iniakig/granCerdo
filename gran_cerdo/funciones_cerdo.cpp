#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h> /* para funcion time*/
#include <conio.h>
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
            int maxDado = 0;
            int acuMaxTiro = 0;
            int acuMaxDado = 0;
            int jugMaxTiroPos;
            int jugMaxDadoPos;
            int bandEmpate = 0;
            for(int i=0; i<cant; i++){
                cout << "Ingrese el nombre del jugador " << i+1 << " " << endl;
                //cin.ignore();
                cin >> nombresJugadores[i];
                //cin.ignore();
            }

            while(bandEmpate == 0){
                for(int i=0; i<cant; i++){
                    int sumaTiro=0;
                    for(int j=0; j<2; j++){
                        cout << nombresJugadores[i] << " presione una tecla para tirar el dado "<< j+1 << endl;
                        getch();
                        matDados[i][j] = generarDado();
                        cout<<matDados[i][j]<<endl;
                        sumaTiro = sumaTiro + matDados[i][j];
                        if(matDados[i][j]>maxDado){
                            maxDado = matDados[i][j];
                            jugMaxDadoPos = i;
                        }
                        if(sumaTiro>maxTiro){
                            maxTiro = sumaTiro;
                            jugMaxTiroPos = i;
                        }
                    }
                    cout << "Su tiro suma "<< sumaTiro << endl;
                    cout << "-----------------------------"<< endl;
                }

                for(int i=0; i<cant; i++){
                    int sumaDados=0;
                    for (int j=0; j<2; j++){
                        sumaDados = sumaDados + matDados[i][j];
                        if(matDados[i][j] == maxDado){
                            acuMaxDado++;
                        }
                    }
                    if(sumaDados == maxTiro){
                        acuMaxTiro++;
                    }

                }

                if(acuMaxTiro == 2 && acuMaxDado >= 2){
                    cout<<"La suma de los dados y el dado mas alto son igual, deben volver a tirar"<< endl;
                    cout << "----------------------------------"<< endl;
                }
                if(acuMaxTiro == 1){
                    if(jugMaxTiroPos==0){
                        arr[0] = nombresJugadores[0];
                        arr[1] = nombresJugadores[1];
                        bandEmpate = 1;
                    }else{
                        arr[0] = nombresJugadores[1];
                        arr[1] = nombresJugadores[0];
                        bandEmpate = 1;
                    }
                }else {
                    if(acuMaxDado == 1) {
                        if(jugMaxDadoPos==0) {
                            arr[0] = nombresJugadores[0];
                            arr[1] = nombresJugadores[1];
                            bandEmpate = 1;
                        }else{
                            arr[0] = nombresJugadores[1];
                            arr[1] = nombresJugadores[2];
                            bandEmpate = 1;
                        }
                    }
                }

            }
}


