#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "Spanish");
    int opcion;

    //DATOS PUNTO A - 20 FILAS QUE CADA UNA REPRESENTA LAS MATERIAS
    bool vectorPuntoA[20]={};
    //DATOS PUNTO B - LAS FILAS SON LAS MATERIAS
    float vecMateriaXHoras[20]={};
    //DATOS PUNTO C -
    int matrizMateriaXDias[20][30]={};

    mostrarMenu();
    rlutil::hidecursor();
    cin >> opcion;
    system("cls");

    while(opcion != 0){

        switch(opcion){
            case 1: cargarMaterias();
            break;

            case 2: cargarNotas(vectorPuntoA, vecMateriaXHoras, matrizMateriaXDias);
            break;

            case 3: puntoA(vectorPuntoA);
            break;

            case 4: puntoB(vecMateriaXHoras);
            break;

            case 5: puntoC(matrizMateriaXDias);
            break;


            default: cout << "Opción incorrecta, vuelva a marcar una opción disponible nuevamente" << endl;
            break;
        }
    system("pause");
    system("cls");
    mostrarMenu();
    cin >> opcion;
    }

    return 0;
}
