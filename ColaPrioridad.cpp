#include <iostream>
using namespace std;

struct Node{
    int dato;
    int prioridad;
    Node *enlace;
};

Node *ptrCabeza = NULL;
Node *ptrCola = NULL;

//Function to check if queue is empty or not
bool estaVacia(){
    if( ptrCabeza == NULL && ptrCola == NULL)
        return true;
    else
        return false;
}
//function to enter elements in queue
void encolar ( int valor, int p ){
    
    Node *nuevaCola = new Node(); //creo nueva cola
    nuevaCola->dato= valor; //le insertamos el valor a la cola
    nuevaCola->prioridad=p; //le insertmos la priorioridad
    nuevaCola->enlace=NULL;
    Node *ptrAnterior=NULL;
    //este if es para cuando solo hay 1 elemento, en ese caso nuestro puntero cola y cabeza apuntaran al mismo nodo
    if( ptrCabeza == NULL ){
        ptrCabeza = nuevaCola;
        ptrCola = nuevaCola;
    }
    else{  //en caso contrario el puntero cola ahora si apuntara al nuevo nodo creado(conceptualmente nuestra nueva cola)
        while( nuevaCola->prioridad < ptrCola->prioridad && ptrCabeza->enlace!=NULL){
            ptrAnterior = ptrCola;
            ptrCola = ptrCola->enlace;          
        }
        nuevaCola->enlace=ptrAnterior->enlace;
        ptrAnterior->enlace=nuevaCola;
    }
}

void desencolar(){
    if ( estaVacia() ) //validamos el underflow
        cout<<"\nERROR el stack esta vacio testing";
    else
    if( ptrCabeza == ptrCola){
        delete(ptrCabeza);
        ptrCabeza = NULL;
        ptrCola = NULL;
    }else
    {
        Node *nodoTemporal = ptrCabeza; //en un nodo temporalle guardamos la direccion de la cabeza
        ptrCabeza = ptrCabeza -> enlace; //ahora la cima apuntara al siguiente nodo o conceptualmente al anterior
        delete(nodoTemporal); //liberamos memoria para eliminar el nodo 
    }
}
void displayStack()
{
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
        cout<<"\n1.encolar 2.Desencolar 3.mostrarCola 4.salir:  ";
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
            case 3: displayStack(); break;
            case 4: var = 0; break;
        }
    }
    return 0;
}