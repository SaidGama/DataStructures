#include <iostream>
#include <vector>
using namespace std;

struct Node{
   int key;
   vector<Node *> arrayHijos; //array de punteros
   Node *izq=NULL;
   Node *der=NULL;
};

// funcion crear nodo
Node *crearNodo(int key){
   Node *temp = new Node;
   temp->key = key;

   return temp;
}

Node *encode(Node* raiza) {

    if (!raiza)
      return nullptr;

    Node *raiz = new Node();
    raiz = raiza; //al nuevo nodo se le asigna el nodo que ingresa a la funcion para que el nuevo nodo tenga los atributos de la raiz que llega
    //es decir copiar a raiza y pegarlo al nuevo nodo creado

    //este bloque hace que el primer hijo del array( es decir "el mas izquierdo") se guarde en el puntero izq de su padre
    if (!raiza->arrayHijos.empty()){
        raiz->izq = encode(raiza->arrayHijos[0]);   
    }
    // una ves asignado el hijo izquierdo ese sera el nodo actual para ahora asignar los hermanos del actual a su puntero derecho
    Node *nodoActual = raiz->izq;
    cout<<"longitud del array1: "<<raiza->arrayHijos.size()<<"\n";
    // encode the rest of the children
    for (int i = 1; i < raiza->arrayHijos.size(); ++i) {
      cout<<"longitud del array2: "<<raiza->arrayHijos.size()<<"\n";
      nodoActual->der = encode(raiza->arrayHijos[i]);
      nodoActual = nodoActual->der; 
    }
    
    return raiz;
}


Node *convertir(Node *raiz){

    raiz->izq = raiz->arrayHijos[0];
    if( raiz->arrayHijos[0] != NULL){
        raiz->izq = convertir(raiz->arrayHijos[0]);
    } 


}
void inorder(Node* raiz)
{
    if (raiz != NULL) {
        cout<<raiz->key<<" ";
        inorder(raiz->izq);
        inorder(raiz->der);
    }
}

int main(){
    Node *raiz = crearNodo(5);
    raiz->arrayHijos.push_back(crearNodo(1)); //agrega la direccion al array de hijos
    raiz->arrayHijos.push_back(crearNodo(7));
    raiz->arrayHijos.push_back(crearNodo(8));
    (raiz->arrayHijos[0]->arrayHijos).push_back(crearNodo(9));
    encode(raiz);
    inorder(raiz);
    return 0;

}






