/* 
Gama Ponce Said Arturo
Grupo: 2CV6
Carrera: Ingenieria en Sistemas Computacionales    
Ultima modificacion 17/06/22
Practica 4 Conversion de arbol general a binario
*/
#include <iostream>
#include <list> 
using namespace std;

struct Node{
   string key;
   Node *arrayHijos[5]; //array de punteros, un nodo podra tener como maximo 4 hijos
   Node *izq=NULL;
   Node *der=NULL;
};

// funcion crear nodo
Node *crearNodo(string key){
    Node *nuevoNodo = new Node;
    nuevoNodo->key = key;
    for (int i = 0; i<5; i++){
        nuevoNodo->arrayHijos[i] = NULL; //rellena el array que contiene cada nodo con valores nulos
    }
    return nuevoNodo;
}
//funcion para saber la longitud de un array 
int longitudArray(Node *raiza){
    int count=0;
    for(int i=0; i<5; i++){
        if(raiza->arrayHijos[i] != NULL){
            count ++;
        }
    }
    return count; 
}
//funcion para convertir un arbol general a binario
Node *convertir(Node* raiza){
    if (!raiza){
        return nullptr;
    }
    Node *raiz = new Node();
    raiz = raiza; //al nuevo nodo se le asigna el nodo que ingresa a la funcion para que el nuevo nodo tenga los atributos de la raiz que llega
    //es decir copiar a raiza y pegarlo al nuevo nodo creado

    //este bloque hace que el primer hijo del array( es decir "el mas izquierdo") se guarde en el puntero izq de su padre
    if (raiza->arrayHijos[0]!=NULL){   //valida si el array esta vacio es decir si existen hijos en esa raiz
        raiz->izq = convertir(raiza->arrayHijos[0]);   
    }
    // una ves asignado el hijo izquierdo ese sera el nodo actual para ahora asignar los hermanos del actual a su puntero derecho
    Node *nodoActual = raiz->izq;

    for (int i=1; i<longitudArray(raiza); i++){  //este for se ejecutara conforme al tamano actual del array, este cambiara ya que depende cuantos hijos tenga la raiz
        nodoActual->der = convertir(raiza->arrayHijos[i]);
        nodoActual = nodoActual->der; 
    }
    return raiz;
}

void imprimirAnchura(Node* raiz){
    //se crea una cola
    list<Node*> cola;
    cola.push_back(raiz); //se encola el nodo raiz
    //este puntero almacenara el nodo actual
    Node* NodoActual = nullptr;
    // el while se rompe cuando la cola este vacia
    while (cola.size()) {
        NodoActual = cola.front(); //el nodo actual sera el nodo que estara hasta delante en la cola
        cola.pop_front(); //se desencola el nodo una ves que ya se guardo en el puntero 
        cout<< NodoActual->key << " "; //se imprime el valor del nodo actual
        if (NodoActual->izq) { //este if verifica si el nodo actual tiene hijo izq, si lo tiene lo agrega a la cola para que posteriormente sea el nodo actual
            cola.push_back(NodoActual->izq);
        }
        if (NodoActual->der) {  //este if verifica si el nodo actual tiene hijo der, si lo tiene lo agrega a la cola para que posteriormente sea el nodo actual
            cola.push_back(NodoActual->der);
        }
    }
}
Node *crearArbolGeneral(){
    Node *raiz = crearNodo("A");
    raiz->arrayHijos[0] = crearNodo("B");
    raiz->arrayHijos[1] = crearNodo("F");
    raiz->arrayHijos[2] = crearNodo("C");

    raiz->arrayHijos[0]->arrayHijos[0] = crearNodo("D"); 
    raiz->arrayHijos[0]->arrayHijos[1] = crearNodo("E"); 

    raiz->arrayHijos[1]->arrayHijos[0] = crearNodo("J"); 
    raiz->arrayHijos[1]->arrayHijos[1] = crearNodo("I"); 
    raiz->arrayHijos[1]->arrayHijos[2] = crearNodo("K");

    raiz->arrayHijos[2]->arrayHijos[0] = crearNodo("G");
    raiz->arrayHijos[2]->arrayHijos[1] = crearNodo("L");
    raiz->arrayHijos[2]->arrayHijos[2] = crearNodo("H");
    raiz->arrayHijos[2]->arrayHijos[3] = crearNodo("J");
    return raiz;
}
int main(){
    bool flag=true; int opc;
    Node *arbol = nullptr;
    while (flag){
        cout<<"\n1. Crear arbol general  2. Convertir a Binario  3. Desplegar Arbol binario en anchura  4. Salir : ";
        cin>>opc;
		switch (opc){
		case 1:
			arbol = crearArbolGeneral();
            cout<<"\nArbol general creado!\n";
		break;
        case 2:
            convertir(arbol);
            cout<<"\nEl arbol general se ha convertido a binario!\n";
        break;
        case 3:
            cout<<"\nArbol binario recorrido en anchura: ";
            imprimirAnchura(arbol); cout<<endl;
        break;
        case 4: flag=false; break;
		}
	}
    return 0;
}