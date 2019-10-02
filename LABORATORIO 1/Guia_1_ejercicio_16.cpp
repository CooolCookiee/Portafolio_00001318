#include <iostream>

using namespace std;

int main() {
    int sumatoria=0;
    int promedio=0;
    int arreglo[10];
    
    for(int i=0;i<10;i++){
        cout<<"Digite un numero entero: ";
        cin>>arreglo[i];
        
        sumatoria += arreglo[i];   
    }
    
    promedio=sumatoria/10;
    
    cout<<"La sumatoria de los numeros es: "<<sumatoria<<endl;
    cout<<"El promedio de los numeros es: "<<promedio<<endl;
    
    return 0;
}

