#include <iostream>
#include <conio.h> //Librería que nos servirá para capturar un caracter ingresado desde el teclado

using namespace std;

//Prototipo de la función que determina si el usuario adivina o no el número mágico
bool adivinar(int numero, string *mensaje, int *contador);

//Inicio de la función main
int main(){
    string cadena; //Variable que almacena las pistas brindadas al usuario
    char salir = ' '; //Variable que captura el caracter si el usuario quiere salir del juego
    int intentos=5, numero; //Declaramos e inicializamos la variable intentos en 5
    bool auxiliar=false; //Variable auxiliar que nos permite saber si el usuario ha adivinado el número o no
    system("cls");

    do{
        system("cls");
        cout<<"\n********************************************************";
        cout<<"\n\t\tEL NUMERO MAGICO"<<endl;
        cout<<"********************************************************"<<endl;
        cout<<"Instrucciones: en este juego debes adivinar un numero secreto contenido entre 1 y 100, "<<endl;
        cout<<"para ello, dispones de 5 intentos. El sistema te ira dando pistas sobre lo cercano o "<<endl;
        cout<<"alejado que te encuentres de adivinar el numero magico. Utiliza con sabiduria tus 5 " <<endl;
        cout<<"intentos. Que la suerte este de tu lado\n\n";
        if(intentos==1){
            cout<<"Te queda "<<intentos<<" intento"<<endl;
        }else{
            cout<<"Te quedan "<<intentos<<" intentos"<<endl;
        }
        cout<<"Adivina el numero magico: ";
        cin>>numero; //Solicitamos al usuario que adivine el número secreto
        //Invocamos la función que determina si el usuario ha adivinado el número o no
        auxiliar = adivinar(numero, &cadena, &intentos);
        //Si el usuario ha adivinado el número, salimos del bucle
        if(auxiliar){
            break;
        }
        cout<<"\n"<<cadena<<endl;
        //Le mostramos al usuario las opciones para salir o continuar jugando
        cout<<"Pulse la tecla TAB para salir. Presione cualquier tecla para continuar."<<endl;
        /*Capturamos la tecla que el usuario ha presionado con la función getche() de la librería conio.h*/
        salir=getche();
        /*Utilizamos código ASCII para comparar la elección del usuario. A la tecla TAB le corresponde el
        número 9 en código ASCII. Si el usuario selecciona la tecla TAB, finalizamos el programa*/
        if(salir==9){
            cout<<"\n********************************************************"<<endl;
            cout<<"\tMuchas gracias por jugar al numero magico"<<endl;
            cout<<"********************************************************\n";
            return 0;
        }
    }while(auxiliar == false && intentos>0); /*El bucle do-while se repetirá mientras el usuario no adivine el número
    o mientras le queden intentos*/

    /*Si la función adivinar() nos retorna true, significa que el usuario ha adivinado el número y por tanto, ha ganado*/
    if (auxiliar){
        cout<<"\n********************************************************"<<endl;
        cout<<"\t\tFELICIDADES. HAS GANADO"<<endl;
        cout<<"********************************************************"<<endl;
    }else{ //De lo contrario, no adivinó y perdió
        cout<<"\nLo sentimos, no has logrado adivinar el numero magico. Te invitamos a que sigas participando\n\n";
    }
    return 0;
}

/*Función que contiene la lógica para saber si el usuario ha adivinado el número mágico o no. Recibe como parámetros:
el número ingresado por el usuario, la varible string que almacena las pistas y la variable contadora*/
bool adivinar (int numero, string *mensaje, int *contador){
    *contador-=1; //Disminuimos en 1 la variable contadora
    int numero_magico = 7; //Declaramos y almacenamos el número mágico
    if(numero==numero_magico){ //Si el número ingresado por el usuario es el mismo que el número mágico retornamos true
        return true;
    }else{
        if(numero>numero_magico){ //De lo contrario retornamos false y brindamos las pistas al usuario
            *mensaje = "El numero ingresado es mayor al numero magico";
        }else{
            *mensaje = "El numero ingresado es menor al numero magico";
        }
        return false;
    }
}