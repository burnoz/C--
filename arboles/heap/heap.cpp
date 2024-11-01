#include <iostream>
#include <sstream>
#include <cstring>
#include <math.h>
#include <string>

using namespace std;

// Clase para heap
template <class T>
class Heap{
    public:
        T *data;
        int maxSize;
        int currentSize;

        // Constructor
        Heap(int n){
            maxSize = n;
            currentSize = 0;
            data = new T(maxSize);
        }

        // Destructor
        ~Heap(){
            delete[] data;
            maxSize = 0;
            currentSize = 0;
        }

        // Funciones
        bool isEmpty();
        bool isFull();

        T getTop();
        int parent(int);
        int left(int);
        int right(int);

        void push(T);
        T pop();
        void heapify(int);
        void swap(int, int);
        void show();
};

// Verifica si el heap esta vacio
// Complejidad O(1)
template <class T>
bool Heap<T>::isEmpty(){
    return currentSize == 0;
}

// Verifica si el heap esta lleno
// Complejidad O(1)
template <class T>
bool Heap<T>::isFull(){
    return currentSize == maxSize;
}

// Obtiene el valor superior del heap
// Complejidad O(1)
template <class T>
T Heap<T>::getTop(){
    return data[0];
}

// Obtiene el indice del padre
// Complejidad O(1)
template <class T>
int Heap<T>::parent(int i){
    return (i - 1) / 2;
}

// Obtiene el indice del hijo izquierdo
// Complejidad O(1)
template <class T>
int Heap<T>::left(int i){
    return 2 * i + 1;
}

// Obtiene el indice del hijo derecho
// Complejidad O(1)
template <class T>
int Heap<T>::right(int i){
    return 2 * i + 2;
}

// Inserta un valor
// Complejidad O(nlog(n))
template <class T>
void Heap<T>::push(T value){
    if(!isFull()){
        int i = currentSize;
        int p = parent(i);

        while(i > 0 && value < data[p]){
            data[i] = data[p];
            i = p;
            p = parent(p);
        }

        data[i] = value;
        currentSize++;
    }

    else{
        cout << "Heap lleno" << endl;
    }
}

// Regresa el valor superior y lo elimina
// O(log(n))
template <class T>
T Heap<T>::pop(){
    if(!isEmpty()){
        T value = data[0];
        data[0] = data[currentSize - 1];
        currentSize--;
        heapify(0);
        return value;
    }

    else{
        cout << "Heap vacio" << endl;
        return -1;
    }
}

// Reordena el heap
// Complejidad O(log(n))
template <class T>
void Heap<T>::heapify(int index){
    int l = left(index);
    int r = right(index);
    int i = index;

    if(l < currentSize && data[l] < data[i]){
        i = l;
    }

    if(r < currentSize && data[r] < data[i]){
        i = r;
    }

    if(i != index){
        swap(index, i);
        heapify(i);
    }
}

// Intercambia dos valores
// Complejidad O(1)
template <class T>
void Heap<T>::swap(int i, int j){
    T aux = data[i];
    data[i] = data[j];
    data[j] = aux;
}

// Muestra el heap
// Complejidad O(n)
template <class T>
void Heap<T>::show( ){	
    int i;
	int level = 0;
	cout << "Size: " << currentSize << endl ;

	i = pow(2, level);

	while(i-1 < currentSize){	
        cout << "\t" << data[i-1] << "(" << level << ")" ;	
		i++;

		if ((i) == pow(2, level+1)){	
            cout << endl;
			level++;
		}
	}
	cout << endl ;
}


int main(){
    // Agregar los elementos: 2, 1, 5, 7, 9, 8, 4, 3, 6, 7
    Heap<int> *heap = new Heap<int>(12);
    heap->push(2);
    heap->push(1);
    heap->push(5);
    heap->push(7);
    heap->push(9);
    heap->push(8);
    heap->push(4);
    heap->push(3);
    heap->push(6);
    heap->push(7);

    heap->show();
    cout << endl;

    // Eliminar el valor en el top
    cout << "Valor eliminado: " << heap->pop() << endl;
    heap->show();
    cout << endl;

    // Agregar los valores 3, 1 y 4
    heap->push(3);
    heap->push(1);
    heap->push(4);

    heap->show();
    cout << endl;

    // Extraer los valores del montículo hasta que quede vacío. Muestra los valores extraídos
    cout << "Valores en el heap: ";
    while(!heap->isEmpty()){
        cout << heap->pop() << " ";
    }
}