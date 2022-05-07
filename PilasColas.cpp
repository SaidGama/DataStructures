#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int opcion,var=1;
    int opcion2,var2=1,valor;
    int opcion3,var3=1,valor2;
    int opcion4, var4=1, valor3,prioridad;
    while(var == 1){
        cout<<"\n1. Stack Dinamico  2. Cola Dinamica 3. Cola de Prioridad 4. Salir del Programa: ";
        cin>>opcion;
        switch(opcion){

            case 1:
            while( var2 == 1){
            cout<<"\n1.Pushear 2.Pop 3.mostrarStack 4.Volver al menu principal:  ";
            cin>>opcion2;
                switch (opcion2){
                    case 1: cout<<"Introduzca el dato:\n";  cin>>valor; push(valor); break;
                    case 2: pop(); break;         
                    case 3: displayStack(); break;
                    case 4: var2 = 0; break;
                }
            }   
            break;
            case 2:
            while( var3 == 1){
            cout<<"\n1.encolar 2.Desencolar 3.mostrarCola 4.Volver al menu principal:  ";
            cin>>opcion3;
                switch (opcion3){
                    case 1: cout<<"Introduzca el dato:\n";  cin>>valor2; encolar(valor2); break;
                    case 2: desencolar(); break;         
                    case 3: mostrarCola(); break;
                    case 4: var3 = 0; break;
                }
            }   
            break;
            case 3:
            while( var4 == 1){
                cout<<"\n1.Encolar 2.Desencolar 3.mostrarCola 4.salir:  ";
                cin>>opcion4;
                switch (opcion4){
                    case 1: 
                        cout<<"Introduzca el dato:\n";  
                        cin>>valor3; 
                        cout<<"Introduzca la prioridad:\n";  
                        cin>>prioridad; 
                        encolarPrioridad(valor3,prioridad); 
                    break;
                    case 2: desencolar2(); break;         
                    case 3: mostrarCola2(); break;
                    case 4: var4 = 0; break;
                }
            }
            break;
            case 4: var = 0; break;
        }
        
    }
    return 0;
}