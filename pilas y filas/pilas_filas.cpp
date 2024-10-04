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
		bool isEmpty();
		bool isFull();

		void show();
};

// Agrega un nuevo elemento en el top
bool Stack::push (int valor){	
    // Primero revisa si hay espacio (si no esta llena)
	if(!this->isFull()){
		arreglo[top + 1] = valor;
		this->top++;
		this->size++;
		return true;
	}

	cout << "Stack llena" << endl;
	return false;
}

// Extrae el elemento del top
int Stack::pop(){	
	// Primero revisa que no este vacia
	if (size > 0){	
		int val = arreglo[top];
		top--;
		size--;
		return val;
	}

	else{	
		cout << "Esta vacia" << endl;
		return -1;
	}
}

// Devuelve el tamano del stack
int Stack::getSize(){
	return this->size;
}

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
		Queue(int maxSize){   
			this->maxSize = maxSize;
			this->data = (int *) malloc(this->maxSize * sizeof(int));
			this->front = -1;
			this->end = -1;
			this->size = 0;
		}

		~Queue(){	
			free(this->data);	
			//	delete[] this->data;
		}

	bool enqueue(int);
	int dequeue();
	int getFront();
	bool isEmpty( );  
	bool isFull( );
	void show();
};


bool Queue::enqueue(int value){	
	if(!this->isFull()){

		if(this->isEmpty()){
			this->front = 0;
			this->end = 0;
		}

		data[end % this->maxSize] = value;
		this->end++;
		this->size++;
		return true;
	}

	cout << "Fila llena" << endl;
	return true;

}


int Queue::dequeue(){
	if(!this->isEmpty()){
		int val = data[front % this->maxSize];
		size--;
		end--;
		return val;
	}

	cout << "Fila vacia" << endl;
    return -1;
}


int Queue::getFront(){	
    return 0;
}


bool Queue::isEmpty()
{	return this->size == 0;	}


bool Queue::isFull()
{	return this->size == maxSize;	}


void Queue::show(){
	int i;

	for(i = this->front; i < this->end; i++){
        cout << "data["<< i % this->maxSize <<"]: " << data[i % this->maxSize] << endl;	
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

	Queue *queue = new Queue(maxSize);

	queue->enqueue(4);
    queue->enqueue(5);
    queue->enqueue(6);

    queue->show();

	val = queue->dequeue();
	cout << "Sale " << val << endl;;

	queue->show();

	return 0;
}