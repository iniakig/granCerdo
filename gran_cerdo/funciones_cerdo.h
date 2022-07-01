#ifndef FUNCIONES_CERDO_H_INCLUDED
#define FUNCIONES_CERDO_H_INCLUDED

void cargarMenu();
void cargarJugadores(string arr[], int cant); // FUNCION PARA CARGAR LOS NOMBRES DE LOS JUGADORES Y DEFINIR QUIEN DEBE COMENZAR TIRANDO -- SE PASA EL VECTOR DONDE SE GUARDAN LOS NOMBRES DE LOS JUGADORES X PARAMETRO.
void cargarPDV (int pdv[2][4], int trufas [2][6],int oinks[], int tiros[]);
void jugarJuego(int pdv[2][4], int cantJug, int cantRondas, int dadosMax, int trufasAcumuladas[2][6], int vecOinks[], int vecMaxTiros[], string jugadores[]);
void jugarRonda(string jugadores[],int acuTrufasGlobal[2][6], int oinks[], int vecContTiros [], int cantJugadores, int dadosMax, int ronda, int &cantDados);
void dibujarCuadroRonda (int ronda, int trufas, int tiros); // FUNCION QUE RECIBE POR PARAMETRO LA RONDA, EL ACUMULADOR DE TRUFAS DE LA RONDA Y EL ACUMULADOR DE TIROS DE LA RONDA Y LOS DIBUJA EN UN CUADRO.
void dibujarCuadroEstadisticas (int pdv[2][4], int trufas[2][6], int oinks[], int tiros[], string jugadores[]);
bool checkContinua(); // FUNCION QUE PREGUNTA SI QUIERE CONTINUAR TIRANDO. RETORNA UN BOOL
int acumularTrufasTiro (int arr[],int dados); // FUNCION UTILIZADA PARA SUMAR LAS TRUFAS DEL TIRO AL ACUMULADOR DE LA RONDA ACTUAL. NO CARGA EN EL ACUMULADOR GLOBAL
int sumarTrufasGlobal (int mat[2][6], int numJug);
void tirarDados(int arr [], int dados); // AL LLAMAR A LA FUNCION SE CARGA EN UN VECTOR DE 3 POSICIONES NUMEROS DEL 1 al 6. A Traves del parametro DADOS se pasa la variable dadosAct(Establece si se juega con 2 o 3 dados).
int generarDado(); // FUNCION QUE DEVUELVE UN NUMERO ENTRE 1 Y 6 -- O EL VALOR DE UN SOLO DADO
int calcularMax(int a, int b); // FUNCION A LA QUE SE LE PASAN DOS INT y DEVUELVE EL MAXIMO
#endif // FUNCIONES_CERDO_H_INCLUDED
