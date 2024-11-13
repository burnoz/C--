#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class Stack{
	private:
		int *data;
		int top;
		int maxSize;

	public:
		Stack(int maxSize){	
			this->maxSize = maxSize;
			this->data = (int *) malloc( this->maxSize * sizeof(int));
			this->top = -1;
		}

		~Stack(){	
			//free(this->data);	
			delete[] this->data;
		}

		void push(int Valor);
		int getTop();
		int pop();
		bool isEmpty();  
		bool isFull();
};

//	solo consulta el dato en top
int Stack::getTop(){	
	int value = this->data[top];
	return value;
}

//	extrae el dato en top
int Stack::pop(){	
	int value = this->data[top];
	this->top--;
	return value;
}

// 	agrega elemento
void Stack::push(int value){	
	this->top++;
	this->data[this->top] = value;
}

//	revisa si la pila esta llena
bool Stack::isFull(){	
	return this->top == (this->maxSize - 1);	
}

//	 revisa si la pila esta vacia
bool Stack::isEmpty(){	
	return this->top == -1;	
}


class Queue{
	private:
		int *data;
		int front;
		int end;
		int maxSize;

	public:
		Queue(int maxSize){   
			this->maxSize = maxSize;
			this->data = (int *) malloc( this->maxSize * sizeof(int));
			this->front = -1;
			this->end = -1;
		}

		~Queue(){	
			free(this->data);	
			//	delete[] this->data;
		}

	void enqueue(int Valor);
	int dequeue();
	int getFront();
	bool isEmpty();  
	bool isFull();

};

//	muestra el valor al frente
int Queue::getFront(){	
	return this->data[this->front];  
}

//	extrae elemento del frente
int Queue::dequeue(){	
	int value = this->data[this->front];
	
	if (this->front == this->end){	
		this->front = -1;
		this->end = -1 ;	
	}
	
	else{	
		this->front = (this->front + 1) % this->maxSize;	
	}

	return value;
}

//	agrega elemento
void Queue::enqueue(int value){	
	this->end = (this->end + 1) % this->maxSize;
	this->data[end] = value;

	if (this->front == -1 ){	
		this->front++;
	}
}

//	si esta llena
bool Queue::isFull(){	
	return (end+1) % this->maxSize == front;	
}

//	si esta vacia
bool Queue::isEmpty(){	
	return front == -1;	 
}


void grados(int N, int** matrix) {
    cout << "Grados de los nodos:" << endl;

    for(int i = 0; i < N; i++) {
        int degree = 0;
        
		for(int j = 0; j < N; j++) {
            if(matrix[i][j] == 1) {
                degree++;
            }
        }
        
		cout << "Grado de " << i << ": " << degree << endl;
    }

    cout << endl;
}

//	Usa una stack para procesar los nodos
void recDFS(int N, int **matrix){	
	Stack *stack = new Stack(N);

	int i;
	int origen = 0;

	int *visitados = (int *) calloc(N, sizeof(int));
	int *predecesores = (int *) calloc(N, sizeof(int));

	// for(i = 0; i < N, i++){
	// 	cout << visitados[i] << " ";
	// }

	// cout << endl;

	stack->push(origen); // El nodo origen entra a la stack
	visitados[origen] = 1; // se marca como visitado
	predecesores[origen] = -1; // no tiene predecesor

	int u;

	while(!stack->isEmpty()){
		u = stack->pop(); // sale el nodo de la stack
		cout << "Sale nodo: " << u << endl;

		for(i = 0; i < N; i++){
			// Se buscan los vecinos
			if(matrix[u][i] == 1){
				// cout << "Vecinos-> u: " << u << " i: " << i << endl;

				if(visitados[i] == 0){
					stack->push(i);
					visitados[i] = 1;
					predecesores[i] = u;
				}
			}
		}
	}

	cout << endl;

	// for(i = 0; i < N; i++){
	// 	cout << predecesores[i] << "\t";
	// }

	// cout << endl;

	// for(i = 0; i < N; i++){
	// 	cout << i << "\t";
	// }

	// cout << endl;
}

//	Recorre el grafo y busca las componentes conexas
void conexas(int N, int** matrix){
    int* visitados = (int *) calloc(N, sizeof(int));
    int numComponents = 0;

    for(int i = 0; i < N; i++){
        if(visitados[i] == 0){
            cout << "Componente conexa " << numComponents + 1 << ":" << endl;
            
            recDFS(N, matrix);

            for(int j = 0; j < N; j++) {
                if(visitados[j] == 0){
                    visitados[j] = 1;
                }
            }
            
            numComponents++;
        }
    }

    cout << "Numero de componentes: " << numComponents << endl;
	cout << endl;
}

//	Usa una queue para procesar los nodos
void recBFS(int N, int** matrix) {
	Queue *queue = new Queue(N);

	int *visitados = (int *) calloc(N, sizeof(int));
	int *distancias = (int *) calloc(N, sizeof(int));
	int *predecesores = (int *) calloc(N, sizeof(int));

	int origen = 0;

	queue->enqueue(origen); // El nodo origen entra a la queue
	visitados[origen] = 1; // se marca como visitado
	distancias[origen] = 0; // distancia desde el origen
	predecesores[origen] = -1; // no tiene predecesor

	int u;

	while(!queue->isEmpty()){
		u = queue->dequeue(); // sale el nodo de la queue
		cout << "Sale nodo: " << u << endl;

		for(int i = 0; i < N; i++){
			// Se buscan los vecinos
			if(matrix[u][i] == 1 && visitados[i] == 0){
				queue->enqueue(i);
				visitados[i] = 1;
				distancias[i] = distancias[u] + 1;
				predecesores[i] = u;
			}
		}
	}

	cout << endl;

	cout << "Distancias desde el nodo " << origen << ":" << endl;
	
	for(int i = 0; i < N; i++){
		cout << "Nodo " << i << ": " << distancias[i] << "\t";

		// Imprime el recorrido
		cout << " Recorrido: ";
		int j = i;

		// Derecha a izquierda
		while(j != -1){
			cout << j << " ";
			j = predecesores[j];
		}

		cout << endl;
	}
}


int main(int argc, char* argv[]){    
	string sline, line, aux;
	int index;
	int a, b, current = -1;

	int **matrix;

	int *start, *end; 

	ifstream inFile("grafo.txt");         //  input file stream
	//ofstream outFile("salida2.txt");        //    output file stream    
	
	//    Verifica que los archivos se hayan abierto correctamente
	int i = 0;
	int j;
	int N;
	int E;

	if (inFile.is_open()){    
		//    Lee liniea a linea
		while(getline(inFile, sline)){    
			if(i == 1){   
				//cout << sline << endl;
				line = sline;
				index = line.find(" "); 
				aux = line.substr(0, index);
				N = stoi(aux);//lee cuantos nodos son

				line = line.substr(index+1);
				index = line.find(" ");

				line = line.substr(index+1);
				index = line.find(" ");
				aux = line.substr(0, index);
				E = stoi(aux);

				// cout << "N: "<< N << endl;
				// cout << "E: "<< E << endl;

				matrix = (int **) malloc ( N * sizeof(int*) );

				for (j = 0; j < N; j++){     
					matrix[j] = (int *) malloc(N * sizeof(int));    
				}

				for (int x = 0; x < N; x++) {
					for (int y = 0; y < N; y++) {
						matrix[x][y] = 0;
					}
				}
			}

			else if(i > 1){    
				//cout << sline << endl;

				line = sline;
				index = line.find(" "); 
				aux = line.substr(0, index);
				a = stoi(aux);

				line = line.substr(index+1);
				index = line.find(" "); 
				aux = line.substr(0, index);
				b = stoi(aux);

				// cout << "a y b: "<< a << " " << b << endl;

				//    asignar valores a la matriz
				//    indicando que a es adyacente a b, y viceversa
				matrix[a][b] = 1;
				matrix[b][a] = 1;
			}
			
			i++;
		}
	} 

	inFile.close();
	//outFile.close();

	cout << "Matriz del grafo:" << endl;

	for(i = 0; i < N; i++){	
		for(j = 0; j < N; j++){	
			cout << "["<< i <<","<< j <<"] " << matrix[i][j] << "\t\t"; 
		}
		
		cout << endl;
	}

	cout << endl;

	for(i = 0; i < N; i++){	
		for(j = 0; j < i; j++){	
			cout << "["<< i <<","<< j <<"] " << matrix[i][j] << "\t\t"; 
		}
		
		cout << endl;
	}
	
	cout << endl;

	grados(N, matrix);

	cout << "Recorrido DFS:" << endl;
	conexas(N, matrix);

	cout << "Recorrido BFS:" << endl;
	recBFS(N, matrix);
}
