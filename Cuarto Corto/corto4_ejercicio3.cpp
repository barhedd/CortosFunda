#include <iostream>
#include <iomanip> //Librería que nos servirá para redondear a dos decimales los resultados
using namespace std;

/*Declaración de la función que llena la matriz. Esta función recibe dos parámetros:
la matriz a llenar y el número de filas de dicha matriz*/
void llenarMatriz(float matriz[][5], int N);

/*Declaración de la función que calcula la nota final y muestra si el alumno aprobó 
o reprobó. Esta función recibe dos parámetros: la matriz con las notas y el número
de filas de dicha matriz*/
void calcularNotaFinal(float matriz[][5], int N);

//Inicio de la función main
int main(){
    //Declaramos la variable que almacenará el número de estudiantes
    int N = 0;
    cout<<"\n********************************************************";
    cout<<"\n\t    SISTEMA DE REGISTRO DE NOTAS"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"Ingrese la cantidad de alumnos: ";
    cin>>N;
    cout<<"\n";
    float notas[N][5];
    //Invocamos las funciones
    llenarMatriz(notas, N);
    calcularNotaFinal(notas, N);
    return 0;
}

//Programación de la función que llena la matriz
void llenarMatriz(float matriz[][5], int N){
    for(int i=0; i<N; i++){
        cout<<"NOTAS DEL ALUMNO #"<<i+1<<endl;
        for(int j=0; j<5; j++){
            cout<<"Ingrese la nota #"<<j+1<<": ";
            cin>>matriz[i][j];
        }
        cout<<"\n";
    }
}

//Programación de la función que calcula la nota final
void calcularNotaFinal(float matriz[][5], int N){
    float notaFinal = 0;
    for(int i=0; i<N; i++){
        notaFinal = (matriz[i][0] * 0.2) + (matriz[i][1] * 0.2) + (matriz[i][2] * 0.2) +
        (matriz[i][3] * 0.2) + (matriz[i][4] * 0.2);
        cout<<">La nota final del alumno #"<<i+1<<" es: "<<fixed<<setprecision(2)<<notaFinal<<endl;
        if(notaFinal>=6){
            cout<<"El alumno APROBO"<<endl;
        }else{
            cout<<"El alumno REPROBO"<<endl;
        }
        cout<<"\n";
    }
}