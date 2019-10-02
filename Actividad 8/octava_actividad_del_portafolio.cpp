#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int); 
void sacarPila(Nodo *&,int &);

int main(){
	Nodo *pila = NULL;
	int dato;
	char respuesta;
	
	do{ 
		cout<<"Digite un numero: ";
		cin>>dato;
		agregarPila(pila,dato);
	
		cout<<"\nDesea agregar otro numero a pila(s/n): ";
		cin>>respuesta;
		cout<<endl;
	}while((respuesta == 's')||(respuesta=='S'));
	
	
	cout<<"\nMostrando los elementos de la pila: ";
	while(pila != NULL){
		sacarPila(pila,dato);
		
		if(pila != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
		
	getch();
	return 0;
}

void agregarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tNumero "<<n<<" agregado a PILA ";
}

void sacarPila(Nodo *&pila,int &z){
	Nodo *aux = pila;
	z = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
