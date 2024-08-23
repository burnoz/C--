#include <iostream>
using namespace std;

// Complejidad O(n)
int factorial_rec_lineal(int n, int a){
    if(n == 0){
        return a;
    }

    else{
        return factorial_rec_lineal(n - 1, a * n);
    }
}


int main(){
    int num;
    cin >> num;
    
    cout << "El factorial de " << num << " es: " << factorial_rec_lineal(num, 1);

    return 0;
}
