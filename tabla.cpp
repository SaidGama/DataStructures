#include <iostream>
using namespace std;

int tablita(int i){
    if(i>3){
        return 0;
    }
    cout<<i;
    for(int i=0; i<2; i++){
        tablita(i);
    }
    
}

int main(int argc, char const *argv[]){
    tablita(0);
    return 0;
}
