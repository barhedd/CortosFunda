#include <iostream>
#include <ctype.h>
using namespace std;

/*Declaración de la función que codifica una letra. Esta función recibe
la letra que se desea codificar como único parámetro*/
char codificarLetra(char letra);

//Inicio de la función main
int main(){
    int i=0; //Variable que utilizaremos para iterar
    /*Declaramos el arreglo donde almacenaremos la cadena de caracteres y una variable para 
    almacenar la letra que será codificada*/
    char letra, arreglo[100]; 
    cout<<"\n********************************************************";
    cout<<"\n\t\tCLAVE DEL MURCIELAGO"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"Hola! Este programa te ayudara codificar cualquier cadena de caracteres a clave murcielago"<<endl;
    cout<<"Por favor, ingresa una cadena de caracteres: ";
    /*Almacenamos la cadena de caracteres en "arreglo" con el método getline del cin. Esta función recibe como 
    parámetros el arreglo donde se almacenará la cadena y la longitud máxima de caracteres que puede leer*/
    cin.getline(arreglo, 100); 

    /*Las cadenas de caracteres tienen la particularidad de que deben finalizar con el carácter ‘\0’. 
    Cada vez que se almacena desde teclado una cadena de caracteres el compilador asigna al final de la cadena este valor.
    Por lo tanto, recorremos con un ciclo for la cadena de caracteres "arreglo" hasta que encuentre el caracter '\0' */
    for(i=0; i<arreglo[i] != '\0'; i++){
        /*Almacenamos la letra correspondiente a la posición "i" en la variable "letra", la cual, será enviada 
        como argumento a la función "codificarLetra()" */
        letra = arreglo[i]; 
        /*Invocamos la función "codificarLetra()" y almacenamos en la posición "i" de la cadena de caracteres
        la letra codificada*/
        arreglo[i] = codificarLetra(letra);
    }

    //Imprimimos en pantalla la cadena codifica a clave murcielago
    cout<<"\nLa cadena de caracteres codificada a clave murcielago es: "<<endl;
    /*Volvemos a recorrer el arreglo hasta que encuentre el caracter '\0' y vamos imprimiendo
    letra por letra*/
    for(i=0; i<arreglo[i] != '\0'; i++){
        cout<<arreglo[i];
    }
    cout<<"\n\n";
    return 0;
}

//Programación de la función que codifica una letra
char codificarLetra(char letra){
    /*Declaramos la variable que guardará el número correspondiente a la letra codificada*/
    char letraConvertida = ' ';

    /*Utilizamos la función tolower de la librería ctype.h para convertir a minúscula la letra
    recibida por parametro y así realizar una sola condición de evaluación en el swtich.*/
    letraConvertida = tolower(letra);

    //Evaluamos la letra en un switch
    switch(letraConvertida){
        case 'm':
            letraConvertida = '0';
            break;
        case 'u':
            letraConvertida = '1';
            break;
        case 'r':
            letraConvertida = '2';
            break;
        case 'c':
            letraConvertida = '3';
            break;
        case 'i':
            letraConvertida = '4';
            break;
        case 'e':
            letraConvertida = '5';
            break;
        case 'l':
            letraConvertida = '6';
            break;
        case 'a':
            letraConvertida = '7';
            break;
        case 'g':
            letraConvertida = '8';
            break;
        case 'o':
            letraConvertida = '9';
            break;
        /*Si la letra ingresada no corresponde a ninguna de la palabra "murcielago", entonces
        devolvemos la misma letra*/
        default:
            letraConvertida = letra;
    }
    return letraConvertida;
}