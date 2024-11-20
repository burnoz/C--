#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

void topologicalOrder(){
	
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
}