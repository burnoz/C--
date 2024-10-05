#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

class Stack{
	private:
		int top = -1; 
		int *arreglo;
		int size = 0;
		int maxSize; 

	public:
		// Constructor
		Stack(int maxSize){
            this->maxSize = maxSize; 
			arreglo = (int *) malloc(maxSize * sizeof(int));
		}

		//	Destructor de la clase
		~Stack(){   delete[] this->arreglo; }

		bool push (int valor);
		int pop();
		int getSize();
		int getTop();
		bool isEmpty();
		bool isFull();

		void show();
};

// Agrega un nuevo elemento en el top
// Complejidad: O(1)
bool Stack::push(int valor){	
    // Primero revisa si hay espacio (si no esta llena)
	if(!this->isFull()){
		// Agrega el valor y actualiza top y size
		arreglo[top + 1] = valor;

		this->top++;
		this->size++;
		return true;
	}

	// En caso de que ya no quepan mas elementos
	cout << "Stack llena" << endl;
	return false;
}

// Extrae el elemento del top
// Complejidad: O(1)
int Stack::pop(){	
	// Primero revisa que no este vacia
	if(!this->isEmpty()){
		// Extrae el valor y actualiza top y size
		int val = arreglo[top];

		top--;
		size--;
		return val;
	}

	// En caso de que no haya elementos
	cout << "Esta vacia" << endl;
	return -1;
}

// Devuelve el tamano del stack
int Stack::getSize(){
	return this->size;
}

// Devuelve el siguiente elemento
int Stack::getTop()
{	return arreglo[top];	}

// Verifica si el stack esta vacio
bool Stack::isEmpty()
{	return this->size == 0;	}

// Verifica si la pila esta llena
bool Stack::isFull()
{	return this->size == this->maxSize;	}

// Muestra el stack en la consola
void Stack::show(){	
    int i;

	for (i = 0; i < this->size; i++){	
        cout << "arreglo["<< i <<"]: " << arreglo[i] << endl;	
    }

	cout << endl;
}


class Queue {
	private:
		int *data;
		int front;
		int end;
		int maxSize;
		int size;

	public:
		// Constructor
		Queue(int maxSize){   
			this->maxSize = maxSize;
			this->data = (int *) malloc(this->maxSize * sizeof(int));
			this->front = -1;
			this->end = -1;
			this->size = 0;
		}

		// Destructor
		~Queue(){	
			free(this->data);	
			//	delete[] this->data;
		}

	bool enqueue(int);
	int dequeue();
	int getSize();
	int getFront();
	bool isEmpty( );  
	bool isFull( );

	void show();
};

// Agrega un nuevo elemento en la fila
// Complejidad: O(1)
bool Queue::enqueue(int value){	
	// Primero revisa si hay espacio (si no esta llena)
	if(!this->isFull()){
		// Si esta vacia, actualiza front y end
		if(this->isEmpty()){
			this->front = 0;
			this->end = 0;
		}

		// Agrega el valor y actualiza end y size
		data[end % this->maxSize] = value;

		this->end++;
		this->size++;
		return true;
	}

	// En caso de que ya no quepan mas elementos
	cout << "Fila llena" << endl;
	return true;
}

// Extrae el elemento siguiente
// Complejidad: O(1)
int Queue::dequeue(){
	// Primero revisa que no este vacia
	if(!this->isEmpty()){
		// Extrae el valor y actualiza front y size
		int val = data[front % this->maxSize];

		size--;
		front++;
		return val;
	}

	// En caso de que no haya elementos
	cout << "Fila vacia" << endl;
    return -1;
}

// Devuelve elemento siguiente
int Queue::getFront(){	
	return data[front % this->maxSize];
}

// Devuelve el tamano de la fila
int Queue::getSize(){	
	return this->size;	
}

// Verifica si la fila esta vacia
bool Queue::isEmpty(){	
	return this->size == 0;	
}

// Verifica si la fila esta llena
bool Queue::isFull(){	
	return this->size == maxSize;
}

// Muestra la fila en la consola
void Queue::show(){
	int i;

	for(i = this->front; i < this->end; i++){
        cout << "data["<< i % this->maxSize <<"]: " << data[i % this->maxSize] << endl;	
    }

	cout << endl;
}

// Elementos para la fila con prioridad
class element{
	public:
		int data;
		int priority;
};


class PQueue{
	private:
		element *data;
		int maxSize;
		int size;

	public:
		// Constructor
		PQueue(int maxSize){
			this->maxSize = maxSize;
			this->data = new element[maxSize];
			this->size = 0;
		}

		// Destructor
		~PQueue(){
			delete[] this->data;
		}

		bool enqueue(int, int);
		int dequeue();
		int getFront();
		int getSize();
		bool isEmpty();
		bool isFull();

		void show();
};

// Agrega un nuevo elemento en la fila
// Complejidad: O(1)
bool PQueue::enqueue(int value, int priority){
	// Primero revisa si hay espacio (si no esta llena)
	if(!this->isFull()){
		// Agrega el valor y actualiza size
		data[size].data = value;
		data[size].priority = priority;

		size++;
		return true;
	}

	// En caso de que ya no quepan mas elementos
	cout << "Fila de prioridad llena" << endl;
	return false;
}

// Extrae el elemento siguiente
// Complejidad: O(n)
int PQueue::dequeue(){
	// Primero revisa que no este vacia
	if(!this->isEmpty()){
		// Obtiene el elemento con la mayor prioridad
		int front = getFront();
		int value = data[front].data;

		// Mueve los elementos
		for(int i = front; i < size - 1; i++){
			data[i] = data[i + 1];
		}

		// Actualiza size y devuelve el valor
		size--;
		return value;
	}

	// En caso de que no haya elementos
	cout << "Fila de prioridad vacia" << endl;
	return -1;
}

// Devuelve el elemento con mayor prioridad
// Complejidad: O(n)
int PQueue::getFront(){
	// Primero revisa que no este vacia
	if(!isEmpty()){
		// Caso por default (el primero es el de mayor prioridad)
		int front = 0;

		// Busca el elemento con la mayor prioridad
		for(int i = 1; i < size; i++){
			if(data[i].priority < data[front].priority){
				front = i;
			}
		}

		return front;
	}

	// En caso de que no haya elementos
	cout << "Fila de prioridad vacia" << endl;
	return -1;
}

// Devuelve el tamano de la fila
int PQueue::getSize(){
	return size;
}

// Verifica si la fila esta vacia
bool PQueue::isEmpty(){
	return size == 0;
}

// Verifica si la fila esta llena
bool PQueue::isFull(){
	return size == maxSize;
}

// Muestra la fila en la consola
void PQueue::show(){
	for(int i = 0; i < size; i++){
		cout << "data["<< i <<"]: " << data[i].data << "\t priority: " << data[i].priority << endl;
	}

	cout << endl;
}


int main(int argc, char  *argv[]){	
    int i;
	int maxSize = 10;

	Stack *stack = new Stack(maxSize);

	stack->push(4);
	stack->push(5);
	stack->push(9);

	stack->show();

	int val = stack->pop();
	cout << "Sale " << val << endl;

	stack->show();

	cout << "------------------------------" << endl << endl;

	Queue *queue = new Queue(maxSize);

	queue->enqueue(4);
    queue->enqueue(5);
    queue->enqueue(6);

    queue->show();

	val = queue->dequeue();
	cout << "Sale " << val << endl;

	queue->show();

	cout << "------------------------------" << endl << endl;

	PQueue *pqueue = new PQueue(maxSize);

	pqueue->enqueue(4, 1);
	pqueue->enqueue(7, 1);
	pqueue->enqueue(6, 3);
	pqueue->enqueue(5, 2);

	pqueue->show();

	val = pqueue->dequeue();
	cout << "Sale " << val << endl;

	pqueue->show();

	return 0;
}