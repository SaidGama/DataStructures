#include <iostream>
using namespace std;

struct nodo1{
    int dato;
    nodo1 *enlace;
} *cima=NULL;

struct nodo2{
    int dato;
    nodo2 *enlace;
};
struct Node{
    int dato;
    int prioridad;
    Node *enlace;
};

nodo2 *ptrCabeza = NULL;
nodo2 *ptrCola = NULL;

Node *ptrCabeza2 = NULL;
Node *ptrCola2 = NULL;

//Funcion para validar si el stack esta vacio
bool estaVacio(){
    if(cima == NULL) //si cima apunta a nada entonces el stack esta vacio
        return true; 
    else
        return false;
}
//Funcion para verificar si la cola esta vacio
bool estaVacia(){
    if( ptrCabeza == NULL && ptrCola == NULL)
        return true;
    else
        return false;
}

void push (int valor){
    nodo1 *nuevoNodo = new nodo1(); //asignamos memoria para el nuevo nodo
    if(nuevoNodo == NULL){
        cout << "Stack OVERFLOW";
    }
    nuevoNodo->dato = valor; //ponemos el valor al nuevo Nodo
    nuevoNodo->enlace = cima; //asignamos al enlace del nuevo nodo la direccion de la cima del "anterior" nodo, de esta forma "enlazamos el nuevo nodo al stack"
    cima = nuevoNodo; //ahora hacemos que la cima guarde la direccion del nuevo nodo(que ahora se el primero)
}   
void pop (){
    if ( estaVacio() ) //validamos el underflow
        cout<<"\nERROR el stack esta vacio";
    else
    {
        nodo1 *nodoTemporal = cima; //al nodo temporal se le asigna el valor de cima
        cima = cima -> enlace; //ahora la cima apuntara al siguiente nodo o conceptualmente al anterior
        delete(nodoTemporal); //liberamos memoria para eliminar el nodo 
    }
}
void encolar (int valor){
    nodo2 *nuevaCola = new nodo2();
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
void encolarPrioridad(int valor, int p){
    
    Node *nuevaCola = new Node(); //creo nueva cola
    nuevaCola->dato= valor; //le insertamos el valor a la cola
    nuevaCola->prioridad=p; //le insertmos la priorioridad
    //este if es para cuando no hay ningun nodo, en ese caso insertamos el nodo al principio
    if( ptrCabeza2 == NULL || p <= ptrCabeza2->prioridad){
        nuevaCola->enlace=ptrCabeza2;
        ptrCabeza2 = nuevaCola;
    }else{
        ptrCola2 = ptrCabeza2;
        while (ptrCola2->enlace!=NULL && ptrCola2->enlace->prioridad<=p)
        {
            ptrCola2 = ptrCola2->enlace;
        }
        nuevaCola->enlace = ptrCola2->enlace;
        ptrCola2->enlace = nuevaCola;
    }
}
void desencolar(){
    if ( estaVacia() ) //validamos el underflow
        cout<<"\nERROR el stack esta vacio";
    else{
        nodo2 *nodoTemporal = ptrCabeza; //en un nodo temporalle guardamos la direccion de la cabeza
        ptrCabeza = ptrCabeza -> enlace; //ahora la cima apuntara al siguiente nodo o conceptualmente al anterior
        delete(nodoTemporal); //liberamos memoria para eliminar el nodo 
    }
}
void desencolar2(){
    if ( estaVacia() ) //validamos el underflow
        cout<<"\nERROR el stack esta vacio testing";
    else{
        Node *temporal = ptrCabeza2;
        ptrCabeza2 = ptrCabeza2->enlace;
        delete(temporal);
    }
    
}
void mostrarCola(){
   if( estaVacia() ){
       cout <<"cola vacia";
   }else{
        nodo2 *temp=ptrCabeza;  //creamos un puntero temporal para almacenar cima
        cout<<"\nCOLA\n| ";
        while(temp!=NULL)  //el bucle se detendra cuando el puntero temp llegue al ultimo nodo ya que el ultimo nodo su enlace es null
        {   
            cout<< temp->dato <<" | "; //imprime el dato de la cima
            temp=temp->enlace; //asignamos a temporal el enlace siguiente para ir recorriendo el stack
        }
        cout<<"\n";
   }
}
void mostrarCola2(){
   if( estaVacia() ){
       cout <<"cola vacia";
   }else{
        Node *temp=ptrCabeza2;  //creamos un puntero temporal para almacenar cima
        cout<<"\nCOLA\n| ";
        while(temp!=NULL)  //el bucle se detendra cuando el puntero temp llegue al ultimo nodo ya que el ultimo nodo su enlace es null
        {   
            cout<< temp->dato <<" | "; //imprime el dato de la cima
            temp=temp->enlace; //asignamos a temporal el enlace siguiente para ir recorriendo el stack
        }
        cout<<"\n";
   }
}
void displayStack()
{
    if ( estaVacio() )
        cout<<"\nStack esta vacio";
    else
    {
        nodo1 *temp=cima;  //creamos un puntero temporal para almacenar cima
        cout<<"\nSTACK\n";
        while(temp!=NULL)  //el bucle se detendra cuando el puntero temp llegue al ultimo nodo ya que el ultimo nodo su enlace es null
        {   
            cout <<"----\n";
            cout<< temp->dato <<"\n"; //imprime el dato de la cima
            temp=temp->enlace; //asignamos a temporal el enlace siguiente para ir recorriendo el stack
        }
        cout <<"----\n";
        cout<<"\n";
    }
}