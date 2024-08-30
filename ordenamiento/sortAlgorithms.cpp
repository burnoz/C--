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

//	Ordenamiento burbuja
// Complejidad O(n^2)
void bubbleSort(int *A, int n){
	int i, j, aux;

	for(i = 0; i < n; i ++){
		for(j = 0; j < n - i - 1; j++){
			if(A[j] > A[j + 1]){
				aux = A[j];
				A[j] = A[j + 1];
				A[j + 1] = aux;
			}
		}
	}

	return;
}

//	Ordenamiento por intercambio
// Complejidad O(n^2)
void swapSort (int *A, int n){
	int i, j, aux;

	for(i = 0; i < n; i ++){
		for(j = i + 1; j < n; j++){
			if(A[i] > A[j]){
				aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}

	return;
}

//	Ordenamiento por seleccion
// Complejidad O(n^2)
void selectionSort(int *A, int n){
	int i, j, indexMin, aux;

	for(i = 0; i < n; i++){
		indexMin = i;

		for(j = i + 1; j < n; j++){
			if(A[j] < A[indexMin]){
				indexMin = j;
			}
		}

		aux = A[indexMin];
		A[indexMin] = A[i];
		A[i] = aux;
	}
}

// Ordenamiento por insercion
// Complejidad O(n^2)
void insertionsort(int *A, int n){
	int i, c, j;

	for(i = 0; i < n; i ++){
		c = A[i];
		j = i - 1;

		while(j >= 0 && A[j] > c){
			A[j + 1] = A[j];
			j--;
		}

		A[j + 1] = c;
	}
}

// Ordenamiento por fusion (merge)
// Complejidad O(nlog(n))
void mergeSort(int *A, int n){

}

//	Print the array
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
	int n = 10;						//	Elementos totales
	int asorted1[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted2[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted3[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted4[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted5[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	
	printArray(asorted1, n);
	
	cout << "\n\nSeleccion-Sort "<< endl;
	selectionSort(asorted1, n);
	printArray(asorted1, n);
	
	cout << "\n\nBubble-Sort "<< endl;
	bubbleSort(asorted2, n);
	printArray(asorted2, n);

	cout << "\n\nSwap-Sort "<< endl;
	swapSort(asorted3, n);
	printArray(asorted3, n);

	cout << "\n\nInsertion-Sort "<< endl;
	swapSort(asorted4, n);
	printArray(asorted4, n);
}
