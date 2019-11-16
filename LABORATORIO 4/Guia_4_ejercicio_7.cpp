#include <iostream>
#include <string>

using namespace std;

struct TNum{
    int valor;
   
};
typedef struct TNum Num;

Num solicitarNumero(){
    Num p;
    
    cout << "Ingresar un numero: "; cin >> p.valor;
    cin.ignore();
    bool continuar = true;
   
    return p;
}

void mostrarNumero(Num p){
    cout << "Numero: " << p.valor << endl;
}

struct TNodo{
    Num dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Num p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Num p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void agregarNumero(){
    Num p = solicitarNumero();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Desea agregar al principio\n\t2) Desea agregar al final"
            << "\n\tOpcion: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
            default: cout << "ERROR...Opcion invalida" << endl;
            break;
        }
    }while(continuar);
}

void mostrarNumero() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarNumero(s->dato);
        s = s->sig;
    }
}


int Contador(int num){
	Nodo *s;
	int cont=0;
	
	 for(s=pInicio; s!=NULL; s=s->sig){
	 	
	   if((s->dato).valor == num)
	   
	     cont++;
     }
	return cont;   
}


void eliminarN(int num, int cantidad){

	
 int n=0;
 
 while(n!=cantidad){
	Nodo *borrar = pInicio, *p = NULL;    
    while(borrar != NULL && (borrar->dato).valor != num){
        p = borrar;
        borrar = borrar->sig;
    }
    if(borrar == NULL){
        cout << "Numero no exite\n" << endl;
        system("pause");
        return;
    }
    if(p == NULL)
        pInicio = pInicio->sig;
    else
        p->sig = borrar->sig;
    delete(borrar);
    n++;
 }
 cout<<"Ocurrencias eliminadas\n";
 system("pause");
}

void eliminarOcurrencias(){
	float ocu=0;
	
	int contador=0;
	
	cout << "Ingrese el numero deseado\n";
	
	cin >> ocu;
	
	contador = Contador(ocu);
	cout<<" "<< ocu <<" "<<contador;
	system("pause");
	
	eliminarN(ocu,contador);
}

int main(){

    int unVALOR=0;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar numero\n\t2) Ver datos"
            << "\n\t3) Eliminar ocurrencias"
            << "\n\t4) Salir\n\tOpcion: ";
        cin >> opcion;
        cout<<endl;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarNumero();
            break;
            case 2: cout << "Mostrando..." << endl;
                mostrarNumero();
            break;
            case 3: cout << "Eliminando..." << endl;
                eliminarOcurrencias();
            break;
		    case 4: continuar = false;
            break;
            default: cout << "ERROR...Opcion Invalida" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
