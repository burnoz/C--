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


class SplayTree{

};