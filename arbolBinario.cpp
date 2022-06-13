#include<iostream>

using namespace std;

struct nodo{
	int elemento;
	nodo* izq = NULL;
	nodo* der = NULL;
	string data;
};

nodo* crearRaiz(int elem){
	nodo* nodito = new nodo();
	nodito->elemento = elem;
	return nodito;
}

void insertarNodo(int elem, nodo*raiz){
	if (elem < raiz->elemento && raiz->izq == NULL){
        nodo * nodote = new nodo;
		raiz->izq = nodote;
	}else if(raiz->izq != NULL){
		insertarNodo(elem, raiz->izq);
	}
	if (elem > raiz->elemento && raiz->der == NULL){
		nodo * nodote = new nodo;
		raiz->der = nodote;
	}else if(raiz->der != NULL){
		insertarNodo(elem, raiz->der);
	}
}

void inorder(nodo* raiz)
{
    if (raiz != NULL) {
        inorder(raiz->izq);
        printf("%d \n", raiz->elemento);
        inorder(raiz->der);
    }
}

int main(){
	int elem, opc,flag;
	nodo* raiz = new nodo;
    raiz = crearRaiz(3);
	while (flag)
	{
		switch (opc)
		{
		case 1:
			/* code */
			break;
		
		default:
			break;
		}
	}
	

    return 0;
}