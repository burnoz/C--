#include <iostream>

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
// Complejidad promedio: O(n^2)
void bubbleSort(int *A, int n){
	int i, j, aux;

	for(i = 0; i < n; i ++){
		for(j = 0; j < n - i - 1; j++){
			// Verifica si el primer elemento en el par es mayor al segundo
			if(A[j] > A[j + 1]){
				// Intercambia los elementos
				aux = A[j];
				A[j] = A[j + 1];
				A[j + 1] = aux;
			}
		}
	}
	
	// Nota: se ordenan primero los elementos mayores
}

//	Ordenamiento por intercambio
// Complejidad promedio: O(n^2)
void swapSort (int *A, int n){
	int i, j, aux;

	for(i = 0; i < n; i ++){
		for(j = i + 1; j < n; j++){
			// Verifica si el elemento en i es mayor a los que le proceden
			if(A[i] > A[j]){
				// Intercambia los elementos
				aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}
	// Nota: se ordenan primero los elementos menores
}

//	Ordenamiento por seleccion
// Complejidad: O(n^2)
void selectionSort(int *A, int n){
	int i, j, indexMin, aux;

	for(i = 0; i < n; i++){
		// Toma el primer elemento como el menor
		indexMin = i;

		// Itera en el resto del arreglo para buscar un nuevo valor menor
		for(j = i + 1; j < n; j++){
			// Compara el valor minimo con el actual
			if(A[j] < A[indexMin]){
				// Actualiza el valor minimo
				indexMin = j;
			}
		}

		// Intercambia los elementos
		aux = A[indexMin];
		A[indexMin] = A[i];
		A[i] = aux;
	}
}

// Ordenamiento por insercion
// Complejidad promedio: O(n^2)
void insertionSort(int *A, int n){
	int i, c, j;

	for(i = 0; i < n; i++){
		c = A[i];
		j = i - 1;

		// Si el elemento actual es menor a valores anteriores, los desplaza
		while(j >= 0 && A[j] > c){
			A[j + 1] = A[j];
			j--;
		}

		// Inserta el elemento en su lugar
		A[j + 1] = c;
	}
}

// Ordenamiento por fusion (merge)
// Complejidad promedio: O(nlog(n))
void merge(int *A, int n, int l, int r, int m){
	int s1, s2, i, j, k;
	
	// Tamanos de los subarreglos
	s1 = m - l + 1;
	s2 = r - m;

	// Creación de arreglos de tamano dinamico
	int *L = (int *) malloc(s1 * sizeof(int));
	int *R = (int *) malloc(s2 * sizeof(int));

	// Copia los elementos al subarreglo de la izquierda
	for(i = 0; i < s1; i++){
		L[i] = A[l + i];
	}

	// Copia los elementos al subarreglo de la derecha
	for(j = 0; j < s2; j++){
		R[j] = A[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	
	// Combina los subarreglos
	while(i < s1 && j < s2){
		// Compara los elementos de los subarreglos e inserta el menor
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

	// Inserta los elementos restantes
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
		// Encuentra el punto medio
		m = l + (r - l) / 2;

		mergeSort(A, n, l, m);
		mergeSort(A, n, m + 1, r);
		merge(A, n, l, r, m);
	}
}

// Quicksort
// Complejidad promedio: O(nlog(n))
int partition(int *A, int n, int l, int r){
	int pivot, aux, i, j;

	// Asigna el ultimo elemento como pivote
	pivot = A[r];
	i = l - 1;
	
	for(j = l; j < r - 1; j++){
		// Si el elemento actual es menor al pivote, lo mueve a la izquierda
		if(A[j] < pivot){
			i++;
			aux = A[j];
			A[j] = A[i];
			A[i] = aux;
		}
	}

	// Intercambia el pivote con el elemento en la posicion correcta
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

// ./algoritmos.exe file.txt
int main(int argc, char* argv[]){
    int aux;
    int i = 0;

	// Arreglos de tamano dinamico
    int *asorted1 = (int *) malloc(100 * sizeof(int));
	int *asorted2 = (int *) malloc(100 * sizeof(int));
	int *asorted3 = (int *) malloc(100 * sizeof(int));
	int *asorted4 = (int *) malloc(100 * sizeof(int));
	int *asorted5 = (int *) malloc(100 * sizeof(int));
	int *asorted6 = (int *) malloc(100 * sizeof(int));
    
    char *file_route;
    FILE *input_file;

	// Lee la ruta del archivo desde la terminal
    file_route = argv[1];

	// Abre el archivo
    input_file = fopen(file_route, "r");

	// Lee el contenido del archivo y asigna los valores al arreglo
    while(fscanf(input_file, "%d", &aux) != EOF){
        asorted1[i] = aux;
		asorted2[i] = aux;
		asorted3[i] = aux;
		asorted4[i] = aux;
		asorted5[i] = aux;
		asorted6[i] = aux;
        i++; // Numero de elementos
    }

	// Muestra el arreglo a ordenar y su numero de elementos
    printArray(asorted1, i);
	cout << "Elementos: " << i << endl;

    cout << "\n\nSeleccion-Sort "<< endl;
	selectionSort(asorted1, i);
	printArray(asorted1, i);

	cout << "\n\nBubble-Sort "<< endl;
	bubbleSort(asorted2, i);
	printArray(asorted2, i);

	cout << "\n\nSwap-Sort "<< endl;
	swapSort(asorted3, i);
	printArray(asorted3, i);

	cout << "\n\nInsertion-Sort "<< endl;
	insertionSort(asorted4, i);
	printArray(asorted4, i);

	cout << "\n\nMerge-Sort "<< endl;
	mergeSort(asorted5, i, 0, i - 1);
	printArray(asorted5, i);

	cout << "\n\nQuick-Sort "<< endl;
	mergeSort(asorted6, i, 0, i - 1);
	printArray(asorted6, i);

    return 0;
}