//g++ listaEnlazadaEj.cpp -o listaEnlazadaDoble; ./listaEnlazadaDoble

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;


// class node: un valor y un puntero a otro nodo
template <class T>		//	Esta linea permite que podamos crear listas de cualquier tipo de dato
class Node{	
    public:
		//	Atributos del nodo

		//int value;		// En lugar de que el nodo guarde un entero, guarda algo de tipo T
		T value; 			// valor almacenado

		Node<T> *prev; 	 	//	dir del nodo anterior
		Node<T> *next;		//	dir del nodo siguiente
		
		
		//	Que deberia recibir el contructor de la clase? 
		//		un valor para guardar en el nodo
		//	Que valores por default deberian tener prev y next? 
		Node(T valor)
		{	this->value = valor;
			this->prev = NULL;
			this->next = NULL;
		}
};

//  Clase lista enlazada doble: 
template <class T>
class List{	
    //	Que atributos necesita??

	Node<T> *first;		//	puntero al primer nodo
	Node<T> *last; 	//	puntero al ultimo nodo	
	int size;			//	numero de elementos que tiene la lista

	public:
		//	Que valores deberia tener la lista por default??
		List(){	
            this->first = NULL; 
			this->last = NULL; 
			this->size = 0;
		}
		
		//	Funciones similares a las de la lista simple


		int getSize(){ return size; }	//	Funcion para obtener el tamanaño de la lista
		void showList();				//	Funcion para mostrar la lista
		void showListReverse();			//	Funcion para mostrar la lista en reversa
		
		//	Funciones para insertar elementos
		void insertFirst(T);				//	al principio
		void insertLast(T);					//	al final
		bool insertAtIndex(int, T); 		//	en un indice

		//	Funciones para eliminar elementos
		void deleteFirst();					//	al principio
		void deleteLast();					//	al final				
		void deleteAtIndex(int); 			//	en un indice		

		Node<T>* find(T, int*);			//	Encontrar un valor	
		void update(int, T);			//	Actualizar el valor de un indice
};
/**/
// inserta en un indice especifico
template<class T>
bool List<T>::insertAtIndex(int index, T newValue){	
    Node<T> *node = new Node<T> (newValue);  
	
	//	insertar al inicio 
	if (index == 0){	
        this->insertFirst(newValue); 
		return true;
	}

	if (index == this->size){	
        this->insertLast(newValue); 
		return true;
	}

	if (index < size/2){		//	cuando es mas barato insertar desde el inicio	
        Node<T> *aux = first;
		int i = 0; 

		while(i < size/2){	
            if (i == index - 1){	
                node->prev = aux;
				node->next = aux->next; 

				node->next->prev = node; 
				aux->next = node;
				this->size++;
				return true;
			}

			aux = aux->next;
			i++;
		}
	}

	else{  	//	cuando es mas barato insertar desde el final 
		Node<T> *aux = last;
		int i = this->size - 1;

		while(i > size/2){
			if(i == index){
				node->next = aux;
				node->prev = aux->prev;

				node->prev->next = node;
				aux->prev = node;
				this->size++;
				return true;
			}

			aux = aux->prev;
			i--;
		}
	}

	return false;
}

template<class T>
Node<T>* List<T>::find(T value, int *index){	
	Node<T> *aux = first;
	int i = 0;

	while(i < this->size){	
		if(aux->value == value){	
			*index = i;
			return aux;
		}

		aux = aux->next;
		i++;
	}

	*index = -1;
	return NULL;
}
/*
*/
// inserta al inicio
template<class T>
void List<T>::deleteFirst(){	
    //  Crear un  auxiliar que guarde la direccion de first
	Node<T> *aux = first;
	
	//	Crear una puntero, llamado segundo, que tome la direccion del nodo siguiente de first
	Node<T> *second = aux->next;
	//  Asigna que el anterior a segundo ahora es last
	second->prev = last; 

	//  Y que el siguiente de last es segundo
	last->next = second;

	// Elimina aux con un delete
	delete aux;	
	
	// Ahora first es segundo
	this->first = second;

	// Decrementa el tamaño
	this->size--;	
	
}

// inserta al inicio
template<class T>
void List<T>::insertFirst(T newValue){	
    // Crear un nodo nuevo
	// Sintaxis: 
	// Clase<plantilla> *nombre = new Clase<plantilla>(parametros)
	Node<T> *node = new Node(newValue);

	// Crear un puntero auxiliar que guarde la direccion de first
	Node<T> *aux = first;

	// Hacer que el siguiente del nodo nuevo sea el auxiliar
	node->next = aux;
	// Y que el first ahora sea el nodo nuevo
	this->first = node;


	// Si la lista esta vacia
	if(this->size == 0){
		//	el ultimo es tambien el nodo nuevo
		this->last = node;
	}

	// Si no, 
	else{
		// el anterior a aux (viejo first) es ahora el nodo nuevo
		aux->prev = node; 
	}	

	// Para asegurar que la lista es circular
	// El anterior a first es last
	// El siguiente de last es first

	//	Finalmente actualizar el tamaño de la lista
	this->size++;
}


// inserta al final
template<class T>
void List<T>::insertLast(T newValue){	
    // Crear un nodo nuevo
	// Sintaxis: 
	// Clase<plantilla> *nombre = new Clase<plantilla>(parametros)
	Node<T> *node = new Node<T>(newValue);

	// Crear un puntero auxiliar que guarde la direccion de last
	Node<T> *aux = this->last;

	// Hacer que el anterior del nodo nuevo sea el auxiliar (viejo last)
	node->prev = aux;
	// Y que el nuevo last ahora sea el nodo nuevo
	this->last = node;
	

	// Si la lista esta vacia
	if(this->size == 0){
		//	el first es tambien el nodo nuevo
		this->first = node;
	}

	// Si no, 
	else{
		// el siguiente a aux (viejo last) es ahora el nodo nuevo
		aux->next = node; 
	}
	
	// Para asegurar que la lista es circular
	// El anterior a first es last
	// El siguiente de last es first
	
	//	Finalmente actualizar el tamaño de la lista
	this->size++;
}

template<class T>
void List<T>::showList(){	
    // Crea un nodo auxiliar para iterar en la lista
	// auxiliar inicia en first
	Node<T> *aux = this->first;

	// Declara un contador i que inicie en 0
	int i = 0;

	// Imprime el tamaño de la lista
	cout <<  this->size << " elementos" << endl;

	// Mientras i sea menor que el tamaño... 
	while(i < this->size){	
        // Imprime el nodo
		cout << "El [" << i << "] elemento es:\t" << aux->value << endl;
		
		// aux avanza a aux->next
		aux = aux->next;

		// i incrementa
		i++;
	}

	cout << endl;
}

template<class T>
void List<T>::showListReverse(){
	// Crea un nodo auxiliar para iterar en la lista
	// auxiliar inicia al final de la lista
	Node<T> *aux = last;

	// Declara un contador i con el tamaño de la lista
	int i = this->size - 1;

	while(i >= 0){
		// Imprime el nodo
		cout << "El [" << i << "] elemento es:\t" << aux->value << endl;
		
		// aux retrocede a aux->prev
		aux = aux->prev;

		// i disminuye
		i--;
	}

	cout << endl;
}


template<class T>
void List<T>::update(int index, T newValue){
	
}


int main(int argc, char* argv[]) {	
 	List<int> dList;

	cout << "boing" << endl;

 	dList.insertLast(2); 	dList.showList(); 	dList.showListReverse();
 	dList.insertLast(3); 	dList.showList(); 	dList.showListReverse();
	dList.insertFirst(1); 	dList.showList(); 	dList.showListReverse();
	dList.insertFirst(0); 	dList.showList(); 	dList.showListReverse();



	cout << "\n Insert at index\n " << endl;

	dList.insertAtIndex(4, 5); 	dList.showList(); 	dList.showListReverse();	
    dList.insertAtIndex(4, 4); 	dList.showList(); 	dList.showListReverse();


	dList.deleteFirst(); 	dList.showList(); 	dList.showListReverse();

	int index = -1;
	Node<int> *address = dList.find(3, &index);
	
	cout << "dir: " << address << " index: " << index << " value: " << address->value << endl;	
}