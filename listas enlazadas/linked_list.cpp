#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

// class node: un valor y un puntero a otro nodo
class Node{	
    public:
		int value;		//	valor almacenado
		Node *next;		//	puntero a otro nodo
	
		Node(int value){	
            this->value = value;
			this->next = NULL;
		}
};

//  Clase lista enlazada simple: 
class List{	
    Node *first;   // Puntero al nodo inicial 
	int size;      // y numero de elementos totales

	public:
		List(){	
            first = NULL; 
			size = 0;
		}
		
		int getSize(){ return size; } 	// Devuelve cuantos elementos hay
		void showList(); 				// Imprime los elementos

		Node* find(int, int*);		// Encuentra un valor y devuelve la direccion del nodo
		
		void insertLast(int);		//	Agregua valor al inicio
		void insertFirst(int);		//	Agrega valor al fianl

		bool insertAtIndex(int, int); // <-- Actividad
		void update(int, int);		// <--- Actividad cambiar el valor en un indice
		
		void deleteFirst();
		void deleteLast();			// <--- Actividad	
		void deleteAtIndex(int);	// <--- Actividad

};


void List::showList(){	
    // Define un contador i = 0
    int i = 0;

	// Imprime cuantos elementos hay en la lista
    cout << "List size:\t" << this->getSize() << endl;

	//	Usa un nodo auxiliar, cuyo valor inicial es first para recorrer la lista
    Node *aux = this->first;

	//	Mientras next en el auxiliar no sea null...
    while(aux != NULL){
		//  Imprime el valor de i y del nodo
        cout << "El [" << i << "] elemento es:\t" << aux->value << endl;
		//  Avanza en la lista, haciendo que aux = aux->next
        aux = aux->next;
	    //  Aumenta el contador i
        i++;
    }

    cout << endl;
}

/*Inserta nodo nuevo al inicio de la lista*/
void List::insertFirst(int newValue){	
    // Crea un nodo nuevo llamando al constructor de nodo
	// Sintaxis: clase *nombre = new  constructor_clase( params );
    Node *node = new Node(newValue);

	// Enlaza el nodo nuevo para apuntar a first como su siguiente
    node->next = this->first;

	// Actualiza first, ahora es el nodo nuevo
    this->first = node;

	// Aumenta la cantidad de elementos en la lista
    this->size++;
}

// Insertar nuevo nodo al final 
void List::insertLast(int newValue){	
	// Si la lista esta vacia, inserta el nuevo valor al inicio
    if(this->size == 0){
        this->insertFirst(newValue);
    }
	// Si no...
    else{
		// Crea un nodo nuevo
        Node *node = new Node(newValue);

		//	Usa un nodo auxiliar, cuyo valor inicial es first para recorrer la lista:
        Node *aux = this->first;

		//	Mientras el siguiente auxiliar no sea null...
        while(aux->next != NULL){
			//  Avanza en la lista, haciendo que aux = aux->next
            aux = aux->next;
        }

        // Enlaza aux con el nodo nuevo
        aux->next = node;
    }

    // Aumenta la cantidad de elementos en la lista
    this->size++;
}

// Inserta en un indice especifico
bool List::insertAtIndex(int index, int newValue){
	Node *aux = this->first;					//	Comenzamos en el primer link
	Node *node = new Node(newValue);    //  Creamos el nodo nuevo

	if(index == 0){					//	Nuevo al inicio
        insertFirst(newValue);	
		return true;
	}

	else if(index == this->size){		    //	Nuevo al final	
        insertLast(newValue);	
		return true;
	}

	else{
	    //	Insertar nuevo enmedio
		int i = 0;		//	contador para el indice
		
		// Usa un while para recorrer la lista, contando con i
        while(i < index - 1){
			aux = aux->next;
			i++;
		}

		// Cuando llegues al indice, agrega el nodo
		node->next = aux->next;
		aux->next = node;

		// Actualiza el numero de elementos de la lista
		this->size++;

		return true;
	}	
 
	cout << "Indice no valido" << endl;
	return false; 
}

// 	Elimina el primer elemento de la lista
void List::deleteFirst(){	
    // Asigna first a un nodo auxiliar
	Node *aux = this->first;

	// Haz que first sea el siguiente auxiliar
	// De modo que el nodo next de first se vuelve el nuevo first
	this->first = aux->next;
	
	// Elimina auxiliar con delete. Sintaxis delete nombre_ptr;
	delete aux;

	// Actualiza el numero de elementos de la lista
	this->size--;
}

// 	Elimina el primer elemento de la lista
void List::deleteLast(){
	// Nodo auxiliar
	Node *aux = this->first;

	if(this->size == 0){
		this->deleteFirst();
	}

	else{
		// Recorre la lista hasta el penultimo nodo
		while(aux->next->next != NULL){
			aux = aux->next;
		}

		// Elimina el ultimo nodo
		delete aux->next;
		aux->next = NULL;
	}

	this->size--;
}


void List::deleteAtIndex(int index){
	if(index == 0){
		this->deleteFirst();
	}

	else if(index == this->size - 1){
		this->deleteLast();
	}

	else{
		// Variable contadora
		int i = 0;

		Node *aux = this->first; // Nodo auxiliar
		Node *aux_2; // Nodo a aliminar

		// Recorre la lista hasta el elemento anterior al que se va a eliminar
		while(i < index - 1){
			aux = aux->next;
			i++;
		}

		// Elimina el nodo
		aux_2 = aux->next;
		aux->next = aux_2->next;
		delete aux_2;
	}

	this->size--;
}


Node* List::find(int value, int *index){
	Node *aux = this->first; // Nodo auxiliar
	int i = 0; // Variable contadora

	// Recorre la lista
	while(aux != NULL){
		// Compara el elemento actual con el valor a buscar
		if(aux->value == value){
			// Guarda el indice y devuelve el nodo en que se encontro el elemento
			*index = i;
			return aux;
		}

		// Avanza en la lista e incrementa el indice
		aux = aux->next;
		i++;
	}

	// Caso en el que no se encuentra el elemento
	return NULL;
}


void List::update(int new_value, int index){
	Node *aux = this->first; // Nodo auxiliar
	int i = 0; // Variable contadora

	// Avanza en la lista hasta llegar al elemento a actualizar
	while(i < index){
		// Actualiza el nodo auxiliar y el valor del indice
		aux = aux->next;
		i++;
	}

	// Asigna el nuevo valor en el indice dado
	aux->value = new_value;
}


int main(int argc, char* argv[]) {	
    List list;

	// cout << " Nada por ahora :P" << endl;

	list.insertFirst(1); 	list.showList();
	list.insertFirst(0); 	list.showList();

	list.insertLast(4); 	list.showList();
	list.insertLast(2); 	list.showList();

	list.insertAtIndex(3, 3); 	list.showList();

	list.deleteFirst(); 	list.showList();
	list.deleteLast(); 	list.showList();

	list.deleteAtIndex(1); 	list.showList();

	int index;
	Node *a = list.find(3, &index);
	cout << "Encontrado en memoria: " <<a << " index: " << index << endl << endl;

	list.update(5, 1);	list.showList();
}