#ifndef FUNCIONES_CERDO_H_INCLUDED
#define FUNCIONES_CERDO_H_INCLUDED

void cargarMenu();
void cargarJugadores(string arr[], int cant); // FUNCION PARA CARGAR LOS NOMBRES DE LOS JUGADORES Y DEFINIR QUIEN DEBE COMENZAR TIRANDO -- SE PASA EL VECTOR DONDE SE GUARDAN LOS NOMBRES DE LOS JUGADORES X PARAMETRO.
void jugarJuego();
void jugarRonda(string jugadores[],int acuTrufasGlobal [2][5], int cantJugadores, int dadosMax, int ronda, int cantDados);
int acumularTrufasTiro (int arr[],int dados); // FUNCION UTILIZADA PARA SUMAR LAS TRUFAS DEL TIRO AL ACUMULADOR DE LA RONDA ACTUAL. NO CARGA EN EL ACUMULADOR GLOBAL
void sumarTrufasGlobal (int matTrufas [2][5], int acuTrufas, int numJug, int ronda);
void tirarDados(int arr [], int dados); // AL LLAMAR A LA FUNCION SE CARGA EN UN VECTOR DE 3 POSICIONES NUMEROS DEL 1 al 6. A Traves del parametro DADOS se pasa la variable dadosAct(Establece si se juega con 2 o 3 dados).
void mostrarJugAct(string jugador);
int generarDado(); // FUNCION QUE DEVUELVE UN NUMERO ENTRE 1 Y 6 -- O EL VALOR DE UN SOLO DADO
int calcularMax(int a, int b); // FUNCION A LA QUE SE LE PASAN DOS INT y DEVUELVE EL MAXIMO
#endif // FUNCIONES_CERDO_H_INCLUDED
