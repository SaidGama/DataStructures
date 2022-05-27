#include <string>
#include <iostream>

#define size 940 //se define el tamano
int conteo = 0;//contador global para saber cuantos elementos hay en la tabla

//array de strings
std::string arr[size];

//iniciliza el array con cadena vacias
void init1(){   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = "";
}
//funcion hash
int Hash1(std::string data){
    int key=0;
    for (int i = 0; i< data.length(); i++){
        key = (data[i]-32) + key;
    }
    return key;
}

//funcion insertar
void insert1(std::string data){
    if(data.length()>10 || conteo > 939){   //overflow
        std::cout<<"OVERFLOW ingresaste mas de 10 caracteres o la tabla se lleno";
    }else{
        int key = Hash1(data); //se llama la funcion hash para obtener la key(indice)
        if(arr[key] == ""){   //si el indice tiene informacion vacia(cadena vacia) entonces lo inserta
            arr[key] = data; //se asigna el dato a la posicion dada por el indice
            conteo++; //se aumenta el contador
            std::cout<<"\ninsertado en indice: "<<key;        
        }
        else{  //aqui es donde ocurre la colision, si el indice ya contiene datos entonces se inserta en la siguiente posicion
                arr[key+1] = data; 
                conteo++;
                std::cout<<"\nColision, se ha insertado en "<<key+1;
        }
    }
    
}

int del1(std::string data){
        if(conteo==0){ //underflow
            printf("\nTabla vacia\n");
        }
        int key = Hash1(data); //funcion hash
        while (arr[key]!="")  //hace la busqueda del dato a borrar
        {
            if(arr[key] == data){ //cuando se halla el dato
                arr[key] = ""; //se borra con una cadena vacia
                conteo--; //se decrementa conteo
                return 1; //nos retorna 1 si es exitoso
            }
            key=(key+1); //si no el dato a eliminar fue una colision entonces estara en la sig posicion
        }
        std::cout<<"\nNo existe\n";   //si el while nunca ejecuta el if entonces no existe el dato
        return 0; //retorna 0 si no fue exitoso o no existe el dato
}

int search1(std::string data){
    if(conteo==0){  //underflow
        printf("Tabla vacia\n");
    }
    int key=Hash1(data);  //funcion hash para obtener la key(indice)
    while(arr[key]!="") //hace la busqueda
    {
        if(arr[key]==data){
            return key;  //una ves que lo encuentra nos retorna el indice en donde esta
        }
        key=(key+1);  //de igual forma si el dato fue una colision estara en la sig posicion
    }
    std::cout<<"\ndato no encontrado";
    return 0;
}

void print1(){
    for(int i = 0; i < size; i++){   //imprime solo los indices con datos
        if(arr[i]!=""){
            std::cout<<"\nIndice["<<i<<"] = "<<arr[i];
        }
    }
}

void hashcerrada(){
    
    init1(); //iniciliza la tabla
    int flag=1,menu;
    std::string data;
    while (flag!=0)
    {
        std::cout<<"\n1. Insertar  2. Borrar   3. Buscar   4. Mostrar Tabla   5. Salir: ";
        std::cin>>menu;
        switch (menu)
        {
        case 1:
            std::cout<<"\nIngresa el texto a insertar: ";
            std::cin>>data;
            insert1(data);
        break;
        case 2:
            std::cout<<"\nIngresa el texto a remover: ";
            std::cin>>data;
            int de;
            de=del1(data);
            if(de!=0){
                std::cout<<"\nDato removido exitosamente";
            }
                
        break;
        case 3:
            std::cout<<"\nIngresa el texto a buscar: ";
            std::cin>>data;
            int sea;
            sea=search1(data);
            if(sea!=0){
                std::cout<<"\nDato encontrado en indice: "<<sea;                
            }
        break;
        case 4:
            print1();
        break;
        case 5: 
            flag=0;
        break;
        }
    }
}