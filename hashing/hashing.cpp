#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

//	Una clase para un elemento de la tabla
template<class T>
class Element{
	public:
		string str_key;		//	Llave string, como "Ana"
		int int_key;		//	Llave entera, resultante de la llave string
		int h_key;		//	Indice real asignado con base en int_key
		T item;		//	El objeto asociado con la llave

		bool free;		//	Una bandera para saber si este elemento de la tabla esta libre o no

		//	Constructor
		Element<T>(){	
            str_key = "";
            int_key = -1;
            h_key = -1;
            item = -1;
            free = true;
		}
};

//	Una clase que sera la tabla hash
template<class T>
class Hash{	
    public:
		int maxSize;	//	tamaño maximo
        int currentSize;    //	tamaño actual	
        int i;    // contador de colisiones
		Element<T> **table;	//	puntero a arreglo de los elementos
		
		
		Hash(int size){
            int j;
			maxSize = size;
            currentSize = 0;
            i = 0;
            table = new Element<T>*[maxSize];

            for(j = 0; j < maxSize; j++){
                table[j] = new Element<T>();
            }
		}

		void show();				//	ver toda la tabla
		void insert(string, T);		//	agregar un elemento nuevo, recibe key y value
		void remove(string);		//	remover uno por su key
        void update(string, T);     //  cambia el valor de una llave
		int find(string);			//	encontrar el indice de una key
};


template<class T> 
void Hash<T>::show(){	
    int j;

	//	Muestra toda la tabla, su indice, char_key, int_key, int_key real y valor almacenado
	for (j =0; j < maxSize; j++){	
        cout << j << " " << table[j]->str_key << " " << table[j]->int_key << " " << table[j]->h_key << " " << table[j]->item << endl; 	
    }
	
    cout << endl << endl;
}

// Inserta un elemento en la tabla
// Complejidad: O(1)
template<class T> 
void Hash<T>::insert(string str_key, T value){  // Recibe algo como insert( "Annie", 23)
    int key = 0;
    int h_key;
    int flag;
    int k;
    
    if(currentSize < maxSize){
        // Calcula el valor numerico de la llave
        for(k = 0; k < size(str_key); k++){
            key += int(str_key[k]);
        }
        
        i = 0; // Contador de colisiones
        flag = 0;

        while(flag == 0){
            // Linear probing
            h_key = (key + i) % maxSize;

            // Verifica si el espacio esta libre (no hay colisiones)
            if(table[h_key]->free == true){
                // Indica que el espacio ya no esta libre
                table[h_key]->free = false;

                // Guarda el elemento en el espacio
                table[h_key]->str_key = str_key;
                table[h_key]->int_key = key;
                table[h_key]->h_key = h_key;
                table[h_key]->item = value;

                // Aumenta el numero de elementos
                currentSize++;

                // Sale del ciclo
                flag = 1;
            }

            // El espacio esta ocupado (hay una colision)
            else{
                // Suma una colision
                i++;
            }
        }
    }

    else{
        cout << "Tabla llena" << endl;
    }
}

// Elimina un elemento de la tabla
// Complejidad: O(1 + a) por el uso de find
template<class T> 
void Hash<T>::remove(string str_key){  // Recibe una key como "Annie"
    int index = find(str_key);

    if(index != -1){
        // Indica que el espacio ahora esta libre
        table[index]->free = true;

        // Elimina el elemento (regresa a los valores por defecto)
        table[index]->str_key = "";
        table[index]->int_key = -1;
        table[index]->h_key = -1;
        table[index]->item = -1;

        // Disminuye el numero de elementos
        currentSize--;
    }

    else{
        cout << "La llave no existe en la tabla" << endl;
    }
}

// Inserta un elemento en la tabla
// Complejidad: O(1 + a) por el uso de find
template<class T> 
void Hash<T>::update(string str_key, T newValue){  // Recibe algo como update("Annie", 23)
    int index = find(str_key);
    int key = 0;
    int k;

    if(index != -1){
        // Actualiza el valor de la llave
        table[index]->item = newValue;

        // Disminuye el numero de elementos
        currentSize--;
    }

    else{
        cout << "La llave no existe en la tabla" << endl;
    }
}

// Encuentra un elemento en la tabla
// Complejidad: O(1 + a)
template<class T>
int Hash<T>::find(string str_key){  // Recibe una key como "Annie"
    int key = 0;
    int h_key;
    int flag;

    i = 0; // Contador de colisiones
    flag = 0;

    while(flag == 0){
        // Linear probing
        h_key = (key + i) % maxSize;

        // Verifica si la llave es la del elemento actual
        if(table[h_key]->str_key == str_key){
            return h_key;
        }

        // La llave no es la del elemento actual
        else{
            // Suma una colision
            i++;
        }
    }

    // No se encontro la llave
    return -1;
}


int main(){	
	Hash<int> htable(10);

    cout << "Prueba insert" << endl << endl;

	htable.insert("Annie", 30);
	htable.insert("Armando", 45);
	htable.insert("Alex", 60);
	htable.insert("Axel", 28);
	htable.insert("Andrea", 32);
	htable.insert("Bill", 32);	
	htable.insert("Veronica", 32);
	htable.insert("Karla", 32);
	htable.insert("Laura", 32);
	htable.insert("Luis", 32);

	htable.show();

    cout << "Prueba remove" << endl << endl;

    htable.remove("Annie");
    htable.remove("Bill");
    htable.remove("Luis");

    htable.show();

    cout << "Prueba update" << endl << endl;

    htable.update("Alex", 100);
    htable.update("Karla", 40);
    htable.update("Laura", 35);

    htable.show();

    cout << "Prueba find" << endl << endl;

    int index = htable.find("Karla");
    cout << "Karla esta en el indice " << index << endl;
}