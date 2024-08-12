#include <iostream>
using namespace std;

// Potencias de 2
int pow2(int n){

    if(n == 0){
        return 1;
    }

    else{
        return 2 * pow2(n - 1);
    }
}

int main(){
    
    cout << pow2(4) << endl;

    // powA(a, n)
    return 0;
}