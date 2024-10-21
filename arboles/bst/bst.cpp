#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

// Clase para nodo de la lista
template <class T>
class Node{
	public:
		T data;
		Node<T> *next;

		Node(T value){
			data = value;
			next = NULL;
		}
};


// Clase para lista enlazada
template <class T>
class List{
	public:
		Node<T> *first;
		Node<T> *last;
		int size;

		List(){
			first = NULL;
			last = NULL;
			size = 0;
		}

		void insertFirst(T);
		void deleteFirst();
};

template <class T>
void List<T>::insertFirst(T value){
	Node<T> *newNode = new Node<T>(value);

	if(first == NULL){
		first = newNode;
		last = newNode;
	}

	else{
		newNode->next = first;
		first = newNode;
	}

	size++;
}

template <class T>
void List<T>::deleteFirst(){
	if(first != NULL){
		Node<T> *aux = first;
		first = first->next;
		delete aux;
		size--;
	}
}

// Clase Stack
template <class T>
class StackList{
	public:
		List<T> *lista;
		Node<T> *top;

		int maxSize;
		int size;

		StackList(int max){
			lista = new List<T>();
			top = lista->first;
			maxSize = max;
			size = 0;
		}

		void push(T);
		T pop();
		bool isEmpty();
		bool isFull();
};


template <class T>
void StackList<T>::push(T value){
	if(!isFull()){
		lista->insertFirst(value);
		top = lista->first;
		size++;
	}

	else{
		cout << "Stack llena" << endl;
	}
}


template <class T>
T StackList<T>::pop(){
	if(!isEmpty()){
		T value = top->data;
		
		lista->deleteFirst();
		top = lista->first;
		size--;

		return value;
	}

	else{
		cout << "Stack vacia" << endl;
		return NULL;
	}
}


template <class T>
bool StackList<T>::isEmpty(){
	return size == 0;
}


template <class T>
bool StackList<T>::isFull(){
	return size == maxSize;
}

// Clase para fila
template <class T>
class QueueList{
	public:
		List<T> *lista;
		Node<T> *front;
		Node<T> *end;

		int maxSize;
		int size;

		QueueList(int max){
			lista = new List<T>();
			front = lista->first;
			end = lista->last;
			maxSize = max;
			size = 0;
		}

		void enqueue(T);
		T dequeue();
		bool isEmpty();
		bool isFull();
};


template <class T>
void QueueList<T>::enqueue(T value){
	if(!isFull()){
		Node<T> *newNode = new Node<T>(value);

		if(front == NULL){
			front = newNode;
			end = newNode;
		}

		else{
			end->next = newNode;
			end = newNode;
		}

		size++;
	}

	else{
		cout << "Queue llena" << endl;
	}
}


template <class T>
T QueueList<T>::dequeue(){
	if(!isEmpty()){
		T value = front->data;
		Node<T> *aux = front;

		front = front->next;
		delete aux;
		size--;

		return value;
	}

	else{
		cout << "Queue vacia" << endl;
		return NULL;
	}
}


template <class T>
bool QueueList<T>::isEmpty(){
	return size == 0;
}


template <class T>
bool QueueList<T>::isFull(){
	return size == maxSize;
}

// Atributos para el nodo: punteros a izquierda y derecha 
// El puntero hacia arriba (padre) es opcional
class NodeTree{	
    public: 
		int data;
		NodeTree *left, *right, *up;
	
		NodeTree(int value){	
            data = value;
			left = NULL;
			right = NULL;
			up = NULL;
		}
};


class BST{	
    public:
		NodeTree *root;   // el arbol tiene un nodo raiz
	
		// Al crear el arbol, creamos su nodo raiz
		BST(int value){	
            root = new NodeTree(value);  
		}

		NodeTree* search(int);
		void insert(int);
		void remove(int);

		// Recorridos (agregar entre parentesis al padre, ej. 25(-1) 20(25))
		void preorder(NodeTree*);
		void inorder(NodeTree*);
		void postorder(NodeTree*);
		void dfs(NodeTree*); 
		void levelorder(NodeTree*); // BFS
};

// Busqueda de un valor en el arbol
// Complejidad: O(log n) si el arbol esta balanceado, O(n) en el peor de los casos
NodeTree* BST::search(int value){	
    // Asigna un nodo que nos sirva para recorrer el arbol 
	// aux inicia como  la raiz 
	NodeTree *aux = this->root; 

	// mientras que aux no sea null... 
	while(aux != NULL){	
        // el valor buscado es menor que el del nodo actual??  
		// desplazate al nodo de su izquierda
		if(value < aux->data){
            aux = aux->left;
		}
		// el valor buscado es mayor que el del nodo actual??  
		// desplazate al nodo de su derecha
		else if(value > aux->data){	
            aux = aux->right;
		}
		// si no es mayor, ni menor, debe ser igual... 
		else{
            cout << "Valor " << value << " encontrado" << endl;
            return aux;
		}
	} 

	// Caso en que el valor no se encuentra en el arbol
    cout << "Valor " << value << " no encontrado" << endl;
	return NULL;
}

// Insercion de un valor en el arbol
// Complejidad: O(log n) si el arbol esta balanceado, O(n) en el peor de los casos
void BST::insert(int value){	
    // Comienza por verificar que el valor que se quiere agregar no exista en el arbol... 
	if(this->search(value) == NULL){  
        // Crea el nodo nuevo
		NodeTree *newNode = new NodeTree(value);

		// Inicia un proceso similar al de la busqueda... 
		// Necesitas encontrar a un nodo que pueda ser el padre del nuevo
		// Inicia desde la raiz... 
		NodeTree *aux = this->root;

		// mientras aux no sea null... 
		// agrega un return cuando consigas agregar el nodo nuevo... 
		while(aux != NULL){ 	
            // revisa a que lado de aux deberia quedar el nodo nuevo
			// Va a la izquierda si es menor que el valor en aux
			// y a la derecha si no
			if (value < aux->data){	
                // Revisa si el nodo nuevo puede ser el hijo izquierdo de aux
                if(aux->left == NULL){
                    aux->left = newNode;
                    newNode->up = aux;
                    break;
                }  

				// si no, continua buscando un lugar a la izauierda de aux
                else{
                    aux = aux->left;
                }
			}

			else{	
                // Mismo proceso, pero para la derecha
                if(aux->right == NULL){
                    aux->right = newNode;
                    newNode->up = aux;
                    break;
                }

                else{
                    aux = aux->right;
                }
			}
		}
	}
	
    else{
        cout << "El nodo ya existe" << endl;
	}
}

// Elimina un nodo del arbol
// Complejidad: O(log n) si el arbol esta balanceado, O(n) en el peor de los casos
void BST::remove(int value){
	NodeTree *aux = search(value);

	if(aux != NULL){
		NodeTree *parent = aux->up;

		// El nodo a eliminar es una hoja
		if(aux->left == NULL && aux->right == NULL){
			// Verifica si la hoja es izquierda o derecha
			if(aux->data < parent->data){
				// Si es izquierda, elimina el puntero izquierdo en el padre
				parent->left = NULL;
			}

			else{
				// Si es derecha, elimina el puntero derecho en el padre
				parent->right = NULL;
			}

			// Elimina el nodo
			delete aux;
		}

		// El nodo a eliminar tiene un hijo
		else if(aux->left == NULL || aux->right == NULL){
			// Verifica si el nodo a eliminar tiene un hijo izquierdo o derecho
			if(aux->left != NULL){
				// Verifica si el nodo a eliminar es izquierdo o derecho
				if(aux->data < parent->data){
					// Si es izquierdo, el hijo izquierdo del padre apunta al hijo izquierdo del nodo a eliminar
					parent->left = aux->left;
				}

				else{
					// Si es derecho, el hijo derecho del padre apunta al hijo izquierdo del nodo a eliminar
					parent->right = aux->left;
				}

				// Enlaza al hijo con el nuevo padre
				aux->left->up = parent;
			}

			else{
				// Verifica si el nodo a eliminar es izquierdo o derecho
				if(aux->data < parent->data){
					// Si es izquierdo, el hijo izquierdo del padre apunta al hijo derecho del nodo a eliminar
					parent->left = aux->right;
				}

				else{
					// Si es derecho, el hijo derecho del padre apunta al hijo derecho del nodo a eliminar
					parent->right = aux->right;
				}

				// Enlaza al hijo con el nuevo padre
				aux->right->up = parent;
			}
			
			// Elimina el nodo
			delete aux;
		}

		// El nodo a eliminar tiene dos hijos
		else{
			// Busca el sucesor del nodo a eliminar (menor del subarbol derecho)
			NodeTree* succesor = aux->right;

			// Avanza hacia la izquierda hasta que no haya mas nodos
			while (succesor->left != NULL){
				succesor = succesor->left;
			}

			aux->data = succesor->data;

			if (succesor->right != NULL){
				if(succesor->up->left == succesor){
					succesor->up->left = succesor->right;
				}

				else{
					succesor->up->right = succesor->right;
				}

				succesor->right->up = succesor->up;
			}

			else{
				if (succesor->up->left == succesor){
					succesor->up->left = NULL;
				}

				else{
					succesor->up->right = NULL;
				}
			}

			delete succesor;
		}
	}

	else{
		cout << "El nodo no existe" << endl;
	}
}

// N-L-R
// Complejidad: O(n)
void BST::preorder(NodeTree *auxroot){
	if(auxroot == NULL){
		return;
	}

	cout << auxroot->data << "(";

	if(auxroot->up != NULL){
		cout << auxroot->up->data << ")\t";
	}

	else{
		cout << -1 << ")\t";
	}

	preorder(auxroot->left);
	preorder(auxroot->right);
}

// L-N-R
// Complejidad: O(n)
void BST::inorder(NodeTree *auxroot){
	if(auxroot == NULL){
		return;
	}

	inorder(auxroot->left);

	cout << auxroot->data << "(";

	if(auxroot->up != NULL){
		cout << auxroot->up->data << ")\t";
	}

	else{
		cout << -1 << ")\t";
	}

	inorder(auxroot->right);
}

// L-R-N
// Complejidad: O(n)
void BST::postorder(NodeTree *auxroot){
	if(auxroot == NULL){
		return;
	}

	postorder(auxroot->left);
	postorder(auxroot->right);

	cout << auxroot->data << "(";

	if(auxroot->up != NULL){
		cout << auxroot->up->data << ")\t";
	}

	else{
		cout << -1 << ")\t";
	}
}

// DFS
// Complejidad: O(n)
void BST::dfs(NodeTree *auxroot){
	StackList<NodeTree*> *stack = new StackList<NodeTree*>(-1);
	NodeTree *aux;

	stack->push(auxroot);

	while(!stack->isEmpty()){
		aux = stack->pop();

		cout << aux->data << "(";

		if(aux->up != NULL){
			cout << aux->up->data << ")\t";
		}

		else{
			cout << -1 << ")\t";
		}

		if(aux->left != NULL){
			stack->push(aux->left);
		}

		if(aux->right != NULL){
			stack->push(aux->right);
		}
	}
}

// levelorder
// Complejidad: O(n)
void BST::levelorder(NodeTree *auxroot){
	QueueList<NodeTree*> *queue = new QueueList<NodeTree*>(-1);
	NodeTree *aux;

	queue->enqueue(auxroot);

	while(!queue->isEmpty()){
		aux = queue->dequeue();

		cout << aux->data << "(";

		if(aux->up != NULL){
			cout << aux->up->data << ")\t";
		}

		else{
			cout << -1 << ")\t";
		}

		if(aux->left != NULL){
			queue->enqueue(aux->left);
		}

		if(aux->right != NULL){
			queue->enqueue(aux->right);
		}
	}
}

int main(int argc, char  *argv[]){		
	cout << "Paso 1" << endl;
    BST *bst = new BST(25);

	NodeTree *aux = bst->search(25);
	aux = bst->search(30);
	
	bst->insert(20);
	bst->insert(34);
	bst->insert(2);
	bst->insert(22);
	bst->insert(30);
	bst->insert(40);
	bst->insert(26);
	bst->insert(31);
	bst->insert(32);
	bst->insert(45);
	bst->insert(39);
	cout << endl;

	bst->preorder(bst->root);
	cout << endl << endl;

	cout << "Paso 2" << endl;
	bst->remove(34);
	bst->preorder(bst->root);
	cout << endl;
	aux = bst->search(34);
	cout << endl;

	bst->remove(32);
	bst->preorder(bst->root);
	cout << endl << endl;

	bst->remove(39);
	bst->preorder(bst->root);
	cout << endl << endl;

	bst->remove(40);
	bst->preorder(bst->root);
	cout << endl << endl;

	cout << "Paso 3" << endl;
	bst->insert(33);
	bst->insert(48);
	bst->insert(35);
	cout << endl;

	bst->preorder(bst->root);
	cout << endl << endl;

	cout << "Paso 4" << endl;
	cout << "Preorder:" << endl;
	bst->preorder(bst->root);
	cout << endl << endl;

	cout << "Inorder:" << endl;
	bst->inorder(bst->root);
	cout << endl << endl;

	cout << "Postorder:" << endl;
	bst->postorder(bst->root);
	cout << endl << endl;

	cout << "DFS:" << endl;
	bst->dfs(bst->root);
	cout << endl << endl;

	cout << "Levelorder:" << endl;
	bst->levelorder(bst->root);
}