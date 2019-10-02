#include <iostream>
using namespace std;

long mcd(long n, long m){
    if(n==m){
        return n;
    }else if(n<m){
        return mcd(n,m-n);
    }else{
        return mcd(n-m,m);
    }

}

int main() {
    long a,b;
    
    cout<<"Digite el primer numero: "; cin>>a;
    cout<<"Digite el segundo numero: "; cin>>b;
    
    mcd(a,b);
    
    cout<<"MCD: "<<mcd(a,b);
    
    
    return 0;
}

