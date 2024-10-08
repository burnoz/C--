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