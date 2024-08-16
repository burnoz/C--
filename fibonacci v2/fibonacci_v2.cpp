#include <iostream>
using namespace std;

// Complejidad O(n)
int fibo_iter(int n){
    int a = 0; // Fibonacci de 0
    int b = 1; // Fibonacci de 1
    int c;

    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}


// fibo_rec_lineal(n, 0, 1), Complejidad O(n)
// Tail recursion / recursividad terminal
int fibo_rec_lineal(int n, int a, int b){
    if(n == 0){
        return a;
    }

    else if(n == 1){
        return b;
    }

    else{
        return fibo_rec_lineal(n - 1, b, a + b);
    }
}


int main(){
    cout << "Metodo iterativo: " << fibo_iter(6) << endl;
    cout << "Metodo recursivo eficiente: " << fibo_rec_lineal(6, 0, 1);

    return 0;
}