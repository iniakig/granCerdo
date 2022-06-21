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
        int trufasAcumuladas[CANT_JUGADORES][CANT_RONDAS] = {};
        int oinksAcu [CANT_JUGADORES] = {};
        string jugadores[CANT_JUGADORES];
        cargarJugadores(jugadores, CANT_JUGADORES);
        cout << "Empieza jugando " << jugadores[0];
        int dadosAct = 2;
        for(int i=0; i<CANT_RONDAS; i++){
                cout<< "Ronda act "<< i+1<< endl;
            jugarRonda(jugadores,trufasAcumuladas,oinksAcu,CANT_JUGADORES, DADOS_MAX, i, dadosAct);
        }
}

void mostrarJugAct(string jug[], int a){
    cout << "Jugador act "<< jug[a] <<endl;
}

void cargarJugadores(string arr[], int cant){
            string nombresJugadores[cant];
            int matDados [cant][2];
            int bandEmpate = 0;
            for(int i=0; i<cant; i++){
                cout << "Ingrese el nombre del jugador " << i+1 << " " << endl;
                cin.ignore();
                //cin >> nombresJugadores[i];
                getline(cin, nombresJugadores[i]);
                //cin.ignore();
            }

            while(bandEmpate == 0){
                int maxTiro = 0;
                int maxDado = 0;
                int acuMaxTiro = 0;
                int acuMaxDado = 0;
                int jugMaxTiroPos;
                int jugMaxDadoPos;
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

void jugarRonda(string jugadores[],int acuTrufasGlobal[2][5], int oinks[], int cantJugadores, int dadosMax, int ronda, int cantDados) {
    for( int i=0; i<cantJugadores; i++){

        int trufasRonda=0;
        bool bandCambioTurno = true;
        int vecDados [dadosMax] = {};
        while (bandCambioTurno){
            //system("cls");
            cout<<"------------------------------------------"<< endl;
            cout<<"Actualmente esta jugando en la ronda "<< ronda+1<<endl;
            cout<<"------------------------------------------"<< endl;
            cout<<jugadores[i]<< " es tu turno. Presiona una tecla para tirar tus dados"<<endl;
            getch();
            tirarDados(vecDados, cantDados);
            if(cantDados == 2){
                if(vecDados[0] != 1 && vecDados[1] !=1){
                    if(vecDados[0] == vecDados[1]){
                        trufasRonda+=(acumularTrufasTiro(vecDados, cantDados)*2);
                        oinks[i]=oinks[i]+1;
                        cout<<oinks[i]<<endl;
                        cout<<"Felicitaciones!!! Hiciste un OINK duplicas las trufas. En este tiro juntaste "<<trufasRonda<<"Estas obligado a volver a tirar, apreta una tecla"<<endl;
                        getch();
                    }else{
                        char continua;
                        trufasRonda+=acumularTrufasTiro(vecDados, cantDados);
                        cout<<"---------------------------------"<<endl;
                        cout<<"Llevas acumuladas "<<trufasRonda<<" trufas" << endl;
                        cout<<"Quiere volver a tirar? -- S/N"<<endl;
                        cin>>continua;
                        if(continua=='N'||continua=='n'){
                            bandCambioTurno = false;
                            acuTrufasGlobal[i][ronda] = trufasRonda;
                            cout<< "------------------------------------------------"<<endl;
                            cout<< "En esta ronda sumaste "<<acuTrufasGlobal[i][ronda]<< endl;
                        }
                    }
                }else if(vecDados[0] == vecDados[1]){
                    cout << "Ups... " <<jugadores[i]<<" te hundiste en el barro, perdes todas las trufas que habias acumulado durante esta ronda y las anteriores. Ademas perdiste el turno, no te olvides 'A quien la codicia gobierna nada le dura'"<<endl;
                    for(int j=0; j<5; j++){
                        acuTrufasGlobal[i][j]=0;
                        //cout<< acuTrufasGlobal[i][j];
                        bandCambioTurno = false;
                    }
                }else{
                    cout << "Que mala suerte! "<< jugadores[i]<< "Salio un AS, perdiste todas las trufas que venias acumulando en la ronda"<<endl;
                    trufasRonda = 0;
                    bandCambioTurno = false;
                }
            }
        }
    }
}

/*void sumarTrufasGlobal (int matTrufas [2][5], int acuTrufas, int numJug, int ronda){
    matTrufas [numJug][ronda] = acuTrufas;
}*/

int acumularTrufasTiro (int arr[],int dados){
    int acuTrufas = 0;
    for(int i=0; i<dados; i++){
        acuTrufas+=arr[i];
    }
    return acuTrufas;
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
