#include <iostream>
#include <iomanip> //Librería que nos servirá para redondear a dos decimales los resultados
using namespace std;

/* Declaración de la función que calcula la media de las estaturas. Esta función recibe 2 parámetros:
-el arreglo donde están almacenadas las estaturas  
-la variable que almacenará la media de las estaturas*/
float calcularMedia(float arreglo[], float *media);

/*Declaración de la función que compara y cuenta la cantidad de estaturas que están arriba 
de la media y debajo de la media. Esta función recibe 4 parámetros:
-el arreglo donde están almacenadas las estaturas
-la media de las estaturas
-las variables que almacenarán el número de estaturas que están arriba y abajo de la media*/
void compararMedia(float arreglo[], float media, int *arriba, int *abajo);

//Inicio de la función main
int main(){
    float media = 0; //Variable que almacenará la media de las estaturas
    float estaturas[25]; //Arreglo que almacena las 25 estaturas
    //Variables que almacena la cantidad de estaturas arriba y abajo del promedio
    int arriba = 0, abajo = 0; 
    cout<<"\n********************************************************";
    cout<<"\n\tCALCULO DEL PROMEDIO DE 25 ESTATURAS"<<endl;
    cout<<"********************************************************"<<endl;

    //Pedimos al usuario que ingrese las 25 estaturas
    cout<<"Por favor, ingresa una a una las 25 estaturas: "<<endl;
    for(int i=0; i<25; i++){
        cout<<"Estatura #"<<i+1<<": ";
        cin>>estaturas[i];
    }

    //Invocamos la función que calcula el promedio de las estaturas
    calcularMedia(estaturas, &media);

    /*Invocamos la función que compara y calcula la cantidad de estaturas que están arriba
    y debajo de la media*/
    compararMedia(estaturas, media, &arriba, &abajo);

    //Imprimimos en pantalla los resultados
    cout<<"\nEl promedio de las 25 estaturas es: "<<fixed<<setprecision(2)<<media<<endl;
    cout<<"Hay "<<arriba<<" estaturas arriba del promedio"<<endl;
    cout<<"Hay "<<abajo<<" estaturas abajo del promedio"<<endl;
    cout<<"\n";

    return 0;
}

//Programación de la función que calcula la media de las estaturas
float calcularMedia(float arreglo[], float *media){
    float acumulador = 0;
    for(int i=0; i<25; i++){
        acumulador += arreglo[i];
    }

    *media = acumulador/25;
    return *media;
}

//compara y cuenta la cantidad de estaturas que están arriba y debajo de la media
void compararMedia(float arreglo[], float media, int *arriba, int *abajo){
    for(int i=0; i<25; i++){
        if(arreglo[i] > media){
            *arriba += 1;
        }else if(arreglo[i] < media){
            *abajo += 1;
        }
    }
}