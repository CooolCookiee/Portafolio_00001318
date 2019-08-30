#include <iostream>
using namespace std;

int multiplicacion(int a, int b){
	
	if(a==0 || b==0)
	return 0;
	else
   {
    return a+multiplicacion(a,b-1);
   }
}

int main(){
	int x,y,m;
	
	cout << "Introduzca primer numero: ";
	cin >> x;
	cout << "Introduzca segundo numero: ";
	cin >> y;
	
	m=multiplicacion(x,y);
	
	cout << "El resultado es: " << m << endl;
 system("pause");

}
