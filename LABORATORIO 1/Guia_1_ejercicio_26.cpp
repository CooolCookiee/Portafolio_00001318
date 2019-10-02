#include<iostream>
#include<conio.h>
using namespace std;

struct Complejo{
	float real;
	float imaginaria;
	}a;

void PedirDatos(){
	cout<<"Digite un numero complejo: "<<endl;
	cout<<"Parte Real: "; cin>>a.real;
	cout<<"Parte Imaginaria: "; cin>>a.imaginaria;
}

Complejo conjugada(Complejo a){
	a.real=a.real;
	a.imaginaria=-a.imaginaria;

	return a;
}

void Mostrar(Complejo b){
	cout<<"\nLa conjugada es: "<<b.real<<" , "<<b.imaginaria<<endl;
}

int main(){
	cout<<"Este es el ejercicio 26"<<endl;
	PedirDatos();
	Complejo b=conjugada(a);
	Mostrar(b);

	getch();
	return 0;
}
