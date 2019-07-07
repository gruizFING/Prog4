/*
 * File:   main.cpp
 * Author: p4gr22
 *
 * Created on March 18, 2011, 1:38 PM
 */

#include "String.h"

void ImprimirMenuPrincipal() {
    cout << "\nIngrese la opcion deseada.\n\n";
    cout << "1. Concatenacion de strings.\n";
    cout << "2. Acceso a un caracter de un string (operador []).\n";
    cout << "3. Largo de un string.\n";
    cout << "4. Substring.\n";
    cout << "5. Comparacion de strings (submenu).\n";
    cout << "6. Escribir en Archivo.\n";
    cout << "7. Leer de Archivo (palabra por palabra)\n";
    cout << "8. Leer de Archivo (lineas enteras)\n";
    cout << "0. Salir.\n\n";
}

void ImprimirMenuComparacion() {
    cout << "\nSeleccione el tipo de comparacion.\n";
    cout << "1. Menor.\n";
    cout << "2. Menor o igual.\n";
    cout << "3. Mayor.\n";
    cout << "4. Mayor o igual.\n";
    cout << "5. Igual.\n";
    cout << "6. Distinto.\n";
}

void ImprimirMenuOperacionSimple(String& st1) {
    cout << "\nIngrese el string:\n";
    getline(cin,st1);
}

void ImprimirMenuOperacionesBinarias(String& st1, String& st2) {
    cout << "\nIngrese el primer string:\n";
    getline(cin,st1);
    cout << "Ingrese el segundo string:\n";
    getline(cin,st2);
}

void ImprimirMenuOperacionesDeTres(String& st1, String& st2, String& st3) {
    cout << "\nIngrese el primer string:\n";
    getline(cin,st1);
    cout << "Ingrese el segundo string:\n";
    getline(cin,st2);
    cout << "Ingrese el tercer string:\n";
    getline(cin,st3);
}

void ImprimirResultado (String& res) {
	cout << "\nString resultante:\n" << res << endl;
}

void ImprimirMenuArchivos(String& st1) {
    cout << "\nIngrese el nombre del archivo: ";
    getline(cin,st1);
}

int main(){
    cout << "<Menu de prueba del datatype String>\n\n";
    String in;
    String st1;
    String st2;
    String st3;
    String res;
    do
    {
    	ImprimirMenuPrincipal();
    	getline(cin,in);
        if (in == "1")
        {
            ImprimirMenuOperacionesDeTres(st1,st2,st3);
            res = st1 + st2 + st3;
            ImprimirResultado(res);
        }
        else if (in == "2")
        {
        	try {
        		ImprimirMenuOperacionSimple(st1);
        		cout << "Ingrese el indice correspondiente a la posicion deseada del string\n"
        		        "(indice 0 corresponde a la primer posicion):\n";
        		int i;
        		cin >> i;
        		getline(cin,in);                       
        		char val = st1[i];
        		cout << "El caracter correspondiente es: " << val << '\n';
        	}
        	catch (out_of_range& oor) {
        		cerr << "\nOut of range: " << oor.what() << endl;
            }

        }
        else if (in == "3")
        {
            ImprimirMenuOperacionSimple(st1);
            cout << "Largo = " << st1.length() << endl;
        }
        else if (in == "4")
        {
        	try {
        		ImprimirMenuOperacionSimple(st1);
        		int i, j;
        		cout << "Ingrese los subindices: ";
        		cin >> i >> j;
        		getline(cin,in);            
        		res = st1.substring(i,j);
				cout << "El substring resultado es:\n";
				cout << res << endl;
        	}
        	catch (invalid_argument& ia){
        		cerr << "\nInvalid argument: " << ia.what() << endl;
        	}

        }
        else if (in == "5")
        {
            ImprimirMenuComparacion();
            getline(cin,in);
            ImprimirMenuOperacionesBinarias(st1,st2);
            bool m = false;
            if (in == "1")
                m = st1 < st2;
            else if (in == "2")
                m = st1 <= st2;
            else if (in == "3")
                m = st1 > st2;
            else if (in == "4")
                m = st1 >= st2;
            else if (in == "5")
                m = st1 == st2;
            else if (in == "6")
                m = st1 != st2;
            else
                cout << "Entrada no valida\n";
            if (m)
                cout << "La comparacion es verdadera\n";
            else
                cout << "La comparacion es falsa\n";
        }
        else if (in == "6"){
        	ImprimirMenuArchivos(st1);
        	ofstream arch;
        	char* val = st1.getValor();
        	arch.open(val);
        	if(!arch) {
        	    cerr << "Error: No se pudo abrir el archivo.\n" << endl;
        	}
        	else {
        		ImprimirMenuOperacionSimple(st2);
        		arch << st2;
        		arch.close();
        	}

        }
        else if (in == "7"){
        	ImprimirMenuArchivos(st1);
        	ifstream arch;
        	char* val = st1.getValor();
        	arch.open(val);
        	if(!arch) {
        	    cerr << "Error: No se pudo abrir el archivo.\n" << endl;
        	}
        	else {
        		while (!arch.eof())
        		{
        			arch >> st2;
        			cout << st2 << endl;
        		}
        		arch.close();
        	}
        }
        else if (in == "8"){
                	ImprimirMenuArchivos(st1);
                	ifstream arch;
                	char* val = st1.getValor();
                	arch.open(val);
                	if(!arch) {
                	    cerr << "Error: No se pudo abrir el archivo.\n" << endl;
                	}
                	else {
                		while (!arch.eof())
                		{
                			getline(arch,st2);
                			cout << st2 << endl;
                		}
                		arch.close();
                	}
                }
        else if (in != "0")
        	cout << "Entrada no valida\n";
    }
    while (in != "0");

    cout << "Fin de prueba!!\n\n";

    return EXIT_SUCCESS;
}
