#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void push(Nodo *&,int); 

void pop(Nodo *&,int &);

int main(){
	Nodo *pila = NULL;
	int dato;
	char respuesta;
	
	do{ 
		cout<<"Digite un numero: ";
		cin>>dato;
		push(pila,dato);
	
		cout<<"\nDesea agregar otro numero a pila(s/n): ";
		cin>>respuesta;
		cout<<endl;
	}while((respuesta == 's')||(respuesta=='S'));
	
	
	cout<<"\nMostrando los elementos de la pila: ";
	while(pila != NULL){
		pop(pila,dato);
		
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

void push(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tNumero "<<n<<" agregado a PILA ";
}

void pop(Nodo *&pila,int &z){
	Nodo *aux = pila;
	z = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
