#include <iostream>
#include <iomanip> //Librería que nos servirá para redondear a dos decimales los resultados

using namespace std;

/*Declaramos los prototipos de las funciones a utilizar: una para realizar los cálculos 
de los salarios totales y otra para realizar los cálculos de los salarios reales*/
float calcular_salario_total(float horas_normales, float horas_extras, float *salario_total);
float calcular_salario_real(float salario_total, float *salario_real);

//Declaramos de manera global las constantes que nos servirán para realizar los cálculos de los descuentos
const float SEGURO = 0.04; 
const float AFP = 0.0625;
const float RENTA = 0.1;

//Inicio de la función main
int main(){
    int N=0; //variable que almacenará el número de usuarios
    string nombre;
    float horas_normales, horas_extras, salario_total, salario_real;

    cout<<"\n********************************************************";
    cout<<"\n\t\tCALCULO DE SALARIOS"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"Ingrese el numero de empleados: ";
    cin>>N;

    /*Realizamos una iteración con un ciclo for, en la cual, pediremos el nombre de cada empleado así como sus horas laboradas 
    e imprimeros en pantalla uno a uno su salario total y su salario real*/
    for(int i=0; i<N; i++){
        cout<<"\nIngrese el nombre del empleado #"<<i+1<<": ";
        cin>>nombre;
        cout<<"Ingrese el numero de horas normales laboradas: ";
        cin>>horas_normales;
        cout<<"Ingrese el numero de horas extras laboradas: ";
        cin>>horas_extras;

        /*Invocamos la función que calcula el salario real del empleado, para ello, le enviamos como argumentos
        por valor las horas normales y las horas extras laboradas, y por referencia le enviamos la variable que 
        almacenará el cálculo del salario total*/
        calcular_salario_total(horas_normales, horas_extras, &salario_total);

        /*Realizamos la impresión en pantalla del salario total. Utilizamos las funciones fixed y setprecision de 
        la librería iomanip para redondear los resultados a dos decimales*/
        cout<<"\n->El salario TOTAL del empleado "<<nombre<<" es: $"<<fixed<<setprecision(2)<<salario_total<<endl;

        /*En una misma linea de instrucciones mandamos a llamar la función que calcula los descuentos al salario total
        e imprimimos en pantalla el salario real. Enviamos como argumentos a la función el salario total calculado anteriormente, 
        y la variable que almacenará el cálculo del salario real.*/
        cout<<"->El salario REAL del empleado "<<nombre<<" es: $"<<fixed<<setprecision(2)<<calcular_salario_real(salario_total, &salario_real);
        cout<<"\n\n";
        system("pause");
        cout<<"\n";
        cout<<"********************************************************";
        cout<<"\n";
    }
    cout<<" GRACIAS POR UTILIZAR NUESTRO PROGRAMA, EDDY S.A DE C.V"<<endl;
    cout<<"********************************************************";
    return 0;
}

/*Función que calcula el salario total de los empleados. Recibe las horas normales y horas extras trabajadas
y retorna el cálculo del salario real*/
float calcular_salario_total(float horas_normales, float horas_extras, float *salario_total){
    *salario_total=(horas_normales*1.75)+(horas_extras*2.5);
    return *salario_total;
}

/*Función que calcula el salario real de los empleados. Recibe el salario total y retorna el salario real*/
float calcular_salario_real(float salario_total, float *salario_real){
    if(salario_total>500){
        *salario_real = salario_total - ((salario_total*SEGURO) + (salario_total*AFP) + (salario_total*RENTA));
    }else{
        *salario_real = salario_total - ((salario_total*SEGURO) + (salario_total*AFP));
    }
    return *salario_real;
}