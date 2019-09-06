#include <iostream>

using namespace std;

int recursive2 (int x , int y){
    
    if (y==x){
        //cout<<x<<endl;
    } else {
        cout<<y<<endl;
        recursive2(x,y+1);
    }
    
}

int recursive(int x){
    
    if(x==1){
        cout<<x<<endl;
    } else {
        cout<<x<<endl;
        recursive(x-1);
    }
}

int main() {
    int x;
    int y=1;
    
    cout<<"Digite un numero entero: ";
    cin>>x;
    
    recursive2(x,y);
    recursive(x);
    
    return 0;
}

