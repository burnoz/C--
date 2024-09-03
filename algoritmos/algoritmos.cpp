#include <iostream>
#include <cstdlib>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;


//	Imprime el arreglo
void printArray (int *A, int n){
	int i;
	cout<<"\nArreglo:\t";
	
	for (i = 0; i < n; i++){
		cout<<' '<<A[i];	
	}

	cout << endl;

	return;
}


int main(int argc, char* argv[]){
    int aux;
    int i = 0;
    int *A = (int *) malloc(100 * sizeof(int));
    
    char *file_route;
    FILE *input_file;

    file_route = argv[1];
    input_file = fopen(file_route, "r");

    while(fscanf(input_file, "%d", &aux) != EOF){
        A[i] = aux;
        cout << aux << " ";
        i++;
    }

    printArray(A, i);

    return 0;
}