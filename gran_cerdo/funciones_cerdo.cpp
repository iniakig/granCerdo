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
    cout << "2 - ESTAD�STICAS" << endl;
    cout << "3 - CERDITOS" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;

        /*DECLARACION DE VARIABLES */
    int opcMenuPrin;

    cout << "Ingrese una opci�n: ";
    cin >> opcMenuPrin;

    while(!(opcMenuPrin==1||opcMenuPrin==2||opcMenuPrin==3||opcMenuPrin==0)){
        cout << "El n�mero ingresado es inv�lido por favor ingreselo nuevamente: ";
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
        int trufasAcumuladas[CANT_JUGADORES][CANT_RONDAS+1] = {};
        int vecOinks [CANT_JUGADORES] = {};
        int vecMaxTiros [CANT_JUGADORES] = {};
        string jugadores[CANT_JUGADORES];
        cargarJugadores(jugadores, CANT_JUGADORES);
        cout << "Empieza jugando " << jugadores[0];
        int dadosAct = 2;
        for(int i=0; i<CANT_RONDAS; i++){
            cout<< "Ronda act "<< i+1<< endl;
            jugarRonda(jugadores,trufasAcumuladas,vecOinks,vecMaxTiros,CANT_JUGADORES, DADOS_MAX, i, dadosAct);

        }
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
                int bandEmpateMaxTiro = 0;
                int bandEmpateMaxDado = 0;
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
                    }else if(maxDadoAct == maxDado){
                        bandEmpateMaxDado = 1;
                    }

                    if(sumaTiro>maxTiro){
                        maxTiro = sumaTiro;
                        jugMaxTiroPos = i;
                    }else if (sumaTiro ==  maxTiro){
                        bandEmpateMaxTiro = 1;
                    }
                    cout << "Su tiro suma "<< sumaTiro << endl;
                    cout << "-----------------------------"<< endl;
                }

                if(bandEmpateMaxTiro == 1 && bandEmpateMaxDado == 1){
                    cout<<"La suma de los dados y el dado mas alto son igual, deben volver a tirar"<< endl;
                    cout << "----------------------------------"<< endl;
                }
                if(bandEmpateMaxTiro == 0){
                    if(jugMaxTiroPos==0){
                        arr[0] = nombresJugadores[0];
                        arr[1] = nombresJugadores[1];
                        bandEmpate = 1;
                    }else{
                        arr[0] = nombresJugadores[1];
                        arr[1] = nombresJugadores[0];
                        bandEmpate = 1;
                    }
                }else if(bandEmpateMaxDado ==0){
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

void jugarRonda(string jugadores[],int acuTrufasGlobal[2][6], int oinks[], int vecContTiros [], int cantJugadores, int dadosMax, int ronda, int &cantDados) {
    for( int i=0; i<cantJugadores; i++){
        int trufasRonda=0;
        bool bandCambioTurno = true;
        int vecDados [dadosMax] = {};
        int contadorTiros = 0;
        while (bandCambioTurno){
            cout<<"GRAN CERDO"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<jugadores[0]<<":"<<sumarTrufasGlobal(acuTrufasGlobal,0)<< "trufas acumuladas.         "<<jugadores[1]<<":"<<sumarTrufasGlobal(acuTrufasGlobal,1)<< "trufas acumuladas.         "<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"TURNO DE "<<jugadores[i]<<endl;
            dibujarCuadroRonda(ronda,trufasRonda,contadorTiros);
            cout<< "LANZAMIENTO #"<<contadorTiros+1<<endl;
            tirarDados(vecDados, cantDados);
            contadorTiros ++;
            if(cantDados == 2){
                if(vecDados[0] != 1 && vecDados[1] !=1){
                    if(vecDados[0] == vecDados[1]){ // CONDICIONES CUANDO LOS DADOS SON IGUALES PERO NINGUNO ES AS
                        trufasRonda+=(acumularTrufasTiro(vecDados, cantDados)*2);
                        oinks[i]=oinks[i]+1;
                        cout<<"Felicitaciones!!! Hiciste un OINK duplicas las trufas de este lanzamiento. Estas obligado a volver a tirar, apreta una tecla"<<endl;
                        cout<<"Llevas acumulados "<<oinks[i]<<" OINKS"<<endl;
                        //cout<<"Llevas acumuladas "<<trufasRonda<<" trufas" << endl;
                        getch();
                    }else{ // CONDICIONES PARA CUANDO LOS DADOS SON DISTINTOS PERO NINGUNO ES AS
                        trufasRonda+=acumularTrufasTiro(vecDados, cantDados);
                        bandCambioTurno = checkContinua();
                        if(!bandCambioTurno){
                            acuTrufasGlobal[i][ronda] = trufasRonda;
                        }
                    }
                }else if(vecDados[0] == vecDados[1]){ // CONDICIONES HUNDIDO EN EL BARRO POR DOS AS
                    cout << "Ups... " <<jugadores[i]<<" te hundiste en el barro, perdes todas las trufas que habias acumulado durante esta ronda y las anteriores. Ademas perdiste el turno, no te olvides 'A quien la codicia gobierna nada le dura'"<<endl;
                    for(int j=0; j<6; j++){
                        acuTrufasGlobal[i][j]=0;
                    }
                    bandCambioTurno = false;
                    cantDados = 3;
                }else{ // CONDICIONES CUANDO SALE UN SOLO AS
                    cout << "Que mala suerte! "<< jugadores[i]<< "Salio un AS, perdiste todas las trufas que venias acumulando en la ronda"<<endl;
                    trufasRonda = 0;
                    bandCambioTurno = false;
                }
            }
            if(cantDados > 2){ // CONDICIONES QUE APLICAN CUANDO SE EMPIEZA A JUGAR CON MAS DE 2 DADOS
                if(vecDados[0] != 1 && vecDados[1] !=1 && vecDados[2] !=1){
                    if(vecDados[0] == vecDados[1] && vecDados[1] == vecDados[2]){ // TRES DADOS IGUALES -- OINK!!
                        trufasRonda+=(acumularTrufasTiro(vecDados, cantDados)*2);
                        oinks[i]=oinks[i]+1;
                        cout<<"Felicitaciones!!! Hiciste un OINK duplicas las trufas de este lanzamiento. Estas obligado a volver a tirar, apreta una tecla"<<endl;
                        cout<<"Llevas acumulados "<<oinks[i]<<" OINKS"<<endl;
                        getch();
                    }else{ // DADOS DIFERENTES SIN AS
                        trufasRonda+=acumularTrufasTiro(vecDados, cantDados);
                        bandCambioTurno = checkContinua();
                        if(!bandCambioTurno){
                            acuTrufasGlobal[i][ronda] = trufasRonda;
                        }
                    }
                }else if(vecDados[0] == vecDados[1] && vecDados[1] == vecDados[2]){ // TRES ASES
                        cout<< "Oh no!!! este cerdito quedo hundido en el barro. El otro cerdito aprovecha la ocasion y le roba todas las trufas que habia acumulado. Estas tan ocupado en intentar salir que no podes hacer nada contra el otro"<<endl;
                        if(i==0){
                            acuTrufasGlobal[1][6]+=sumarTrufasGlobal(acuTrufasGlobal,i);
                            cout<<"Te robaron "<< sumarTrufasGlobal(acuTrufasGlobal,i)<<" trufas."<<endl;
                            for(int j=0; j<6; j++){
                                acuTrufasGlobal[i][j]=0;
                            }
                                bandCambioTurno = false;
                        }else{
                            acuTrufasGlobal[0][6]+=sumarTrufasGlobal(acuTrufasGlobal,i);
                            cout<<"Te robaron "<< sumarTrufasGlobal(acuTrufasGlobal,i)<<" trufas."<<endl;
                            for(int j=0; j<6; j++){
                                acuTrufasGlobal[i][j]=0;
                            }
                                bandCambioTurno = false;
                        }
                }else{ // CUALQUIER NUMERO ACOMPANADO DE UNO O DOS ASES
                    cout << "Que mala suerte! "<< jugadores[i]<< "Salio un AS, perdiste todas las trufas que venias acumulando en la ronda"<<endl;
                    trufasRonda = 0;
                    bandCambioTurno = false;
                }

            }
        }
        cout<<"------------------------------------------------------------------------"<<endl;
        if(contadorTiros > vecContTiros[i]){
            vecContTiros[i]=contadorTiros;
            cout<< "Superaste tu ronda con mayor cantidad de tiros. Lanzaste "<< vecContTiros[i]<< " tiros."<<endl;
        }
        if(sumarTrufasGlobal(acuTrufasGlobal,0)>50 && sumarTrufasGlobal(acuTrufasGlobal,1)>50){
            cantDados = 3;
        }
        cout << "Turno del siguiente jugador, presiona una tecla"<<endl;
        getch();
        system("cls");
    }
}

void dibujarCuadroRonda (int ronda, int trufas, int tiros){

    cout<< "+------------------------------+"<<endl;
    cout<< "| RONDA: "<<ronda+1<<"                     |"<<endl;
    cout<< "| TRUFAS DE LA RONDA: "<<trufas<<"       |"<<endl;
    cout<< "| LANZAMIENTOS: "<<tiros<<"             |"<<endl;
    cout<< "+------------------------------+"<<endl;
}
bool checkContinua(){
    char ingreso;
    cout<<"Quiere volver a tirar? -- S/N"<<endl;
    cin>>ingreso;
    while (!(ingreso== 'N' || ingreso=='n' || ingreso=='s' || ingreso=='S')){
        cout<< "El ingreso no es valido, por favor vuelva a ingresar su opcion. Quiere volver a tirar? -- S/N"<<endl;
        cin>>ingreso;
    }
    if(ingreso=='N'||ingreso=='n'){
        return false;
    }else {
        return true;
    }
}

int acumularTrufasTiro (int arr[],int dados){
    int acuTrufas = 0;
    for(int i=0; i<dados; i++){
        acuTrufas+=arr[i];
    }
    return acuTrufas;
}

int sumarTrufasGlobal (int mat[2][6], int numJug) {
    int trufasAcumuladas = 0;
    for(int i = 0; i<6; i++){
        trufasAcumuladas+= mat[numJug][i];
    }
    return trufasAcumuladas;

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
    //cin>>num;
    num = rand() % 6+1;
    return num;
}
