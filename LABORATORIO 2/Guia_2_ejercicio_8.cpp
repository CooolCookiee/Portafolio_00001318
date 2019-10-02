#include <iostream>
using namespace std;

long recursiva(long a,long b){
    if (a>0){
    return recursiva(a/10, b+1);     
    } 

    return b;
}

int main(){
    long a,b=0;
    
    cout<<"Digite un numero entero: ";
    cin>>a;
    
    cout<<"\nNumero de cifras: "<<recursiva(a,b);
    
    return 0;
}
