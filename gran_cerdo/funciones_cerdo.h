#ifndef FUNCIONES_CERDO_H_INCLUDED
#define FUNCIONES_CERDO_H_INCLUDED

void cargarMenu();
void cargarJugadores(string arr[], int cant); // FUNCION PARA CARGAR LOS NOMBRES DE LOS JUGADORES Y DEFINIR QUIEN DEBE COMENZAR TIRANDO -- SE PASA EL VECTOR DONDE SE GUARDAN LOS NOMBRES DE LOS JUGADORES X PARAMETRO.
void jugarJuego();
void jugarRonda(string jugadores[],int cantJugadores, int dadosMax, int ronda, int cantDados);
void tirarDados(int arr [], int dados);
void mostrarJugAct(string jugador);
int generarDado(); // FUNCION QUE DEVUELVE UN NUMERO ENTRE 1 Y 6 -- O EL VALOR DE UN SOLO DADO
int calcularMax(int a, int b); // FUNCION A LA QUE SE LE PASAN DOS INT y DEVUELVE EL MAXIMO
#endif // FUNCIONES_CERDO_H_INCLUDED
