#include <iostream>
using namespace std;

struct Node{
    int dato;
    int prioridad;
    Node *enlace;
};

Node *ptrCabeza = NULL;
Node *ptrCola = NULL;

//Funcion para verificar si la cola esta vacio
bool estaVacia(){
    if( ptrCabeza == NULL && ptrCola == NULL)
        return true;
    else
        return false;
}
void encolar(int valor, int p){
    
    Node *nuevaCola = new Node(); //creo nueva cola
    nuevaCola->dato= valor; //le insertamos el valor a la cola
    nuevaCola->prioridad=p; //le insertmos la priorioridad
    //este if es para cuando no hay ningun nodo, en ese caso insertamos el nodo al principio
    if( ptrCabeza == NULL || p <= ptrCabeza->prioridad){
        nuevaCola->enlace=ptrCabeza;
        ptrCabeza = nuevaCola;
    }else{
        ptrCola = ptrCabeza;
        while (ptrCola->enlace!=NULL && ptrCola->enlace->prioridad<=p)
        {
            ptrCola = ptrCola->enlace;
        }
        nuevaCola->enlace = ptrCola->enlace;
        ptrCola->enlace = nuevaCola;
    }
}

void desencolar(){
    if ( estaVacia() ) //validamos el underflow
        cout<<"\nERROR el stack esta vacio testing";
    else{
        Node *temporal = ptrCabeza;
        ptrCabeza = ptrCabeza->enlace;
        delete(temporal);
    }
    
}
void mostrarCola(){
   if( estaVacia() ){
       cout <<"cola vacia";
   }else{
        Node *temp=ptrCabeza;  //creamos un puntero temporal para almacenar cima
        cout<<"\nCOLA\n| ";
        while(temp!=NULL)  //el bucle se detendra cuando el puntero temp llegue al ultimo nodo ya que el ultimo nodo su enlace es null
        {   
            cout<< temp->dato <<" | "; //imprime el dato de la cima
            temp=temp->enlace; //asignamos a temporal el enlace siguiente para ir recorriendo el stack
        }
        cout<<"\n";
   }
}
int main(){
    int opcion, var=1, valor,prioridad;
    while( var == 1){
        cout<<"\n1.Encolar 2.Desencolar 3.mostrarCola 4.salir:  ";
        cin>>opcion;
        switch (opcion){
            case 1: 
                cout<<"Introduzca el dato:\n";  
                cin>>valor; 
                cout<<"Introduzca la prioridad:\n";  
                cin>>prioridad; 
                encolar(valor,prioridad); 
            break;
            case 2: desencolar(); break;         
            case 3: mostrarCola(); break;
            case 4: var = 0; break;
        }
    }
    return 0;
}