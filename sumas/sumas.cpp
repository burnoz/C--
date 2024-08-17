#include <iostream>
using namespace std;


int sumaIterativa(int n){
    int suma = 0; // Variable acumuladora

    for(int i = 1; i <= n; i++){
        suma = suma + i; // Suma cada número en la variable acumuladora
    }

    return suma; // Devuelve el resultado
}


int sumaRecursiva(int n){
    if(n == 1){ // Caso default
        return 1;
    }

    else{
        return n + sumaRecursiva(n - 1); // Llama a la función hasta llegar al caso default
    }
}


int sumaDirecta(int n){
    return (n * (n + 1)) / 2; // Fórmula de Gauss
}


int main(){
    // Pide un valor de n al usuario
    int lim;
    cout << "Introduzca el valor limite: ";
    cin >> lim;

    // Se muestran los resultados
    cout << "Resultado iterativo: " << sumaIterativa(lim) << endl;
    cout << "Resultado recursivo: " << sumaRecursiva(lim) << endl;
    cout << "Resultado con formula: " << sumaDirecta(lim) << endl;

    return 0;
}