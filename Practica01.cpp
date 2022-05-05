/* 
Gama Ponce Said Arturo
Grupo: 2CV6
Carrera: Ingenieria en Sistemas Computacionales    
Ultima modificacion 09/03/22
Practica 1 implementacion de los algoritmos de ordenamiento
*/
#include <iostream>
#include <cstdlib>  //librerias a usar
using namespace std;

void imprimir(int* array){
    cout << "[";
    for (int i = 0; i<7; i++){
        cout<< array[i]<<",";   //funcion para imprimir un array
    }
    cout << "]\n";
}
void ordenarBurbuja(int* array){
    for (int k = 0; k<7; k++){   //se hace el bucle 7 veces para repetir todo el proceso con los 7 numeros del array
        for (int z = 0; z<7-1; z++){   //este bucle es para repetir los intercambios y mandar hasta al final el mas grande
            if (array[z]>array[z+1]){  //comparamos si la posicion inicial es mayor que la siguiente, si cumple hace el intercambio si no se sigue
                int aux = array[z];    //usamos el auxiliar para guardar el valor temporalmente de la primera posicion y asi volver a asignarlo a n+1
                array[z]=array[z+1];   //estas 3 lineas son para realizar el intercambio
                array[z+1]=aux; 
                imprimir(array); //se imprime cada iteracion
            }
        }
        cout <<"\n";
    }
}
void ordenarSeleccion(int* array){
    int minimo,aux1;
    for (int q = 0; q<7; q++){
        minimo=q;   //suponemos que el numero mas pequeno esta en la primera posicion
        for (int o = q; o<7; o++){
            if (array[o] < array[minimo]){  //hacemos comparaciones para buscar al numero menor
                minimo = o; //se van asignando numeros como minimos pero cuando el for acabe "o" sera la posicion del numero menor y la guardamos
            }    
        }
        aux1=array[q];   //guardamos temporalmente el valor de la primera posicion
        array[q]=array[minimo];  //intercambiamos el valor de la primera posicion con el numero minimo
        array[minimo]=aux1;  //como guardamos la posicion temporal la intercambiamos a donde estaba el numero mas pequeno
        imprimir(array); //se imprime cada iteracion                
    }
}
void ordenarInsercion(int* array){
    int aux2,g;
    for(int h=1; h<7; h++){
        aux2 = array[h]; //sera el valor auxiliar a comparar con el num de la izquierda
        g = h; //g indicara la posicion de la izquierda
        while(g>0 && array[g-1]>aux2){  //bucle que se repite mientran g sea mayor a cero y el valor del indice izquierdo sea mayor al de la derecha
            array[g] = array[g-1]; //intercambio de valores temporal
            g = g-1; //decrementamos el valor de g para asegurarnos que cuando se encuentre un numero mayor no continue el while
        }
        array[g] = aux2; //cuando g se hace 0 hacemos el intercambio ya final
        imprimir(array); //se imprime cada iteracion
    }
}
void mezcla(int *array, int inicio, int mitad, int final) {
	int temp[final-inicio+1]; //declaramos el array auxiliar y su tamano 
    //declaramos los indices a usar, un indice para el lado IZQ y otro para el Derecho
    //ademas de un indice AUX a usar para el array auxiliar que se inicia en 0 
    //indice izq se inicializa en inicio ya que sera la parte inicial de cada particion 
    //indice der se inicializa en mitad+1 ya desde esa posicion empieza el lado derecho en cada particion
	int indiceIZQ=inicio, indiceDER=mitad+1, indiceAUX = 0;
    //este bucle compara y ordena los lados izquierdos y derechos y acaba cuando se llega al indice final de ambos lados izq y derecho
	while(indiceIZQ <= mitad && indiceDER <= final){
		if(array[indiceIZQ] < array[indiceDER]) { //aqui se hace la comparacion para ver cual es menor entre el lado izq o derecho
			temp[indiceAUX] = array[indiceIZQ]; //aqui intercambian posicion el lado izq y se asignan al array auxiliar
			indiceAUX++; indiceIZQ++; //cada bucle hara que el indice auxiliar del lado izq aumente para que compare los demas elementos y avance de posicion
            //tambien se incrementa indiceAux para que vaya avanzando de posicion y vaya rellenando el array auxiliar
		}else{
            temp[indiceAUX] = array[indiceDER]; //aqui intercambian posicion el lado derecho y se asignan al array auxiliar
			indiceAUX++; indiceDER++; //cada bucle hara que el indice auxiliar del lado der aumente para que compare los demas elementos y avance de posicion
            //tambien se incrementa indiceAux para que vaya avanzando de posicion y vaya rellenando el array auxiliar
		}
	}
    for(int k=indiceDER; k<=final;k++){  //este bucle ira asignando los elementos restantes del lado derecho al array auxiliar
        temp[indiceAUX]=array[k];
        indiceAUX++; //se incrementa el indice del array auxiliar para ir avanzando posiciones
    }
    for(int k=indiceIZQ; k<=mitad;k++){ //este bucle ira asignando los elementos restantes del lado izquierdo al array auxiliar
        temp[indiceAUX]=array[k];
        indiceAUX++;  //se incrementa el indice del array auxiliar para ir avanzando posiciones
    }
    for(int k=0; k<=indiceAUX-1;k++){
        array[inicio+k]=temp[k];  //finalmente este bucle copiara los elementos del array auxiliar ya ordenados al array final 
    }
	
}
void ordenamientoMezcla(int *array, int inicio, int final) {
	if(inicio < final) { //la condicion quiere decir que cuando el array es de un solo elemento se acaba la recursividad
		int mitad = (inicio + final) / 2; //la mitad del array para partirlo en 2 sucesivamente 
		ordenamientoMezcla(array, inicio, mitad); //divide y ordena el lado izquierdo recursivamente llamandose asimismo
		ordenamientoMezcla(array, mitad+1, final); //divide y ordena el lado derecho recursivamente llamandose asimismo
		mezcla(array, inicio, mitad, final); //mezcla el lado izquierdo y derecho 
        //bucles para imprimir las iteraciones
        cout << "[";
        for(int i=0; i<4; i++){
            cout<< array[i]<<",";
        }
        cout << "]";
        cout<< " lado izquierdo\n";
        cout << "[";
        for(int i=4; i<7; i++){
            cout<< array[i]<<",";
        }
        cout << "]";
        cout<< " lado derecho\n";
	}
}
int main(){
    srand((unsigned) time(0)); //linea necesaria para generar numeros aleatorios 
    int opcion; //variable para el menu
    do{
        cout << "\n------------------------ MENU PRINCIPAL --------------------------------\n";
        cout << "---------- 1) Generar arreglo Aleatorio de 7 posiciones ------------------\n";
        cout << "---------- 2) Ordenar arreglo generado por metodo de la Burbuja --------\n";
        cout << "---------- 3) Ordenar arreglo generado por metodo de la Seleccion ------\n";
        cout << "---------- 4) Ordenar arreglo generado por metodo de Insercion -- ------\n";
        cout << "---------- 5) Ordenar arreglo generado por metodo de Mezcla ------------\n";
        cout << "---------- 6) Presiona 6 para salir ------------\n";
        cout << "Ingresa el numero de opcion que desea realizar: ";
        cin >> opcion;
        switch (opcion){
            case 1: 
              int array[7],array1[7],array2[7],array3[7];  //declaramos los array a usar
              for (int e = 0; e<7; e++){ array[e]= (rand() % 50) + 0; } //genera numeros aleatorios con rango 0 a 50 y los asigna al array
              cout << "\n\n================================================================";
              cout << "\n\nArray generado aleatoriamente: "; imprimir(array); //imprime el array generado aleatoriamente
              cout << "\n================================================================\n";
              for (int f= 0; f<7; f++){ array1[f]=array[f]; } //se copia el array generado aleatoriamente para usarlo en los otros metodos
              for (int f= 0; f<7; f++){ array2[f]=array[f]; } //se copia el array generado aleatoriamente para usarlo en los otros metodos
              for (int f= 0; f<7; f++){ array3[f]=array[f]; } //se copia el array generado aleatoriamente para usarlo en los otros metodos
            break;

            case 2:
              cout << "\n++++++++++++++++++ METODO DE LA BURBUJA ++++++++++++++++++\n\n";
              cout << "Array previamente generado que se va ordenar: "; imprimir(array);
              ordenarBurbuja(array);  //se manda a llamar a la funcion para ordenar por burbuja
              cout << "Array ordenado: \n"; imprimir(array); cout << "\n"; //se imprime el array ordenado
            break;

            case 3:
              cout << "\n++++++++++++++++++ METODO DE SELECCION ++++++++++++++++++\n\n";
              cout << "Array previamente generado que se va ordenar: "; imprimir(array1);
              ordenarSeleccion(array1); //se manda a llamar a la funcion para ordenar por seleccion
              cout << "Array ordenado: \n"; imprimir(array1); cout << "\n";  //se imprime el array ordenado
            break;

            case 4:
              cout << "\n++++++++++++++++++ METODO DE INSERCION ++++++++++++++++++\n\n";
              cout << "Array previamente generado que se va ordenar: "; imprimir(array2);
              ordenarInsercion(array2); //se manda a llamar a la funcion para ordenar por insercion
              cout << "Array ordenado: \n"; imprimir(array2); cout << "\n"; //se imprime el array ordenado
            break;

            case 5:
              cout << "\n++++++++++++++++++ METODO DE MEZCLA ++++++++++++++++++\n\n";
              cout << "Array previamente generado que se va ordenar: "; imprimir(array3);
              ordenamientoMezcla(array3,0,6); //se manda a llamar a la funcion para ordenar por mezcla, los parametros 0 y 6 indican el indice inicial e indice final 
              //en el caso de nuestro arreglo original al tener 7 elementos ira del indice 0 a 6
              cout << "\nArray ordenado: \n"; imprimir(array3); cout << "\n"; //se imprime el array ordenado 
            break;
        }
    }while (opcion!=6); cout<<"\n\nHas salido del programa\n\n"; //do while, cuando se presiona 6 se rompe el bucle y se cierra el menu
    return 0;
}