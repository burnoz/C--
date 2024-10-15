#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;



// Atributos para el nodo: punteros a izquierda y derecha 
// El puntero hacia arriba(padre) es opcional
class NodeTree {	
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
		void showTree();

		// Recorridos (agregar entre parentesis al padre, ej. 25(-1) 20(25))
		void preorder();
		void inorder();
		void postorder();
		
};

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
	// Que pasa en este punto??
    cout << "Valor " << value << " no encontrado" << endl;
	return NULL;
}

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

void BST::remove(int value){
	NodeTree *aux = search(value);

	if(aux != NULL){
		NodeTree *parent = aux->up;

		// El nodo a eliminar es una hoja
		if(aux->left == NULL && aux->right == NULL){
			if(aux->data < parent->data){
				parent->left = NULL;
			}

			else{
				parent->right = NULL;
			}

			delete aux;
		}

		// El nodo a eliminar tiene un hijo
		else if(aux->left == NULL || aux->right == NULL){
			if(aux->left != NULL){
				if(aux->data < parent->data){
					parent->left = aux->left;
				}

				else{
					parent->right = aux->left;
				}

				aux->left->up = parent;
			}

			else{
				if(aux->data < parent->data){
					parent->left = aux->right;
				}

				else{
					parent->right = aux->right;
				}

				aux->right->up = parent;
			}

			delete aux;
		}

		// El nodo a eliminar tiene dos hijos
		else{

		}
	}

	else{
		cout << "El nodo no existe" << endl;
	}
}

int main(int argc, char  *argv[]){		
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

    aux = bst->search(2);

	// bst->remove(34);

	// NodeTree *aux = bst->search(34);

	// bst->remove(32);
	// bst->remove(31);
	// bst->remove(34);


	//saux = bst->search(4);

	//cout << aux << endl;	
}