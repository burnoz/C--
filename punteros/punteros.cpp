//rm ./ejemploPunteros.exe; g++ ejemploPunteros.cpp -o ejemploPunteros; ./ejemploPunteros.exe
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <string.h>
using namespace std;


class ClaseDemo
{	int valor;

	public: 
		void setValor(int v) 
		{	valor = v;	}

		void show()
		{	cout<< " Valor es: " << valor << endl; };
};


void funcion_uno (int variable_estatica)
{	variable_estatica += 27;

	cout << "\nfuncion uno:\n" << endl;
	cout << "\tvalor de variable_estatica dentro de funcion_uno: " << variable_estatica << endl;
	cout << "\tdireccion de variable_estatica dentro de funcion_uno: " << &variable_estatica << endl;
	cout << endl;

	return;
}


void funcion_dos (int *variable_puntero)
{	variable_puntero[0] += 40;

	cout << "\nfuncion dos:\n" << endl;
	cout << "\tvalor de variable_puntero[0] dentro de funcion_uno: " << variable_puntero[0] << endl;
	cout << "\tvalor de variable_puntero dentro de funcion_uno: " << variable_puntero << endl;
	cout << "\tdireccion de variable_puntero dentro de funcion_uno: " << &variable_puntero << endl;
	cout << endl;

	return;
}


void intercambio_1(int a, int b)
{	int aux; 

	aux = a;
	a = b;
	b = aux;

	return;
}
//intercambio(a, b);

void intercambio_2(int *a, int *b)
{	int aux; 

	aux = *a;
	*a = *b;
	*b = aux;

	return;
}
//intercambio(&a, &b);

void intercambio_3(int &a, int &b)
{	int aux; 

	aux = a;
	a = b;
	b = aux;

	cout << "intercambio_3 " << a << " "<<b<< " " << aux << endl;

	return;
}
//intercambio(a, b);

int main ()
{	int variable = 0; 
	int *puntero; 

	funcion_uno(variable);
	
	cout << "Main"<<endl;
	cout << "\tvalor de variable en main, despues de funcion_uno: "<< variable <<endl;
	cout << "\tdireccion de variable: " << &variable << endl;
	cout << endl;

	puntero = &variable;
	funcion_dos(puntero);

	cout << "Main"<<endl;
	cout << "\tvalor de variable en main, despues de funcion_dos: "<< variable <<endl;
	cout << "\tdireccion de variable: " << &variable << endl;
	cout << "\tvalor de puntero: " << puntero << endl;
	cout << "\tvalor de puntero: " << *puntero << endl;
	cout << "\tdireccion de puntero: " << &puntero << endl;
	cout << endl;



	int a = 5, *p;
	p = new int;
	*p = a;
	a = *p + 2;
	cout << a << " " << *p << endl;
	delete p;

	int b= 5;
	cout << "intercambio "<< a << " " << b << endl;
	intercambio_2(&a, &b);
	cout << "intercambio "<< a << " " << b << endl;


	//	Arreglos dinamicos con new/delete C++
	cout << "\nArreglos dinamicos C++" << endl;
	int tamano = 24;

	//int *arreglo = new int[tamano];
	int *arreglo;
	arreglo = new int[tamano];

	arreglo[3] = 12;
	cout << arreglo[3] << endl;

	delete[] arreglo;


	// Arreglos dinamicos en C con malloc/calloc y free 
	cout << "\nArreglos dinamicos C" << endl;
	int *arreglo2 = (int *) malloc(tamano * sizeof(int));
	int *arreglo3 = (int *) calloc(tamano , sizeof(int));

	cout << arreglo2[0] << " " << arreglo3[0] << endl;

	// realloc cambia el tamaño de un arreglo existente
	arreglo2 = (int *) realloc( arreglo2, (tamano + 7) * sizeof(int));

	free(arreglo2);				//	C
	delete[] arreglo3;			//	C++



	// Arreglos estaticos
	cout << "\nArreglos estaticos" << endl;
	int arreglo_estatico[24]; 
	arreglo_estatico[3] = 17;

	cout << arreglo[3] << endl;


	//	Punteros a objetos
	cout << "\nPunteros a objetos" << endl;

	// V1 crea objeto y lugo obtiene puntero
	ClaseDemo objeto, *p_objeto;
	objeto.setValor(15);
	objeto.show();

	p_objeto = &objeto;
	p_objeto->setValor(20);
	p_objeto->show();

	//	V2 Crea objeto como puntero desde el inicio
	ClaseDemo *puntero_directo = (ClaseDemo *) new ClaseDemo();
	puntero_directo->setValor(30);
	puntero_directo->show();


	//	Arreglo dinamico de objetos
	cout << "\nArreglos dinamicos de objetos" << endl;

	// C
	ClaseDemo *p_arreglo_obj = (ClaseDemo *) malloc(tamano * sizeof( ClaseDemo ));

	for( int i=0; i < tamano; i++)
	{	p_arreglo_obj[i].setValor(i);
		(&p_arreglo_obj[i])->show(); // p_arreglo_obj[i].show();  // <-- seria lo mismo
	}
	free(p_arreglo_obj);

	// C++
	ClaseDemo *p_arreglo_obj2 = new ClaseDemo[tamano];
	p_arreglo_obj2[0].setValor(11);
	p_arreglo_obj2[0].show();
	delete[] p_arreglo_obj2;

	int *aux1, *aux2;
	aux1 = &a; 
	aux2 = &a;

	cout << a << " "<<aux1 <<" "<< aux2 << " " << endl;
	//delete aux1;
	//cout << a << " "<< aux2 << " " << endl;
}
