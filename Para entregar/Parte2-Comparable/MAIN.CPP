/*
 * main.cpp
 *
 *  Created on: Mar 23, 2011
 *      Author: p4gr22
 */


#include "String.h"
#include "Entero.h"

void ImprimirMenuPrincipal(){
	cout << "Ingrese la opcion deseada\n\n";
	cout << "1. Ordenacion strings.\n";
	cout << "2. Ordenacion enteros.\n";
	cout << "0. Salir.\n\n";
}

int ImprimirConsultaCantidadStrings(String aux){
	int res;
	do {
		cout << "\nIngrese la cantidad de strings a comparar:";
		cin >> res;
		getline(cin,aux);
	}
	while (res <= 0);
	return res;
}

int ImprimirConsultaCantidadEnteros(String aux){
	int res;
	do {
		cout << "\nIngrese la cantidad de enteros a comparar:";
		cin >> res;
		getline(cin,aux);
	}
	while (res <= 0);
	return res;
}

void ImprimirStrings(Comparable** c, int cantidad){
	cout << "\nArreglo ordenado de Strings:\n";
	for (int j=0;j<cantidad;j++){
		cout << j+1 << ": " << c[j]->getCadena() << endl;
	}
	cout << endl;
}

void ImprimirEnteros(Comparable** c, int cantidad){
	cout << "\nArreglo ordenado de Enteros:\n";
	for (int j=0;j<cantidad;j++){
		cout << j+1 << ": " << c[j]->getValor() << endl;
	}
	cout << endl;
}

void DestruirComparable(Comparable** c, int cant){
	for (int i=0; i < cant; i++)
		delete c[i];
	delete [] c;
}


int main() {
	cout << "<Menu de prueba de Comparable>\n\n";
	Comparable**  c1;
	String opcionmenu;
	String aux;
	int cantidad;
	do {
		ImprimirMenuPrincipal();
		cin >> opcionmenu;
		if (opcionmenu == "1")
		{
			cantidad = ImprimirConsultaCantidadStrings(aux);
			c1 = new Comparable*[cantidad];

			for (int i = 0;i<cantidad;i++){
				cout << i+1 << ":";
				String s;
				getline(cin,s);
				c1[i] = new String(s);
			}

			Comparable::ordenar(c1,cantidad);
			ImprimirStrings(c1,cantidad);
			DestruirComparable(c1,cantidad);
		}
		else if (opcionmenu == "2"){
			cantidad = ImprimirConsultaCantidadEnteros(aux);
			c1 = new Comparable*[cantidad];
			for (int i = 0;i<cantidad;i++){
				cout << i+1 << ":";
				int ent;
				cin >> ent;
				c1[i] = new Entero(ent);
			}

			Comparable::ordenar(c1,cantidad);
			ImprimirEnteros(c1,cantidad);
			DestruirComparable(c1,cantidad);
		}
		else if (opcionmenu != "0")
			cout << "\nEntrada no valida\n";

	} while (opcionmenu != "0");

	cout << "\nFIN!!\n";
	return EXIT_SUCCESS;
}
