#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&lista, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato=n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	

	if(lista==aux1){
		lista=nuevo_nodo;
	} else {
		aux2->siguiente=nuevo_nodo;
	}
	
	nuevo_nodo->siguiente=aux1;	
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<" " << actual ->dato<<"-> ";
		actual = actual->siguiente;
	}
}

bool buscarLista(Nodo *lista, int n,int cdn){
	float prob;
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual != NULL) && (actual->dato<=n)){
		if(actual->dato==n){
			band = true;
		}
		actual = actual->siguiente;
	}

	if(band == true){	
		return true;
	} else {
		return false;
	}
	
}

int found(Nodo *lista, int n,int cdn,int jugadas,int veces,int ayuda){
	float prob;
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual != NULL) && (actual->dato<=n)){
		if(actual->dato==n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	ayuda++;
	
	if(ayuda<=jugadas){
		if(band == true){
			//cout<<"ENTRO";
			veces++;
			found(lista,n,cdn,jugadas,veces,ayuda);
		} else {	
			return 0;
		}	
		
	} else {
		return veces;
	}
}

int main() {
    cout << "\n RULETA \n" << endl;
    cout << " Dependiendo de que numeros escoja se le multiplicara el dinero por esa cantidad de numeros. ";
    
    Nodo *lista = NULL;
    
    int puntos, apuesta = 0, cantidad_de_numero, numero, numero2,veces=0,ayuda=1;
    float cdn, probabilidad, prob, times;
    bool retorno = false;
    char respuesta;
    srand(time(NULL));

    cout << "\n 	Ingrese su saldo inicial: ";
    cin>>puntos;

    if (puntos <= 0) {
        cout << " 	Digite un numero positivo: ";
        cin>>puntos;
    }

    bool estado = true;

    cout << " 	Ingrese cantidad de numeros : ";
    cin >> cantidad_de_numero;

    if (cantidad_de_numero <= 0) {
        cout << " 	Digite un numero positivo: ";
        cin>>cantidad_de_numero;
    }

    cout << "\n";
    while (estado) {
        for (int jugadas = 1; jugadas <= 10; jugadas++) {
            fflush(stdin);
            cout << "Saldo actual: " << puntos << endl;
            cout << "Ingrese su apuesta:  ";
            cin >> apuesta;

            if (apuesta == 0 || apuesta > puntos) {
                cout << "Digite un numero inferior o igual a su saldo actual y que sea diferente a 0: ";
                cin>>apuesta;
            }

            if (jugadas == 10) {
                cout << "GRACIAS POR JUGAR...";
                jugadas = 10;
                estado = false;
            }

            if (estado == true) {

                puntos = puntos - apuesta;

                cdn = cantidad_de_numero;
                numero = rand() % cantidad_de_numero;
                
                cout << "Ingrese el numero por el cual va a apostar entre 0 y " << cantidad_de_numero - 1 << ": ";
                cin>>numero2;
                
				retorno=buscarLista(lista,numero,cdn);
				mostrarLista(lista);
				times=found(lista,numero,cdn,jugadas,veces,ayuda);
				
				if(retorno == true){
					
					cout<<"entro2";
					prob=(((1/cdn)*((cdn-1)/cdn))/(times/jugadas));	
					
				} else {
					prob = (1/cdn);
				}
	
				
                cout << "Esta es la probabilidad de ganar: " << prob *100 << "%" << endl;

                cout << "Sabiendo la probabilidad, Desea continuar apostando? ";
                cin>>respuesta;

                if ((respuesta == 's') || (respuesta == 'S')) {

                    cout << "Salio : " << numero << endl;
                    
                    {
                        if (numero == numero2) {
                            puntos = puntos + (apuesta * cantidad_de_numero);

                            cout << "Ha ganado" << endl;
                        } else {
                            cout << "Ha perdido" << endl;
                        }
                    }
                } else {
                    cout << "\n";
                    cout << "GRACIAS POR JUGAR...";
                    cout << "\n";
                    jugadas = 10;
                    estado = false;
                }
            }
            if (puntos == 0) {
                jugadas = 10;
                estado = false;
            }
            agregarPila(lista,numero);
        }
    }


    system("pause");
    return 0;
}
