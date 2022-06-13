#include <iostream>
using namespace std;

struct Node{
   int key;
   Node *arrayHijos[5]; //array de punteros, un nodo podra tener como maximo 5 hijos
   Node *izq=NULL;
   Node *der=NULL;
};

// funcion crear nodo
Node *crearNodo(int key){
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
Node *encode(Node* raiza){
    if (!raiza)
      return nullptr;

    Node *raiz = new Node();
    raiz = raiza; //al nuevo nodo se le asigna el nodo que ingresa a la funcion para que el nuevo nodo tenga los atributos de la raiz que llega
    //es decir copiar a raiza y pegarlo al nuevo nodo creado

    //este bloque hace que el primer hijo del array( es decir "el mas izquierdo") se guarde en el puntero izq de su padre
    if (raiza->arrayHijos[0]!=NULL){   //valida si el array esta vacio es decir si existen hijos en esa raiz
        raiz->izq = encode(raiza->arrayHijos[0]);   
    }
    // una ves asignado el hijo izquierdo ese sera el nodo actual para ahora asignar los hermanos del actual a su puntero derecho
    Node *nodoActual = raiz->izq;

    for (int i=1; i<longitudArray(raiza); i++){  //este for se ejecutara conforme al tamano actual del array, este cambiara ya que depende cuantos hijos tenga la raiz
        nodoActual->der = encode(raiza->arrayHijos[i]);
        nodoActual = nodoActual->der; 
    }
    return raiz;
}

void inorder(Node* raiz){
    if (raiz != NULL) {
        cout<<raiz->key<<" ";
        inorder(raiz->izq);
        inorder(raiz->der);
    }
}

int main(){
    //creacion de un arbol general
    Node *raiz = crearNodo(5);
    raiz->arrayHijos[0] = crearNodo(1);
    raiz->arrayHijos[1] = crearNodo(7);
    raiz->arrayHijos[2] = crearNodo(8);
    raiz->arrayHijos[0]->arrayHijos[0] = crearNodo(9); 
    raiz->arrayHijos[2]->arrayHijos[0] = crearNodo(14); 
    raiz->arrayHijos[0]->arrayHijos[0]->arrayHijos[0] = crearNodo(18); 
    raiz->arrayHijos[0]->arrayHijos[0]->arrayHijos[1] = crearNodo(21); 
    raiz->arrayHijos[0]->arrayHijos[0]->arrayHijos[2] = crearNodo(78); 
    //funcion para convertir el arbol general a binario dada la raiz del arbol general
    encode(raiz);
    //recorre el arbol binario convertido en preorder
    inorder(raiz);
    return 0;
}