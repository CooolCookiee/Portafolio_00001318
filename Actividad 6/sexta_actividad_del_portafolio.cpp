//Busqueda Binaria

#include<iostream>
#include<conio.h>

using namespace std;

int numeros[] = {1,3,4,5,17,18,31,33};

int busqueda (int x,int inf, int sup){

	if(inf>sup){
        return(-1);
	}
	
    int mitad=(inf+sup)/2;
    
	if (x==numeros[mitad]){
		return(mitad);
	}
	if (x<numeros[mitad]){
		return busqueda(x,inf,mitad-1);
	} else {
		return busqueda(x,mitad+1,sup);
	}
}

int main(){
	int a=0;
	int inf=0;
	int sup=7;
	int x=0;
	
	cout<<"Digite el numero a buscar: ";
	cin>>a;
	
	x= busqueda(a,inf,sup);
	
	if(x == -1){
		cout<<"El numero no se encontro"<<endl;
	}
	else{
		cout<<"El numero se encontro en la posiscion: "<<x<<endl;
	}
	
	getch();
	return 0;
}
