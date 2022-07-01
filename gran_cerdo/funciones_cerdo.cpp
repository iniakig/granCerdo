#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h> /* para funcion time*/
#include <conio.h>
#include <math.h>
using namespace std;

#include "funciones_cerdo.h"

void cargarMenu (string jugadores[], int pdvMax[]) {
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
            jugarJuego(jugadores, pdvMax);


        break;
        case 2:
            imprimirEstadisticas(jugadores, pdvMax);
        break;
        case 3:
            imprimirCreditos();
        break;
        case 0:
            char ingreso;
            cout<<"Quiere salir del programa? -- S/N"<<endl;
            cin>>ingreso;
            while (!(ingreso== 'N' || ingreso=='n' || ingreso=='s' || ingreso=='S')){
                cout<< "El ingreso no es valido, por favor vuelva a ingresar su opcion. Quiere salir del programa? -- S/N"<<endl;
                cin>>ingreso;
            }
            if(ingreso=='S'||ingreso=='s'){
                exit(0);
            }
        break;

    }
}

void jugarJuego(string jugadores[], int arrPDVTotal[]){
        const int CANT_JUGADORES=2;
        const int CANT_RONDAS=5;
        const int DADOS_MAX=3;
        arrPDVTotal[0] = 0;
        arrPDVTotal[1] = 0;
        int trufasAcumuladas[CANT_JUGADORES][CANT_RONDAS+1] = {};
        int vecOinks [CANT_JUGADORES] = {};
        int vecMaxTiros [CANT_JUGADORES] = {};
        int matPDV[2][4]={};
        cargarJugadores(jugadores, CANT_JUGADORES);
        cout << "Empieza jugando " << jugadores[0]<<" presiona una tecla para comenzar"<<endl;
        getch();
        system("cls");
        int dadosAct = 2;
        for(int i=0; i<CANT_RONDAS; i++){
            jugarRonda(jugadores,trufasAcumuladas,vecOinks,vecMaxTiros,CANT_JUGADORES, DADOS_MAX, i, dadosAct);

        }
        cargarPDV(matPDV, trufasAcumuladas, vecOinks, vecMaxTiros, arrPDVTotal);
        dibujarCuadroPDV(matPDV, trufasAcumuladas, vecOinks, vecMaxTiros, jugadores, arrPDVTotal);
}

void cargarJugadores(string arr[], int cant){
            string nombresJugadores[cant];
            int matDados [cant][2];
            int bandEmpate = 0;
            for(int i=0; i<cant; i++){
                cin.ignore();
                cout << "Ingrese el nombre del jugador " << i+1<<": ";
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
            cout<<jugadores[0]<<" : "<<sumarTrufasGlobal(acuTrufasGlobal,0)<< " trufas acumuladas.         "<<jugadores[1]<<" : "<<sumarTrufasGlobal(acuTrufasGlobal,1)<< " trufas acumuladas.         "<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"TURNO DE "<<jugadores[i]<<endl;
            cout<< endl;
            cout<< endl;
            dibujarCuadroRonda(ronda,trufasRonda,contadorTiros);
            cout<< endl;
            cout<< endl;
            cout<< "LANZAMIENTO #"<<contadorTiros+1<<endl;
            tirarDados(vecDados, cantDados);
            contadorTiros ++;
            if(cantDados == 2){
                if(vecDados[0] != 1 && vecDados[1] !=1){
                    if(vecDados[0] == vecDados[1]){ // CONDICIONES CUANDO LOS DADOS SON IGUALES PERO NINGUNO ES AS
                        trufasRonda+=(acumularTrufasTiro(vecDados, cantDados)*2);
                        oinks[i]=oinks[i]+1;
                        cout<<"Felicitaciones!!! Hiciste un OINK. Sumaste "<< acumularTrufasTiro(vecDados, cantDados)*2<<" trufas!!. Estas obligado a volver a tirar, apreta una tecla"<<endl;
                        cout<<"Llevas acumulados "<<oinks[i]<<" OINKS"<<endl;
                        getch();
                    }else{ // CONDICIONES PARA CUANDO LOS DADOS SON DISTINTOS PERO NINGUNO ES AS
                        cout<<"Sumaste "<<acumularTrufasTiro(vecDados, cantDados)<< " trufas!"<<endl;
                        trufasRonda+=acumularTrufasTiro(vecDados, cantDados);
                        bandCambioTurno = checkContinua();
                        if(!bandCambioTurno){
                            acuTrufasGlobal[i][ronda] = trufasRonda;
                        }
                    }
                }else{
                    if(vecDados[0] == vecDados[1]){ // CONDICIONES HUNDIDO EN EL BARRO POR DOS AS
                        cout << "Ups... " <<jugadores[i]<<" te hundiste en el barro, perdes todas las trufas que habias acumulado durante esta ronda y las anteriores. Ademas perdiste el turno, no te olvides 'A quien la codicia gobierna nada le dura'"<<endl;
                        for(int j=0; j<6; j++){
                            acuTrufasGlobal[i][j]=0;
                        }
                        bandCambioTurno = false;
                        cantDados = 3;
                    }else{ // CONDICIONES CUANDO SALE UN SOLO AS
                    cout << "Que mala suerte! "<< jugadores[i]<< " Salio un AS, perdiste todas las trufas que venias acumulando en la ronda"<<endl;
                    trufasRonda = 0;
                    bandCambioTurno = false;
                    }
                }
            }
            if(cantDados > 2){ // CONDICIONES QUE APLICAN CUANDO SE EMPIEZA A JUGAR CON MAS DE 2 DADOS
                if(vecDados[0] != 1 && vecDados[1] !=1 && vecDados[2] !=1){
                    if(vecDados[0] == vecDados[1] && vecDados[1] == vecDados[2]){ // TRES DADOS IGUALES -- OINK!!
                        trufasRonda+=(acumularTrufasTiro(vecDados, cantDados)*2);
                        oinks[i]=oinks[i]+1;
                        cout<<"Felicitaciones!!! Hiciste un OINK. Sumaste "<< acumularTrufasTiro(vecDados, cantDados)*2<<" trufas!!. Estas obligado a volver a tirar, apreta una tecla"<<endl;
                        cout<<"Llevas acumulados "<<oinks[i]<<" OINKS"<<endl;
                        getch();
                    }else{ // DADOS DIFERENTES SIN AS
                        cout<<"Sumaste "<<acumularTrufasTiro(vecDados, cantDados)<< " trufas!"<<endl;
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
                    cout << "Que mala suerte! "<< jugadores[i]<< " Salio un AS, perdiste todas las trufas que venias acumulando en la ronda"<<endl;
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

void cargarPDV (int pdv[2][4], int trufas [2][6],int oinks[], int tiros[], int arrPDVTotal[]){
    int pdvmaxTrufas = 5;
    int pdvOinks = 2;
    int pdvMaxTiros = 3;
    int trufasJug1 = sumarTrufasGlobal(trufas,0);
    int trufasJug2 = sumarTrufasGlobal(trufas,1);

    // BUSCAR MAX TRUFAS Y ASIGNAR EN QUIEN CORRESPONDE
    if(trufasJug1>trufasJug2){
        pdv[0][0]=pdvmaxTrufas;
    }else if(trufasJug1<trufasJug2){
        pdv[1][0]=pdvmaxTrufas;
    }else if(trufasJug1==trufasJug2){
        pdv[0][0]=pdvmaxTrufas;
        pdv[1][0]=pdvmaxTrufas;
    }

    // ASIGNARLE 1 PDV cada 50 TRUFAS x JUGADOR
    pdv[0][1]=trufasJug1/50;
    pdv[1][1]=trufasJug2/50;

    //ASIGNAR 2 PDV POR CADA OINK X JUGADOR
    pdv[0][2]=oinks[0]*pdvOinks;
    pdv[1][2]=oinks[1]*pdvOinks;

    // ASIGNAR 3 PDV AL QUE HAYA HECHO MAS LANZAMIENTOS EN UNA RONDA
    if(tiros[0]>tiros[1]){
        pdv[0][3]=pdvMaxTiros;
    }else if(tiros[0]<tiros[1]){
        pdv[1][3]=pdvMaxTiros;
    }else if(tiros[0]==tiros[1]){
        pdv[0][3]=pdvMaxTiros;
        pdv[1][3]=pdvMaxTiros;
    }

    // CARGA LOS PUNTOS DE VICTORIA TOTALES EN UN ARRAY DE LA FUNCION MAIN PARA LUEGO USARLOS EN LA ESTADISTICA
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            arrPDVTotal[i]= arrPDVTotal[i]+pdv[i][j];
        }
    }
}

void dibujarCuadroRonda (int ronda, int trufas, int tiros){

    if(trufas<10){
        cout<< "+------------------------------+"<<endl;
        cout<< "| RONDA: "<<ronda+1<<"                     |"<<endl;
        cout<< "| TRUFAS DE LA RONDA: "<<trufas<<"        |"<<endl;
        cout<< "| LANZAMIENTOS: "<<tiros<<"              |"<<endl;
        cout<< "+------------------------------+"<<endl;
    }else if(trufas>=10 && trufas<100){
        cout<< "+------------------------------+"<<endl;
        cout<< "| RONDA: "<<ronda+1<<"                     |"<<endl;
        cout<< "| TRUFAS DE LA RONDA: "<<trufas<<"       |"<<endl;
        cout<< "| LANZAMIENTOS: "<<tiros<<"              |"<<endl;
        cout<< "+------------------------------+"<<endl;
    }else if(trufas>=100){
        cout<< "+------------------------------+"<<endl;
        cout<< "| RONDA: "<<ronda+1<<"                     |"<<endl;
        cout<< "| TRUFAS DE LA RONDA: "<<trufas<<"      |"<<endl;
        cout<< "| LANZAMIENTOS: "<<tiros<<"              |"<<endl;
        cout<< "+------------------------------+"<<endl;
    }

}

void dibujarCuadroPDV (int pdv[2][4], int trufas[2][6], int oinks[], int tiros[], string jugadores[], int arrPDVTotal[]){
    int trufasJug1=sumarTrufasGlobal(trufas,0);
    int trufasJug2=sumarTrufasGlobal(trufas,1);

    string oink;
    cout<<"GRAN CERDO"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"HITO                                 "<<jugadores[0]<<"                    "<<jugadores[1]<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"M�s trufas en total                  "<<pdv[0][0]<<" PDV ("<<trufasJug1<<" trufas)         "<<pdv[1][0]<<" PDV ("<<trufasJug2<<" trufas)"<<endl;
    cout<<"Cada 50 trufas                       "<<pdv[0][1]<<" PDV ("<<50*pdv[0][1]<<" trufas)          "<<pdv[1][1]<<" PDV ("<<50*pdv[1][1]<<" trufas)"<<endl;
    cout<<"Oinks                                "<<pdv[0][2]<<" PDV ("<<oinks[0]<<" Oinks)           "<<pdv[1][2]<<" PDV ("<<oinks[1]<<" Oinks)"<<endl;
    cout<<"Cerdo codicioso                      "<<pdv[0][3]<<" PDV ("<<tiros[0]<<" lanzamientos)    "<<pdv[1][3]<<" PDV ("<<tiros[1]<<" lanzamientos)"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"TOTAL                                "<<arrPDVTotal[0]<<" PDV                   "<<arrPDVTotal[1]<<" PDV"<<endl;
    cout<<endl;

    // LEYENDA GANADOR
    if(arrPDVTotal[0]>arrPDVTotal[1]){
        cout<< "GANADOR: "<< jugadores[0]<<" con "<<arrPDVTotal[0]<< " puntos de victoria."<<endl;
    }else if(arrPDVTotal[0]<arrPDVTotal[1]){
        cout<< "GANADOR: "<< jugadores[1]<<" con "<<arrPDVTotal[1]<< " puntos de victoria."<<endl;
    }else if(arrPDVTotal[0]==arrPDVTotal[1]){
        cout<< "Empataron los dos con "<< arrPDVTotal[0]<<" puntos de victoria."<<endl;
    }
    cout<<endl;
    cout<<"Ingrese Oink para continuar: ";
    cin>>oink;
    while(!(oink == "oink" || oink == "OINK")){
        cout<<"Ingresaste otra palabra, por favor escribi OINK para continuar: ";
        cin>>oink;
    }
}

void imprimirEstadisticas(string jugador[], int pdv[]){

    if(pdv[0]== 0 && pdv[1]==0){
        cout<<"Aun no se jugo ninguna partida, no hay estadisticas para mostrar"<<endl;
    }else if(pdv[0]>pdv[1]){
        cout<< "El jugador que tiene la mayor cantidad de PDV es: "<< jugador[0]<<" con "<<pdv[0]<<endl;
    }else if(pdv[0]<pdv[1]){
        cout<< "El jugador que tiene la mayor cantidad de PDV es: "<< jugador[1]<<" con "<<pdv[1]<<endl;
    }else if(pdv[0]==pdv[1]){
        cout<<jugador[0]<< " y "<<jugador[1]<<" empataron con "<< pdv[0]<<" puntos de victoria."<<endl;
    }
    cout<<endl;
    cout <<"Presiona cualquier tecla para volver al men�" << endl;
    getch();
    system("cls");

}

void imprimirCreditos(){
    cout <<"PIGGY OINK"<< endl;
    cout << "_-_-_-_-_-_" << endl;
    cout <<"Legajo 26340, Arroyo, Ailen Marina"<< endl;
    cout <<"Legajo 25801, Avila, Rosario"<< endl;
    cout <<"Legajo 26861, Galdos Surmani, I�aki"<< endl;
    cout <<"Legajo 26175, Velazquez, Kevin Alejandro"<< endl;
    cout<<endl;
    cout <<"Presiona cualquier tecla para volver al men�" << endl;
    getch();
    system("cls");
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
