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


