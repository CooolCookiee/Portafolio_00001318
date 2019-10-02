#include<iostream>

using namespace std;

struct inf{ 
	char capital[100];
	int habit;
};

struct pais{
	char pais[100];
	struct inf inf_capital;
}pais[5];

struct continente{
	char cont[100];
	struct pais p_pais;
	
}continente[5];

int main(){
	
	for(int i=0;i<5;i++){
		fflush(stdin);
		cout<<"Digite el nombre del continente: ";
		cin.getline(continente[i].cont,100,'\n');
		for(int i=0;i<5;i++){
			fflush(stdin);
			cout<<"Digite el nombre del pais: ";
			cin.getline(continente[i].p_pais.pais,100,'\n');
			cout<<"Digite el nombre de la capital: ";
			cin.getline(continente[i].p_pais.inf_capital.capital,100,'\n');
			cout<<"Digite el numero de habitantes: ";
			cin>>(continente[i].p_pais.inf_capital.habit);
			cout<<"\n";
		}
		
	}

	return 0;
}
