#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *enlace;
};

nodo *ptrCabeza = NULL;
nodo *ptrCola = NULL;

//Funcion para verificar si la cola esta vacio
bool estaVacia(){
    if( ptrCabeza == NULL && ptrCola == NULL)
        return true;
    else
        return false;
}

void encolar (int valor){
    nodo *nuevaCola = new nodo();
    nuevaCola->dato= valor;
    nuevaCola->enlace=NULL;
    //este if es para cuando solo hay 1 elemento, en ese caso nuestro puntero cola y cabeza apuntaran al mismo nodo
    if( ptrCabeza == NULL ){
        ptrCabeza = nuevaCola;
        ptrCola = nuevaCola;
    }
    else{  //en caso contrario el puntero cola ahora si apuntara al nuevo nodo creado(conceptualmente nuestra nueva cola)
        ptrCola -> enlace = nuevaCola;
        ptrCola = nuevaCola;
    }
}
void desencolar(){
    if ( estaVacia() ) //validamos el underflow
        cout<<"\nERROR el stack esta vacio";
    else{
        nodo *nodoTemporal = ptrCabeza; //en un nodo temporalle guardamos la direccion de la cabeza
        ptrCabeza = ptrCabeza -> enlace; //ahora la cima apuntara al siguiente nodo o conceptualmente al anterior
        delete(nodoTemporal); //liberamos memoria para eliminar el nodo 
    }
}
void mostrarCola(){
   if( estaVacia() ){
       cout <<"cola vacia";
   }else{
        nodo *temp=ptrCabeza;  //creamos un puntero temporal para almacenar cima
        cout<<"\nCOLA\n| ";
        while(temp!=NULL)  //el bucle se detendra cuando el puntero temp llegue al ultimo nodo ya que el ultimo nodo su enlace es null
        {   
            cout<< temp->dato <<" | "; //imprime el dato de la cima
            temp=temp->enlace; //asignamos a temporal el enlace siguiente para ir recorriendo el stack
        }
        cout<<"\n";
   }
}