#include <iostream>
using namespace std;

int tam = 0;

struct Node
{
  int dato;
  Node *enlace;
} *cima = NULL;

//Funcion para validar si el stack esta vacio
bool
estaVacio ()
{
  if (cima == NULL)		//si cima apunta a nada entonces el stack esta vacio
    return true;
  else
    return false;
}

void
push (int valor, int size)
{
  Node *nuevoNodo = new Node ();	//asignamos memoria para el nuevo nodo
  tam++;
  if (nuevoNodo == NULL || tam > size)
    {
      cout << "Stack LLENO";
    }
  nuevoNodo->dato = valor;	//ponemos el valor al nuevo Nodo
  nuevoNodo->enlace = cima;	//asignamos al enlace del nuevo nodo la direccion de la cima del "anterior" nodo, de esta forma "enlazamos el nuevo nodo al stack"
  cima = nuevoNodo;		//ahora hacemos que la cima guarde la direccion del nuevo nodo(que ahora se el primero)
}

void
pop ()
{
  if (estaVacio ())		//validamos el underflow
    cout << "\nERROR el stack esta vacio";
  else
    {
      Node *nodoTemporal = cima;	//al nodo temporal se le asigna el valor de cima
      cima = cima->enlace;	//ahora la cima apuntara al siguiente nodo o conceptualmente al anterior
      delete (nodoTemporal);	//liberamos memoria para eliminar el nodo 
    }
}

void
displayStack ()
{
  if (estaVacio ())
    cout << "\nStack esta vacio";
  else
    {
      Node *temp = cima;	//creamos un puntero temporal para almacenar cima
      cout << "\nSTACK\n";
      while (temp != NULL)	//el bucle se detendra cuando el puntero temp llegue al ultimo nodo ya que el ultimo nodo su enlace es null
	{
	  cout << "----\n";
	  cout << temp->dato << "\n";	//imprime el dato de la cima
	  temp = temp->enlace;	//asignamos a temporal el enlace siguiente para ir recorriendo el stack
	}
      cout << "----\n";
      cout << "\n";
    }
}

int
main ()
{

  int opcion, var = 1, valor,size;
  cout << "Introduzca el tamano:\n";
  cin >> size;
  while (var == 1)
    {
      cout << "\n1.Push 2.Pop 3.mostrarStack 4.salir:  ";
      cin >> opcion;
      switch (opcion)
	{
	case 1:
	  cout << "Introduzca el dato:\n";
	  
	  cin >> valor;
	  push (valor,size);
	  break;
	case 2:
	  pop ();
	  break;
	case 3:
	  displayStack ();
	  break;
	case 4:
	  var = 0;
	  break;
	}
    }
  return 0;
}
