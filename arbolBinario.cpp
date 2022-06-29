/* 
Gama Ponce Said Arturo
Grupo: 2CV6
Carrera: Ingenieria en Sistemas Computacionales    
Ultima modificacion 18/06/22
Examen 3er parcial implementacion de arbol binario
*/
#include<iostream>
using namespace std;
//consutrccion de un nodo
struct nodo{
	int elemento;
	nodo* izq;
	nodo* der;
};
//funcion para crear una raiz se rellena con su elemento y sus puntero en nulo y retorna la direccion de esa raiz/nodo
nodo* crearRaiz(int elem){
	nodo* nodito = new nodo();
	nodito->elemento = elem;
	nodito->izq = NULL;
	nodito->der = NULL;
	return nodito;
}
//funcion para buscar nodo
nodo* buscarNodo(nodo* raiz, int key){
    if(raiz != NULL){  //si raiz en distinto a nulo entonces entrara a la busqueda si no, el nodo no existe y retorna nulo
        if(key == raiz->elemento){  //una ves hecha la recursion el valor encontrado se validara en este if y retorna la direccion del nodo encontrado
            return raiz;
        }else if( key > raiz->elemento){
            return buscarNodo(raiz->der,key);
        }else if(key < raiz->elemento){
            return buscarNodo(raiz->izq,key);
        }
    }
	return nullptr;
	//cout<<"\nEl nodo a buscar NO existe!\n";
}
nodo * insertarnodo(int elemto, nodo * raiz) {
	nodo *existente = buscarNodo(raiz,elemto); //variable auxiliar para validar nodos repetidos
	if( existente!=nullptr ){  //si al buscar el nodo nos retorna una direccion significa que el nodo ya existe por lo tanto no se insertara
		cout<<"\nEse nodo ya existe en el arbol!";
	}else{
		if (raiz == NULL) {  //una ves asignado el lugar, se crea una raiz/nodo con sus respectivos elementos
		return crearRaiz(elemto);
		}
		if (elemto < raiz -> elemento) {
			raiz -> izq = insertarnodo(elemto, raiz -> izq);
		}
		if (elemto > raiz -> elemento) {
			raiz -> der = insertarnodo(elemto, raiz -> der);
		}
		return raiz;  
	}
}
//esta funcion nos retorna la direccion del nodo con el valor minimo del arbol  o desde la raiz dicha que sera de ayuda para eliminar
nodo* masPequeno(nodo* nodito){
    nodo* Actual = nodito;
    while (Actual && Actual->izq != NULL) //el bucle se ejecuta mientras actual no sea nulo y su hijo izq tenga una direccion
        Actual = Actual->izq;  //se va hacia toda la izquierda
 
    return Actual; 
}
//funcion para eliminar nodo
nodo* eliminarNodo(nodo* raiz, int key){
    if (raiz == NULL){
        return raiz;
	}
	//esta parte es para buscar el nodo a eliminar
    if (key < raiz->elemento)
        raiz->izq = eliminarNodo(raiz->izq, key);
    else if (key > raiz->elemento)
        raiz->der = eliminarNodo(raiz->der, key);

    else {
        if (raiz->izq == NULL) {  //caso si tiene hijo derecho
            nodo* temp = raiz->der;
            delete(raiz);
            return temp;
        }
        else if (raiz->der == NULL) {  //caso si tiene hijo izquierdo
            nodo* temp = raiz->izq;
            delete(raiz);
            return temp;
        }
        // caso 2 hijos 
        nodo* temp = masPequeno(raiz->der);  //guardamos el valor minimo que haya despues del hijo izquierdo de la raiz actual
        raiz->elemento = temp->elemento; //se copio ese valor a la raiz
        raiz->der = eliminarNodo(raiz->der, temp->elemento);  //se eliminara el hijo izq y lo que retorna se asignara en hijo derecha
    }
    return raiz;
}
//imprime en preorder
void preorder(nodo * raiz) {
  if (raiz != NULL) {
    cout << raiz -> elemento << ", ";
    preorder(raiz -> izq);
    preorder(raiz -> der);
  }
}
//imprime en inorder
void inorder(nodo * raiz) {
  if (raiz != NULL) {
    inorder(raiz -> izq);
	cout << raiz -> elemento << ", ";
    inorder(raiz -> der);
  }
}
//imprime en postorder
void postorder(nodo * raiz) {
  if (raiz != NULL) {
    postorder(raiz -> izq);
    postorder(raiz -> der);
	cout << raiz -> elemento << ", ";
  }
}
int main(){
	int elem, opc,eleraiz; bool flag=true;
	nodo* raiz = new nodo; nodo *eli=nullptr;
	cout << "\ningresa el nodo raiz: ";
  	cin >> eleraiz;
  	raiz = crearRaiz(eleraiz);
	while(flag){
		cout<<"\n 1. INSERTAR NODO  2. BUSCAR NODO  3. ELIMINAR  4. PREORDER  5. INORDER  6. POSTORDER  7. SALIR :";
		cin>>opc;
		switch (opc){
		case 1:
			cout<<"\nIngresa la key del nodo a insertar: ";
			cin>>elem;
			insertarnodo(elem,raiz);
		break;
		case 2:
			cout<<"\nIngresa la key del nodo a buscar: ";
			cin>>elem;
			if( buscarNodo(raiz,elem) != nullptr){
				cout<<"\nEl nodo a buscar SI existe!";
				eli = buscarNodo(raiz,elem);
				cout<<"\nDireccion y valor del nodo encontrado "<<"direccion: "<<eli<<" key: "<<eli->elemento<<endl;
			}else{
				cout<<"\nEl nodo a buscar no existe!\n";
			}
			
		break;
		case 3:
			cout<<"\nIngresa la key del nodo a eliminar: ";
			cin>>elem;
			eli = buscarNodo(raiz,elem);
			if(eli != nullptr ){
				cout<<"\nDireccion y valor del nodo eliminado "<<"direccion: "<<eli<<" key: "<<eli->elemento<<endl;
				eliminarNodo(raiz,elem);
			}else{ cout<<"\nEl nodo a eliminar no existe!\n"; }
		break;
		case 4:
			cout<<"\n---------------------------------------------------------------------------------------\n";
			cout<<"recorrido en preorder : "; 
			preorder(raiz);
			cout<<"\n---------------------------------------------------------------------------------------\n";
		break;
		case 5:
			cout<<"\n---------------------------------------------------------------------------------------\n";
			cout<<"recorrido en inorder : "; 
			inorder(raiz);
			cout<<"\n---------------------------------------------------------------------------------------\n";
		break;
		case 6:
			cout<<"\n---------------------------------------------------------------------------------------\n";
			cout<<"recorrido en postorder : "; 
			postorder(raiz);
			cout<<"\n---------------------------------------------------------------------------------------\n";
		break;
		case 7: flag=false; break;
		
		}
	}
    return 0;
}