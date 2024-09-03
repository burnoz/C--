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
void insertionSort(int *A, int n){
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
void merge(int *A, int n, int l, int r, int m){
	int s1, s2, i, j, k;
	
	s1 = m - l + 1;
	s2 = r - m;

	// Creación de arreglos de tamano dinamico
	int *L = (int *) malloc(s1 * sizeof(int));
	int *R = (int *) malloc(s2 * sizeof(int));

	for(i = 0; i < s1; i++){
		L[i] = A[l + i];
	}

	for(j = 0; j < s2; j++){
		R[j] = A[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;

	while(i < s1 && j < s2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}

		else{
			A[k] = R[j];
			j++;
		}

		k++;
	}

	while(i < s1){
		A[k] = L[i];
		i++;
		k++;
	}

	while(j < s2){
		A[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int *A, int n, int l, int r){
	int m;

	if(l < r){
		m = l + (r - l) / 2;

		mergeSort(A, n, l, m);
		mergeSort(A, n, m + 1, r);

		merge(A, n, l, r, m);
	}
}

// Quicksort
// Complejidad O(n^2)
int partition(int *A, int n, int l, int r){
	int pivot, aux, i, j;

	pivot = A[r];
	i = l - 1;

	for(j = l; j < r - 1; j++){
		if(A[j] < pivot){
			i++;
			aux = A[j];
			A[j] = A[i];
			A[i] = aux;
		}
	}

	aux = A[i + 1];
	A[i + 1] = A[r];
	A[r] = aux;

	return i + 1;
}


void quickSort(int *A, int n, int l, int r){
	int pivot;
	
	if(l < r){
		pivot = partition(A, n, l, r);
		quickSort(A, n, l, pivot - 1);
		quickSort(A, n, pivot + 1, r);
	}
}


int main(int argc, char* argv[]){
	int n = 10;						//	Elementos totales
	int asorted1[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted2[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted3[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted4[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted5[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted6[10] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	
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
	insertionSort(asorted4, n);
	printArray(asorted4, n);

	cout << "\n\nMerge-Sort "<< endl;
	mergeSort(asorted5, n, 0, n - 1);
	printArray(asorted5, n);

	cout << "\n\nQuick-Sort "<< endl;
	mergeSort(asorted6, n, 0, n - 1);
	printArray(asorted6, n);
}
