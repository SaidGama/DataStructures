/* 
Gama Ponce Said Arturo
Grupo: 2CV6
Carrera: Ingenieria en Sistemas Computacionales    
Ultima modificacion 27/05/22
Examen 2do parcial Implementacion de tabla hash usando linear probing y separate  chaining
*/
#include <iostream>
#include "hashcerrada.h"
#include "hashabierta.h"

int main(int argc, char const *argv[])
{
    int menu; 
    bool flag=true;
    while(flag){
        std::cout<<"\n1. Tabla Hash Cerrada(linear probing)  2. Hash Abierta(separate chaining)  3. salir  :";
        std::cin>>menu;
        switch (menu){
        case 1:
            hashcerrada();
        break;
        case 2:
            hashabierta();
        break;
        case 3:
            flag=false;
        break;
        }
    }
    return 0;
}
