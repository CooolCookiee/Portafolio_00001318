#include <iostream>

using namespace std;

void calculos(int num, int *doble, int *triple){
	*doble=2*num;
	*triple=3*num;
	
		
	cout<<"(*doble): "<<(*doble)<<endl;
	cout<<"(*triple): "<<(*triple)<<endl;
	
	cout<<"Direccion del doble de 2: "<<&doble<<endl;
	cout<<"Direccion del triple de 2: "<<&triple<<endl;
	
}

int main(){
	int numero=2, doble = 0, triple=0;
	
	calculos(numero,&doble,&triple);
	
	cout<<"El doble de 2 es : "<<doble<<endl;
	cout<<"El triple de 2 es : "<<triple<<endl;
	
	cout<<"Direccion del doble de 2: "<<&doble<<endl;
	cout<<"Direccion del triple de 2: "<<&triple<<endl;

	return 0;
}
