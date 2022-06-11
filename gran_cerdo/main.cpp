#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;

#include "funciones_cerdo.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    srand (time(NULL));

    cargarMenu();

}

    /*cout<<"----------------------"<<endl;
    int dados [3] = {};
    int sumaDados;
    int cantDados = 3;
    for(int i=0; i<cantDados; i++){
        dados[i] = generarDado();
        sumaDados+=dados[i];
        cout<<dados[i]<< endl;
    }*/


