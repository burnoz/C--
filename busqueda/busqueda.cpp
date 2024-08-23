#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Complejidad O(log(n))
// A: arreglo, l: limite inferior, r: limite superior, x: elemento a buscar
int busquedaBinariaRec(int A[], int l, int r, int x){
	// Elemento no encontrado
	if(l > r){
		return -1;
	}

	// Elemento en la mitad del arreglo
	int i = l + (r - l) / 2;

	// Caso base (se encuentra el elemento)
	if(x == A[i]){
		return i;
	}

	// Busqueda en la mitad izquierda
	else if(x < A[i]){
		return busquedaBinariaRec(A, l, i - 1, x);
	}

	// Busqueda en la mitad derecha
	else{
		return busquedaBinariaRec(A, i + 1, r, x);
	}


	return -1;
}

// Complejidad O(log(n))
int busquedaBinaria(int A[], int n, int x){   
	int l = 0;
	int r = n - 1;

	while(l <= r){
		int i = l + (r - l) / 2;

		if(A[i] == x){
			return i;
		}

		if(A[i] < x){
			l = i + 1;
		}
		
		else{
			r = i - 1;
		}
	}

	// Elemento no encontrado
	return -1;
}

// Complejidad O(n)
// *A: puntero al arreglo, n: tamaño del arreglo, x: elemento a buscar
int busquedaSecuencial(int *A, int n, int x){
	int i;

	// Pasa por todos los elementos del arreglo
	for(i = 0; i < n; i++){
		if(x == A[i]){
			// Indice del elemento encontrado
			return i;
		}
	}

	// Si no se encuentra el elemento
	return -1;
}


int main(int argc, char* argv[]){	
	const int n = 10;		//	Elementos totales
	int x;					//	Elemento a buscar
	
	int indexSeq, indexBin, indexBinRec;

	//	Arreglos: ordenado y desordenado
	int sorted [n] =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	
	int asorted [n] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	
	x = atoi(argv[1]);		//	Valor a buscar, leido desde consola
	// cin >> x;
	// x = 4;


	//	Imprimir los arreglos donde se buscara
	int i;
	cout<<"Ordenado:\t";
	for (i = 0; i < n; i++) 	{	cout<<sorted[i]<<' '; } 
	cout<<endl;

	cout<<"Desordenado:\t";
	for (i = 0; i < n; i++) 	{	cout<<asorted[i]<<' '; } 
	cout<<endl;

	
	cout<<"\nBuscando:\t"<< x <<endl;

	cout<< "Buscando x = " << x << " en asorted con busq. secuencial: "<< endl;
	indexSeq = busquedaSecuencial(asorted, n, x);
	cout << "Resultado: " << indexSeq << " " << endl << endl;



	cout << "Buscando x = " << x << " en sorted con busq. secuencial: "<< endl;
	indexSeq = busquedaSecuencial(sorted, n, x);
	cout << "Resultado " << indexSeq <<endl<< endl;



	cout << "Buscando x = " << x << " en sorted con busq. binaria: " ;
	indexBin = busquedaBinaria(sorted, n, x);
	cout << "Resultado  " << indexBin << endl<<endl;



	cout << "Buscando x = " << x << " en sorted con busq. binaria recursiva: " ;
	indexBinRec = busquedaBinariaRec(sorted, 0, n-1 , x);	
	cout << "Resultado  " << indexBinRec << endl<< endl;
}