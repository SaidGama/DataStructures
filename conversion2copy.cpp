#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node{
   int key;
   vector<Node*> array; //array que guarda punteros
   Node *izq=NULL;
   Node *der=NULL;
};

// funcion crear nodo
Node *crearNodo(int key){
    Node *nuevoNodo = new Node;
    nuevoNodo->key = key;
    return nuevoNodo;
}

//funcion para convertir un arbol general a binario
Node *convertir(Node* raiza){
    if (!raiza)
      return nullptr;

    Node *raiz = new Node();
    raiz = raiza; 
    if (raiza->array.size()){   //valida si el array esta vacio es decir si existen hijos en esa raiz
        raiz->izq = convertir(raiza->array[0]);   
    }
    // una ves asignado el hijo izquierdo ese sera el nodo actual para ahora asignar los hermanos del actual a su puntero derecho
    Node *nodoActual = raiz->izq;

    for (int i=1; i<raiza->array.size(); i++){  //este for se ejecutara conforme al tamano actual del array, este cambiara ya que depende cuantos hijos tenga la raiz
        nodoActual->der = convertir(raiza->array[i]);
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

    raiz->array.push_back(crearNodo(1));
    raiz->array.push_back(crearNodo(2));
    raiz->array.push_back(crearNodo(3));
    //hIJOS de "1"
    raiz->array[0]->array.push_back(crearNodo(8));  //primer hijo de 1 
    raiz->array[0]->array.push_back(crearNodo(8)); //segundo hijo de 2 

    //hIJOS de "2"
    raiz->array[1]->array.push_back(crearNodo(8));
    raiz->array[1]->array.push_back(crearNodo(8));

    convertir(raiz);
    inorder(raiz);
    
    return 0;
}