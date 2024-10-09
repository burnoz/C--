#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

// Class node: un valor y un puntero a otro nodo
class Node{	
    public:
		int value;		//	valor almacenado
		Node *next;		//	puntero a otro nodo
	
		Node(int value){	
            this->value = value;
			this->next = NULL;
		}
};

// Class dNode: un valor y dos punteros a otros nodos
class dNode{	
    public:
        int value;		//	valor almacenado
        dNode *next;	//	puntero al siguiente nodo
        dNode *prev;	//	puntero al nodo anterior

        dNode(int value){	
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Class pNode: un valor, dos punteros y su prioridad
class pNode{
    public:
        int value;      // valor almacenado
        int priority;   // prioridad de salida
        pNode *next;    // puntero al siguiente nodo
        pNode *prev;    // puntero al nodo anterior

        pNode(int value, int priority){
            this->value = value;
            this->priority = priority;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Fila prioritacia con lista enlazada doble
class PQueue{
    private:
        pNode *first;   // Puntero al primer nodo
        pNode *last;    // Puntero al ultimo nodo
        int size;       // Numero de elementos en la lista
        int maxSize;    // Numero maximo de elementos

    public:
        // Constructor
        PQueue(int maxSize){
            this->first = NULL;
            this->last = NULL;
            this->size = 0;
            this->maxSize = maxSize;
        }

        // Destructor
        ~PQueue(){
            // Elimina todos los nodos
            while(first != NULL){
                pNode *aux = first;
                first = first->next;
                delete aux;
            }
        }

        // Funciones de la fila prioritaria
        bool enqueue(int, int);
        int dequeue();
        int getSize();
        int getFront();
        bool isEmpty();
        bool isFull();
        void show();
};

// Agrega un nuevo elemento en la fila
// Complejidad O(n)
bool PQueue::enqueue(int value, int priority){
    if(!this->isFull()){
        // Crea un nuevo nodo con el elemento a agregar
        pNode *node = new pNode(value, priority);

        // Conecta el nodo con la lista
        if(first == NULL){
            first = node;
            last = node;
        }

        else{
            pNode *aux = first;
            while(aux != NULL && aux->priority <= priority){
                aux = aux->next;
            }

            if(aux == NULL){
                last->next = node;
                node->prev = last;
                last = node;
            }

            else if(aux == first){
                node->next = first;
                first->prev = node;
                first = node;
            }

            else{
                node->next = aux;
                node->prev = aux->prev;
                aux->prev->next = node;
                aux->prev = node;
            }
        }

        size++;
        return true;
    }

    cout << "Fila de prioridad llena" << endl;
    return false;
}

// Elimina el elemento con mayor prioridad
// Complejidad: O(1)
int PQueue::dequeue(){
    if(!this->isEmpty()){
        int value = first->value;
        pNode *aux = first;
        first = first->next;
        delete aux;
        size--;
        return value;
    }

    return -1;
}

// Obtiene el numero de elementos
// Complejidad: O(1)
int PQueue::getSize(){
    return size;
}

// Obtiene el valor del elemento con mayor prioridad
int PQueue::getFront(){
    if(this->isEmpty()){
        return -1;
    }

    return first->value;
}

// Verifica si la lista esta vacia
// Complejidad: O(1)
bool PQueue::isEmpty(){
    return size == 0;
}

// Verifica si la lista esta llena
// Complejidad O(1)
bool PQueue::isFull(){
    return this->size == this->maxSize;
}

// Muestra los elementos de la lista
// Complejidad: O(n)
void PQueue::show(){
    int i = 0;

    cout << "Numero de elementos en la fila de prioridad:\t" << this->getSize() << endl;

    pNode *aux = this->first;

    while(aux != NULL){
        cout << "data[" << i << "]:\t" << aux->value << "\t priority: " << aux->priority << endl;
        aux = aux->next;
        i++;
    }

    cout << endl;
}

// Fila con lista enlazada doble
class Queue{
    private:
        dNode *first;	// Puntero al primer nodo
        dNode *last;	// Puntero al ultimo nodo
        int size;		// Numero de elementos en la lista
        int maxSize;    // Numero maximo de elementos

    public:
        // Constructor
        Queue(int maxSize){	
            this->first = NULL; 
            this->last = NULL;
            this->size = 0;
            this->maxSize = maxSize;
        }
        
        // Destructor
        ~Queue(){	
            // Elimina todos los nodos
            while(first != NULL){
                dNode *aux = first;
                first = first->next;
                delete aux;
            }
        }

        // Funciones de la fila
        bool enqueue(int);
        int dequeue();
        int getSize();
        int getFront();
        bool isEmpty();
        bool isFull();
        void show();
};

// Agrega un nuevo elemento
// Complejidad: O(1)
bool Queue::enqueue(int value){
    if(!this->isFull()){
        // Crea un nuevo nodo con el elemento a agregar
        dNode *node = new dNode(value);
        
        // Conecta el nodo con la lista
        if(first == NULL){
            first = node;
            last = node;
        }

        else{
            last->next = node;
            node->prev = last;
            last = node;
        }
        
        // Incrementa el numero de elementos
        size++;
        return true;
    }
    
    cout << "Fila llena" << endl;
    return false;
}

// Elimina el elemento siguiente
// Complejidad: O(1)
int Queue::dequeue(){
    // Verifica si la lista esta vacia
    if(!this->isEmpty()){
        // Obtiene el valor del primer nodo
        int value = first->value;
        
        // Elimina el primer nodo
        dNode *aux = first;
        first = first->next;
        delete aux;
        
        // Disminuye el numero de elementos
        size--;
        return value;    
    }

    return -1;
}

// Obtiene el numero de elementos
// Complejidad: O(1)
int Queue::getSize(){	
    return size;
}

// Obtiene el valor del elemento siguiente
int Queue::getFront(){	
    // Verifica si la lista esta vacia
    if(this->isEmpty()){
        return -1;
    }

    return first->value;
}

// Verifica si la lista esta vacia
// Complejidad: O(1)
bool Queue::isEmpty(){	
    return size == 0;
}

// Verifica si la lista esta llena
// Complejidad O(1)
bool Queue::isFull(){
    return this->size == this->maxSize;
}

// Muestra los elementos de la lista
// Complejidad: O(n)
void Queue::show(){	
    // Define un contador i = 0
    int i = 0;

    // Imprime cuantos elementos hay en la lista
    cout << "Numero de elementos en la fila:\t" << this->getSize() << endl;

    //	Usa un nodo auxiliar, cuyo valor inicial es first para recorrer la lista
    dNode *aux = this->first;

    //	Mientras next en el auxiliar no sea null...
    while(aux != NULL){
        //  Imprime el valor de i y del nodo
        cout << "data[" << i << "]:\t" << aux->value << endl;
        //  Avanza en la lista, haciendo que aux = aux->next
        aux = aux->next;
        //  Aumenta el contador i
        i++;
    }

    cout << endl;
}


// Stack con lista enlazada simple
class Stack{
    private:
        Node *first;	// Puntero al primer nodo
        int size;		// Numero de elementos en la lista
        int maxSize;    // Numero maximo de elementos

    public:
        // Constructor
        Stack(int maxSize){	
            this->first = NULL; 
            this->size = 0;
            this->maxSize = maxSize;
        }
        
        // Destructor
        ~Stack(){	
            // Elimina todos los nodos
            while(!this->isEmpty()){
                Node *aux = first;
                first = first->next;
                delete aux;
            }
        }

        // Funciones de la pila
        bool push(int);
        int pop();
        int getSize();
        int getTop();
        bool isEmpty();
        bool isFull();
        void show();
};

// Agrega un nuevo elemento
// Complejidad: O(1)
bool Stack::push(int value){
    if(!this->isFull()){
        // Crea un nuevo nodo
        Node *node = new Node(value);
        
        // Conecta el nodo con la lista
        node->next = first;
        first = node;
        
        // Incrementa el numero de elementos
        size++;
        return true;
    }

    cout << "Pila llena" << endl;
    return false;
}

// Elimina el elemento siguiente
// Complejidad: O(1)
int Stack::pop(){	
    // Verifica si la lista esta vacia
    if(!this->isEmpty()){
        // Obtiene el valor del primer nodo
        int value = first->value;

        // Elimina el primer nodo
        Node *aux = first;
        first = first->next;
        delete aux;

        // Disminuye el numero de elementos
        size--;
        return value;        
    }

    cout << "Pila vacia" << endl;
    return -1;
}

// Obtiene el numero de elementos
// Complejidad: O(1)
int Stack::getSize(){	
    return size;
}

// Obtiene el valor del elemento siguiente
// Complejidad: O(1)
int Stack::getTop(){	
    // Verifica si la lista esta vacia
    if(first == NULL){
        return -1;
    }

    return first->value;
}

// Verifica si la lista esta vacia
// Complejidad: O(1)
bool Stack::isEmpty(){	
    return size == 0;
}

// Verifica si la lista esta llena
// Complejidad O(1)
bool Stack::isFull(){
    return this->size == this->maxSize;
}

// Muestra los elementos de la lista
// Complejidad: O(n)
void Stack::show(){	
    // Define un contador i = 0
    int i = 0;

	// Imprime cuantos elementos hay en la lista
    cout << "Numero de elementos en la pila:\t" << this->getSize() << endl;

	//	Usa un nodo auxiliar, cuyo valor inicial es first para recorrer la lista
    Node *aux = this->first;

	//	Mientras next en el auxiliar no sea null...
    while(aux != NULL){
		//  Imprime el valor de i y del nodo
        cout << "arreglo[" << i << "]:\t" << aux->value << endl;
		//  Avanza en la lista, haciendo que aux = aux->next
        aux = aux->next;
	    //  Aumenta el contador i
        i++;
    }

    cout << endl;
}


int main(){
    int max = 8;

    Stack *stack = new Stack(max);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->show();

    int value = stack->pop();
    cout << "Sale: " << value << endl;
    stack->show();

    cout << "-----------------------" << endl;

    Queue *queue = new Queue(max);
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->show();

    value = queue->dequeue();
    cout << "Sale: " << value << endl;
    queue->show();

    cout << "-----------------------" << endl;

    PQueue *pqueue = new PQueue(max);
    pqueue->enqueue(1, 8);
    pqueue->enqueue(3, 3);
    pqueue->enqueue(3, 1);
    pqueue->enqueue(2, 2);
    pqueue->enqueue(4, 3);
    pqueue->show();    

    value = pqueue->dequeue();
    cout << "Sale: " << value << endl;
    pqueue->show();
}