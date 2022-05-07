#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

bool esPrimo(int num){
    for (int i=2; i<num; i++) {
        if (num%i==0){
            return false;
        }  
    }
    return true; 
}
int espejo(int num) {
    int espejo=0;
	string Numchar = to_string(num); 
	string aux;
    aux[0] = Numchar[0];
	Numchar[0] = Numchar[1];
	Numchar[1] = aux[0];
    stringstream espejochar(Numchar);
    espejochar >> espejo; 
    return espejo; 
}
int suma(){
     int num=11;
     int suma=0;
      while(num>10 && num<98){
           if( esPrimo(num) && esPrimo(espejo(num))){
               suma = suma+num;
           }
           num++;
      }
      return suma;
}
int main()
{
    cout<<suma()<<endl;
	return 0;
}