#include <iostream>
#include "rlutil.h"
using namespace std;
#include "funciones.h"


void cargarMaterias(){
    int numMateria, cantAlumnosInscriptos, cantProfesores;
    string nombreMateria;

    //Son 20 materias, pero para probar puse solo 1 ingreso.
    for(int i=0; i<1; i++){
        cout << "Numero de materia: ";
        cin >> numMateria;
        cout << "Nombre de materia: ";
        cin >> nombreMateria;
        cout << "Cantidad de alumnos inscriptos: ";
        cin >> cantAlumnosInscriptos;
        cout << "Cantidad de profesores: ";
        cin >> cantProfesores;
    }
}
void cargarNotas(bool vectorPuntoA[], float vecMateriaXHoras[], int matrizMateriaXDias[][30]){
    int legajo, fechaAccesoDia, fechaAccesoMes, numMateriaQueIngreso;
    float cantHoras;

    system("cls");
    cout << "Legajo: ";
    cin >> legajo;

    while(legajo != 0){
        cout << "¿Fecha de acceso?" << endl;
        cout << "DIA: ";
        cin >> fechaAccesoDia;
        cout << "MES: ";
        cin >> fechaAccesoMes;
        cout << "Numero de la materia a la que ingreso: ";
        cin >> numMateriaQueIngreso;
        cout << "Cantidad de horas: ";
        cin >> cantHoras;

        //Resuelvo punto A
        if(fechaAccesoDia != 0 && fechaAccesoMes != 0){
            vectorPuntoA[numMateriaQueIngreso-1] = true;
        }
        //Resuelvo punto B, las filas representan las materias, y la columna las horas acumuladas de dicha materia
        vecMateriaXHoras[numMateriaQueIngreso-1]+=cantHoras;
        //Resuelvo punto C
        if(fechaAccesoMes == 3){
            //Para la fila materia, columna dia, guardo esos datos en la 3era dimension, ya que si no tuviese una 3era dimension, se estarian cruzando las materias con los dias.
            matrizMateriaXDias[numMateriaQueIngreso-1][fechaAccesoDia-1]++;
        }
        cout << "Legajo: ";
        cin >> legajo;
    }
}
void mostrarMenu(){
    rlutil::setColor(rlutil::YELLOW);
    cout << "              ¡BIENVENIDO!   " << endl;
    cout << "*-----------------------------------------*" << endl;
    cout << "       SELECCIONE LA OPCIÓN DESEADA" << endl;
    cout << "*-----------------------------------------*" << endl;
    cout << "1 - CARGAR REGISTRO DE MATERIAS" << endl;
    cout << "2 - CARGAR INGRESOS DE ESTUDIANTES AL AULA" << endl;
    cout << "3 - VER PUNTO A)" << endl;
    cout << "4 - VER PUNTO B)" << endl;
    cout << "5 - VER PUNTO C)" << endl;
    cout << "*-----------------------------------------*" << endl;
    cout << "0 - SALIR" << endl;
}
void puntoA(bool vectorPuntoA[]){
    for(int i=0; i<20; i++){
        if(vectorPuntoA[i] == false){
            cout << "La materia: #" << i+1 << " no tuvo acceso de alumnos nunca." << endl;
        }
    }
}
void puntoB(float vecMateriaXHoras[]){
    int materiaMax;
    float horasMaxMateria = 0;

    system("cls");
    for(int i=0; i<20; i++){
        if(vecMateriaXHoras[i] > horasMaxMateria){
            materiaMax = i+1;
            horasMaxMateria = vecMateriaXHoras[i];
        }
    }
    cout << "La materia que más cantidad de horas registro fue: #" << materiaMax << endl;
}
void puntoC(int matrizMateriaXDias[][30]){
    bool mensajeUnico;
    system("cls");

    for(int i=0; i<20; i++){
        mensajeUnico = true;
        for(int d=0; d<30; d++){
            if(matrizMateriaXDias[i][d] > 0 && mensajeUnico == true){
                cout << "Para la materia #" << i+1 << ", la cantidad de accesos de alumnos en el mes de marzo, a las aulas virtuales es" << endl;
                mensajeUnico = false;
            }
            if(matrizMateriaXDias[i][d] > 0){
                cout << "DIA: " << d+1 << " | cantidad de accesos de alumnos: #" << matrizMateriaXDias[i][d] << endl;
            }
        }
    }
}
