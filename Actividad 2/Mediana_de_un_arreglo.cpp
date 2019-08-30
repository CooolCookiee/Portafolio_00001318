#include<iostream>

using namespace std;

int main (){

	int elementos=5;
	int numeros[elementos];
	float mediana=0;
	
	cout<<"Digite cincos valores"<<endl;
	
	for(int i=0;i<elementos;i++){
		cout<<"Digite un numero: ";
		cin>>numeros[i];
		mediana+=numeros[i];
	}
	cout<<"La mediana es: "<<numeros[2];
	
return 0;
	
}
