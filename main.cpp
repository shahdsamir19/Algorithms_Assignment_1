#include <iostream>
using namespace std;

int f[2][2] = {{1, 1}, {1, 0}};
int M[2][2] = {{1, 1}, {1, 0}};

void multiplacation (int f[2][2],int  M[2][2]){
    int a = f[0][0]*M[0][0]+ f[0][1]*M[1][0];
    int b= f[0][0]*M[0][1] + f[0][1]*M[1][1];
    int c= f[1][0]*M[0][0]+ f[1][1]*M[1][0];
    int d= f[1][0]*M[0][1]+ f[1][1]*M[1][1];

    f[0][0]= a;
    f[0][1]= b;
    f[1][0]=c;
    f[1][1]=d;
}


void power(int f[2][2], int n ){
    if (n==0 || n==1){ return ;}
    power(f, n/2);
     multiplacation(f, f);
        if (n%2!=0){
             multiplacation( f, M);
        }



}
int fibo (int n){
    if (n==0)
        return 0;
    else{
        power(f, n-1);
        return f[0][0];
    }
}


int main() {
    int n;
    cout << "Enter the position, please  ";
    cin >> n;

    cout << "fibonacci number at position " << n << " = " << fibo (n) <<endl;
    return 0;
}
