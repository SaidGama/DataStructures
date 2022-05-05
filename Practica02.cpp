/* 
Gama Ponce Said Arturo
Grupo: 2CV6
Carrera: Ingenieria en Sistemas Computacionales    
Ultima modificacion 16/03/22
Practica 2 implementacion de los algoritmos de busqueda
*/
#include <iostream>
#include <cstdlib>  //librerias a usar
using namespace std;
void imprimir(int *array){
    cout << "[";
    for (int i = 0; i<13; i++){
        cout<< array[i]<<",";   //funcion para imprimir un array
    }
    cout << "]\n";
}
void secuencial(int *array,int num){
    bool encontrado=false;
    int i=0;
    for (int i = 0; i<13; i++){ //se hace la comparacion con los 13 numeros del array
        if (array[i]==num){
            cout<<"\nValor encontrado en la posicion "<< i; //aqui imprime si se halla el numero
        }else{
            cout << "\nEl valor no existe en la posicion "<<i; //va imprimiendo los numeros que no coinciden con el numero a buscar
        }
    }
    while(encontrado==false && i<13){
        if(array[i]==num){
            encontrado=true; //este bucle while se rompera cuando se halle el numero y encontrado se volvera verdadero
        }
        i++;
    }
    if(encontrado==false){
        cout<<"\nEl numero no existe en el array!\n"; //si encontrado sigio siendo falso no se encontro el numero
    }else if(encontrado == true){
        cout<<"\nEl numero se encontro y esta en la posicion "<<i-1; //si encontrado fue verdadero si se encontro y estara en la posicion i-1
    }
 
}
void ordenarBurbuja(int* array){
    for (int k = 0; k<13; k++){  
        for (int z = 0; z<13-1; z++){  
            if (array[z]>array[z+1]){ 
                int aux = array[z];    
                array[z]=array[z+1];   //funcion para ordenar por burbuja 
                array[z+1]=aux; 
            }
        }
    }
}
void binaria(int *array, int num){
    cout<<"Array ordenado: "; imprimir(array); cout<<"\n";
    int n=13; //longitud del array
    int inicio=0; //inicio de los sub array
    int final=n-1;   //final de los sub array
    int medio=(inicio+final); //mitad de cada sub array
    while (inicio<=final){ //bucle que se rompera cuando un subarreglo ya no se pueda "partir" mas
        if (array[medio]<num){ 
            inicio=medio+1; //si el numero medio es menor que el numero a buscar, ahora inicio sera en la mitad +1 osea buscara en el lado derecho
            cout << "[";
            for (int i = inicio; i<=final+1; i++){
                cout<< array[i]<<",";   //imprime los sub-array en donde buscara
            }
            cout << "]"; cout << " Sub array en el que se busca\n";
        }else if (array[medio]== num){ //aqui se busca al numero y lo compara con la posicion medio
            cout<<"Se encontro en la posición "<<medio; //el termino medio sera el que indique la posicion final
            break; //se hace un break para que ya no se hagan mas comparaciones
        }else {
            final = medio-1; //si no se encuentra en medio se van bajando la posicion 
        }
        medio = (inicio+final)/2; //se recalcula el numero medio para cada sub array
    }
    if (inicio>final) //si inicio es mayor a final significa que ya no encontro ningun valor en algun sub arreglo
    {
        cout<<num<<"No se encontro";
    }
}
void indexado(int *array,int num){
    const int k=3; //nuestro valor de k
    int m= 13/k; //m es el numero de indices a crear que se calcula con longitud / valor de k
    int indice[m];  //array auxiliar para crear la tabla de indices que sera de tamano m
    int i,aux,a; //variables auxiliares
    bool encontrado=false;
    int posGrupos; //esta variable almacenara la posicion final
    cout<<"Array ordenado: "; imprimir(array);  
    for (int i=0; i<m; i++){
        indice[i]=array[i*k];  //bucle para copiar los primeros elementos de los grupos del array original a la tabla de indices
    }
    cout << "Como k = "<<k<<" y nuestro array es de longitud 13 tendremos "<<m<<" indices";
    cout << "\nTabla de indices: ";
    cout << "[";
    for (int i = 0; i<m; i++){
        cout<< indice[i]<<",";   //imprime la tabla de indices
    }
    cout << "]\n\n";
    i=0; //iniciamos i=0 para que en while empieze desde 0 
    while((num>=indice[i]) && (i<4)){  //este while compara nuestro numero a buscar con los valores de la tabla de indices y asi saber en que grupo buscar
        aux=i;  //guarda la posicion del indice en el que queremos buscar
        i++; //se aumenta i para avanzar posiciones
    }
    posGrupos=(i-1)*k; //aqui calculamos la posicion final ya en el array original 
    cout<<"\nVamos a buscar el numero en el grupo del indice "<<i-1<<" de nuestra tabla de indices";
    if (array[posGrupos]==num){
        cout<<"\nNumero encontrado! esta en la posicion "<<posGrupos<<"\n";  //aqui validamos si el numero a buscar es el primero del grupo elegido
    }
    //este bucle es que el hara las comparaciones en el grupo a buscar
    //conceptualmente es como si hicieramos una busqueda en un array de 3(el grupo) pero no hace falta simplemente ya usamos el array original
    //la variable posGrupos nos pondra los limites a comparar en este caso nuestros grupos son de longitud 3 por lo que solo haremos 3 comparaciones
    cout<<"\n\nComparaciones en el grupo elegido: \n";
    for(a=posGrupos; a<=posGrupos+2; a++){ //se le suma 2 ya que el for solo hara 3 bucles ya que solo comparara 3 numeros ya que los bloques son de 3
        if(array[a]==num){
            cout<<"\nValor encontrado en la posicion "<< a;  //aqui hara comparaciones hasta que encuentre al numero
        }else{
            cout << "\nEl valor no existe en la posicion "<<a; //aqui hara comparaciones para indicar que no existe el numero en la posicion indicada
        }
    }
    a=posGrupos;
    while((encontrado==false)&&(posGrupos<=posGrupos+2)){
        if(array[a]==num){
            encontrado=true;
        }
        a++;
    }
    if(encontrado==false){
        cout<<"\nEl numero no existe en el array!\n";
    }else if(encontrado == true){
        cout<<"\n\nEl numero se encontro y esta en la posicion "<<a-1;
    }
    cout << "\n";
}
int main(){
    srand((unsigned) time(0)); //linea necesaria para generar numeros aleatorios 
    int opcion; //variable para el menu
    do{
        cout << "\n------------------------ MENU PRINCIPAL --------------------------------\n";
        cout << "---------- 1) Generar arreglo de 13 posiciones ------------------\n";
        cout << "---------- 2) Buscar elemento por Busqueda secuencial --------\n";
        cout << "---------- 3) Buscar elemento por Busqueda binaria ------\n";
        cout << "---------- 4) Buscar elemento por Busqueda indexada ------------\n";
        cout << "---------- 5) Presiona 5 para salir ------------\n";
        cout << "Ingresa el numero de opcion que desea realizar: ";
        cin >> opcion;
        switch (opcion){
            case 1: 
              int array[13]; //declaramos los array a usar
              for (int e = 0; e<12; e++){ array[e]= (rand() % 100) + 0; } //genera numeros aleatorios con rango 0 a 100 y los asigna al array
              array[12]=85;
              cout << "\n\n================================================================";
              cout << "\n\nArray generado aleatoriamente y ultima posicion con valor fijo de 85: "; imprimir(array); //imprime el array generado aleatoriamente
              cout << "\n================================================================\n";
            break;

            case 2:
              cout << "\n++++++++++++++++++ BUSQUEDA SECUENCIAL ++++++++++++++++++\n\n";
              cout << "Se va a encontrar el numero 85 en el array generado: \n"; imprimir(array);  cout <<"\n";
              secuencial(array,85); //busqueda secuencial, especificas el array en donde se buscara ya ordenado y el numero a buscar
            break;
            case 3:
              cout << "\n++++++++++++++++++ BUSQUEDA BINARIA ++++++++++++++++++\n\n";
              cout << "Se va a encontrar el numero 85 en el array generado: "; imprimir(array); cout <<"\n";
              ordenarBurbuja(array); //ordena el array
              binaria(array,85); //busqueda binaria, especificas el array en donde se buscara ya ordenado y el numero a buscar
            break;
            case 4:
              cout << "\n++++++++++++++++++ BUSQUEDA INDEXADA ++++++++++++++++++\n\n";
              cout << "Se va a encontrar el numero 85 en el array generado: "; imprimir(array); cout <<"\n";
              ordenarBurbuja(array); //ordena el array
              indexado(array,85); //busqueda indexada, especificas el array en donde se buscara ya ordenado y el numero a buscar
            break;

        
        }
    }while (opcion!=5); cout<<"\n\nHas salido del programa\n\n"; //do while, cuando se presiona 5 se rompe el bucle y se cierra el menu
    return 0;
}
