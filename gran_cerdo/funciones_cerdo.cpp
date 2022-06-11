#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h> /* para funcion time*/
#include <conio.h>
#include <math.h>
using namespace std;

#include "funciones_cerdo.h"

void cargarMenu () {
    cout << "GRAN CERDO" << endl;
    cout << "--------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CERDITOS" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;

        /*DECLARACION DE VARIABLES */
    int opcMenuPrin;

    cout << "Ingrese una opción: ";
    cin >> opcMenuPrin;

    while(!(opcMenuPrin==1||opcMenuPrin==2||opcMenuPrin==3||opcMenuPrin==0)){
        cout << "El número ingresado es inválido por favor ingreselo nuevamente: ";
        cin >> opcMenuPrin;

    }
    switch(opcMenuPrin){
        case 1:
            jugarJuego();


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
}

void jugarJuego(){
        const int CANT_JUGADORES=2;
        const int CANT_RONDAS=5;
        const int DADOS_MAX=3;
        string jugadores[CANT_JUGADORES];
        cargarJugadores(jugadores, CANT_JUGADORES);
        cout << "Empieza jugando " << jugadores[0];
        int dadosAct = 2;
        for(int i=0; i<CANT_RONDAS; i++){
                cout<< "Ronda act "<< i+1<< endl;
            jugarRonda(jugadores, CANT_JUGADORES, DADOS_MAX, i, dadosAct);
        }
}

void mostrarJugAct(string jug[], int a){
    cout << "Jugador act "<< jug[a] <<endl;
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
                    cout << nombresJugadores[i] << " presione una tecla para tirar los dados " << endl;
                    getch();
                    matDados[i][0] = generarDado();
                    cout<<matDados[i][0]<<endl;
                    matDados[i][1] = generarDado();
                    cout<<matDados[i][1]<<endl;
                    int sumaTiro = matDados[i][0] + matDados[i][1];
                    int maxDadoAct = calcularMax(matDados[i][0], matDados[i][1]);

                    if(maxDadoAct>maxDado){
                        maxDado = maxDadoAct;
                        jugMaxDadoPos = i;
                    }

                    if(sumaTiro>maxTiro){
                        maxTiro = sumaTiro;
                        jugMaxTiroPos = i;
                    }
                    cout << "Su tiro suma "<< sumaTiro << endl;
                    cout << "-----------------------------"<< endl;
                }

                for(int i=0; i<cant; i++){
                    int sumaDados=0;
                    for (int j=0; j<2; j++){
                        sumaDados = matDados[i][0] + matDados[i][1];
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

void jugarRonda(string jugadores[],int cantJugadores, int dadosMax, int ronda, int cantDados) {
    for( int i=0; i<cantJugadores; i++){
        int trufasRonda=0;
        int bandCambioTurno = 0;
        int vecDados [dadosMax] = {};
        //while (bandCambioTurno == 0){
            cout<<"------------------------------------------"<< endl;
            cout<<"Actualmente esta jugando en la ronda "<< ronda+1<<endl;
            cout<<"------------------------------------------"<< endl;
            cout<<jugadores[i]<< " es tu turno. Presiona una tecla para tirar tus dados"<<endl;
            getch();
            tirarDados(vecDados, cantDados);
            for(int i=0; i<cantDados; i++){
                trufasRonda+=vecDados[i];
            }
            cout<<"---------------------------------"<<endl;
            cout<<"En esta ronda acumulaste "<<trufasRonda<<endl;

        //}


    }
}

void tirarDados(int arr [], int dados){
    for(int i=0; i<dados; i++){
        arr[i] = generarDado();
        cout<< arr[i]<<endl;
    }
}

int calcularMax (int a, int b) {
    if (a>b){
        return a;
    }else {
        return b;
    }
}

int generarDado(){
    int num;
    num = rand() % 6+1;
    return num;
}
