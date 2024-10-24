#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

// Atributos para el nodo: punteros a izquierda y derecha 
// El puntero hacia arriba (padre) es opcional
class NodeTree{	
    public: 
		int data;
        int hL, hR, factorbalance, level;
		NodeTree *left, *right, *up;

	
		NodeTree(int value){	
            data = value;
            hL = 0;
            hR = 0;
			left = NULL;
			right = NULL;
			up = NULL;
		}
};


class AVL{
    NodeTree *root;

    AVL(int value){
        root = new NodeTree(value);
    }

    NodeTree* search(int);
    void insert(int);
    void remove(int);
    NodeTree* update(NodeTree*, NodeTree*);

    // Funciones de rotacion
    void leftRotation(NodeTree*);
    void rightRotation(NodeTree*);
};


void AVL::leftRotation(NodeTree *node){
    
}


NodeTree* AVL::update(NodeTree *parent, NodeTree *child){
    if(parent == NULL){
        return NULL;
    }

    if(parent->left == child){
        parent->hL = max(child->hL, child->hR);
    }

    else{
        parent->hR = max(child->hL, child->hR);
    }

    parent->factorbalance = parent->hR - parent->hL;

    if(parent->factorbalance < -1 || parent->factorbalance > 1){
        cout << "Desbalanceo " << parent->data << endl;
        return parent;
    }

    update(parent->up, parent);
}


void AVL::insert(int value){
    NodeTree *aux = this->root;
    NodeTree *leaf = new NodeTree(value);

    leaf->level = aux->level + 1;
    leaf->hL = leaf->level;
    leaf->hR = leaf->level;
    leaf->factorbalance = leaf->hR - leaf->hL;
    
    NodeTree *Z = update(aux, leaf);

    if(Z != NULL){
        // Z < -1
        if(Z->factorbalance < -1){
    
        }

        // Z < 1
        else{
            
        }
    }
}