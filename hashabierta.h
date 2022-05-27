#include <string>
#include <iostream>

#define size 940 //se define el tamano
int cont=0; //contador global para saber cuantos elementos hay en la tabla

//estrucutra llamada nodo que almananeca la data y el puntero que guarda el next
struct node{
    std::string data;
    node *next;
};

//array de punteros para almacenar las direcciones de los nodos que actuara como la tabla
node *tabla[size];

//inicizaliza el array con valores nulos que representara a la tabla
void init2(){
    for(int i = 0; i < size; i++)
        tabla[i] = NULL;
}

//funcion hash que hace la suma de cada caracter del string recibido
int Hash2(std::string data){
    int key=0;
    for (int i = 0; i< data.length(); i++){
        key = (data[i]-32) + key;
    }
    return key;
}

//funcion para insertar
void insert2(std::string data){
    //este if detecta si se introdujeron mas de 10 caracteres
    if(data.length() > 10){  
        std::cout<<"\nOVERFLOW pusiste mas de 10 caracteres\n";
    }else{
        //crea nuevo nodo
        node *newNode = new node();
        cont++; //cada que se inserta conteo aumenta
        //asigna el valor y el next apunta a null
        newNode->data = data;  //asiganmos el valor
        newNode->next = NULL; //el next se asinga a nulo
        //funcion hash para darnos la key
        int key = Hash2(data);

        //checa si el lugar donde debe ir el nuevo nodo esta vacio, si no entonces ocurre colision
        if(tabla[key] == NULL)
            tabla[key] = newNode; //asigna el nodo a la posicion dada por la key
        //colision
        else
        {
            //cuando ocurre colision agregamos el nodo al final de la lista enlazada recorriendo el next con un while
            node *temp = tabla[key];
            while(temp->next!=NULL){
                temp = temp->next; 
            }
            temp->next = newNode; //se enlaza el nodo al next del anterior
        }
    }
}

//funcion de busqueda
int search2(std::string data){
    int key = Hash2(data); //nos da la key a buscar
    node *temp = tabla[key]; //guardamos la direccion del indice en un puntero nodo que sera el primer nodo de la lista 
    while(temp!=NULL) //bucle hasta que llegue al final de la lista simple
    {
        if(temp->data == data) //se detiene cuando se halla el dato
            return key; //regresa el inidice si existe
        temp = temp->next; //hace que avance el recorrido
    }
    return 0; //retorna 0 si en el while nunca entra al if que significa que no existe el dato
}


int del2(std::string data){
    int key = Hash2(data); //funcion hash para darnos la key
    node *Nodo = new node(); //creamos nodo
    node *temp = new node(); //creamos uno temporal
    Nodo = tabla[key]; //asignamos la direccion del indice en nuestro nodo creador
    temp = NULL; //apuntamos temp a null temporalmente
    if(Nodo != NULL || cont!=0) //si la lista esta vacia o el nodo esta vacio entonces no se ejecutara
    {
        if(Nodo->data == data)
        {
            temp = Nodo; //guardamos la direccion del nodo para no perderla
            Nodo = Nodo->next; //nodo ahora guardara la direccion del next osea del siguiente nodo como en una lista simple
            tabla[key] = Nodo; //esta linea hace que la direccion de next se guarde en el indice osea en el principio
            //ya que sin esta linea, el indice key tendra una direccion ya liberada y dara segment fault
            
            delete(temp); //libera el puntero
            cont--; //decrementamos el contador
            return 1; //retorna 1 si se elimino correctamente
        }
        else{
            while(Nodo->next!=NULL) //recorre hasta el final de la lista
            {
                if(Nodo->next->data == data) //se para cuando el valor a eliminar es el que esta en el nodo
                {
                    temp = Nodo->next; //guardamos la direccion del nodo para no perderla
                    Nodo->next = Nodo->next->next; //nodo->next ahora guardara la direccion del next osea del siguiente nodo como en una lista simple
                    //guarda el next del siguiente nodo borrado, es decir si tuvieramos tres y se borra el de enmedio el next del primero ahora apunta al tercero
                    delete(temp); //liberamos el puntero
                    cont--; //decrementamos
                    return 1; //retorna 1 si es exitoso
                }
                Nodo = Nodo->next; //hace que avance el recorrido
            }
        }
    }
    std::cout<<"\n\nUnderflow tabla esta vacia\n"; //si contador==0 entonces la tabla esta vacia y no dejara eliminar
    return 0;
}

//despliega la tabla
void print2(){
    std::cout<<"*******************************************************";
    std::cout<<"\nTABLA HASH (solo se muestran los indices con datos)\n\n\n";
    for(int i = 0; i < size; i++) 
    {
        node *temp = tabla[i]; //se crea un nodo por cada indice que trae consigo la direccion de las listas
        if(tabla[i]!=NULL){ //este if hace que ssolo se impriman los indices con datos
            std::cout<<"Indice["<<i<<"]--> ";
            while(temp!=NULL){  //recorre la lista hasta el final
                //std::cout<<"  dir 1: "<<temp;
                std::cout<<temp->data<<" --> ";
                temp = temp->next; //hace que avance el recorrido
            }
            std::cout<<"NULL\n"; //cuando llega al final de lista imprime null
        }
    }
    std::cout<<"\n*******************************************************\n";
}

void hashabierta(){
    
    init2(); //iniciliza la tabla
    int flag=1,menu;
    std::string data;
    while (flag!=0)
    {
        std::cout<<"\n1. Insertar  2. Borrar   3. Buscar   4. Mostrar Tabla   5. Salir: ";
        std::cin>>menu;
        switch (menu){
        case 1:
            std::cout<<"\nIngresa el texto a insertar: ";
            std::cin>>data;
            insert2(data);
        break;
        case 2:
            std::cout<<"\nIngresa el texto a remover: ";
            std::cin>>data;
            if(del2(data)){
                std::cout<<"\nRemovido con exito";
            }else{
                std::cout<<"\nRemovido sin exito, elemento no existe";
            }
        break;
        case 3:
            std::cout<<"\nIngresa el texto a buscar: ";
            std::cin>>data;
            int sea;
            sea=search2(data);
            if(sea!=0){
                std::cout<<"\nDato encontrado en indice: "<<sea;                
            }else{
                std::cout<<"\nelemento no existe";
            }
        break;
        case 4: 
            print2();
        break;
        case 5: 
            flag=0;
        break;
        }
    }

}