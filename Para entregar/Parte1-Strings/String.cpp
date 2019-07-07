/*
 * File:   String.cpp
 * Author: p4gr22
 *
 * Created on March 18, 2011, 1:40 PM
 */

#include "String.h"


String::String() {
    largo = 0;
    valor = new char[1];
    strcpy(valor,"");
}

String::String(const String& orig) {
    largo = orig.largo;
    valor = new char[largo+1];
    strcpy(valor,orig.valor);
}

String::String(const char* c){
    largo = strlen(c);
    valor = new char[largo+1];
    strcpy(valor,c);
}
String::~String() {
    delete [] valor;
}

char* String::getValor() {
    char* n = new char[largo+1];
    strcpy(n, valor);
    return n;
}


String String::substring(int i, int j) {
	try {
		if ((i < 0) || (j < 0) || (i >= largo) || (j >= largo))
		{
			invalid_argument ia("String::substring");

			throw ia;
		}

		int min, max;
		if (i < j)
		{
			min = i;
			max = j;
		}
		else
		{
			min = j;
			max = i;
		}
		int l = max - min + 1;
		char* nuevo = new char[l+1];
		for (int I=min;I <= max;I++)
			nuevo[I-min] = valor[I];
		nuevo[l] = '\0';
		String st;
		st.largo = l;
		st.valor = nuevo;
		return st;
	}
	
	catch (invalid_argument& ia){
		throw ia;
	}
}

String& String::operator= (const String& S){
    char* temp = new char[S.largo+1];
    strcpy(temp,S.valor);
    delete [] valor;
    valor = temp;
    largo = S.largo;
    return (*this);
}

String& String::operator+ (const String& S){
    char* ret = new char[largo + S.largo +1];
    strcpy(ret,valor);
    strcat(ret,S.valor);
    String* res = new String(ret);
    return *res;
}

bool String::operator< (const String& S){
     return (strcmp(this->valor,S.valor) < 0);
}

bool String::operator> (const String& S){
     return (strcmp(this->valor,S.valor) > 0);
}

bool String::operator<= (const String& S){
     return (strcmp(this->valor,S.valor) <= 0);
}

bool String::operator>= (const String& S){
     return (strcmp(this->valor,S.valor) >= 0);
}

bool String::operator== (const String& S){
     return (strcmp(this->valor,S.valor) == 0);
}

bool String::operator!= (const String& S){
     return (strcmp(this->valor,S.valor) != 0);
 }

bool operator< (const char* cad, String& s) {
	return (strcmp(cad,s.getValor()) < 0);
}

bool operator> (const char* cad, String& s) {
	return (strcmp(cad,s.getValor()) > 0);
}

bool operator<= (const char* cad, String& s) {
	return (strcmp(cad,s.getValor()) <= 0);
}

bool operator>= (const char* cad, String& s) {
	return (strcmp(cad,s.getValor()) >= 0);
}

bool operator== (const char* cad, String& s) {
	return (strcmp(cad,s.getValor()) == 0);
}

bool operator!= (const char* cad, String& s) {
	return (strcmp(cad,s.getValor()) != 0);
}


char String::operator[] (int i) {
    try {
		if ((i < 0) || (i >= largo)) {
			out_of_range oor("String::operator[]");
			throw oor;
		}
		return (valor[i]);
    }
    catch (out_of_range& oor) {
    	throw oor;
    }
}


ostream& operator<<(ostream& oc, String& s) {
    oc << s.getValor();
    return oc;
}

istream& getline(istream& ic, String& in) {
    char* val = new char[256];
    ic.getline(val, 256, '\n');
    char* input = new char[strlen(val)+1];
    strcpy(input,val);
    delete [] val;
    in = input;
    return ic;
}

istream& operator>>(istream& ic, String& in) {
    char* val = new char[256];
    ic >> val;
    char* input = new char[strlen(val)+1];
    strcpy(input,val);
    delete [] val;
    in = input;
    return ic;
}

ofstream& operator<<(ofstream& oc, String& s) {
    char* val = s.getValor();
	oc << val;
    return oc;
}

ifstream& getline(ifstream& ic, String& in) {
    char* val = new char[256];
    ic.getline(val,256);
    char* input = new char[strlen(val)+1];
    strcpy(input,val);
    in = input;
    return ic;
}

ifstream& operator>>(ifstream& ic, String& in) {
    char* val = new char[256];
    ic >> val;
    char* input = new char[strlen(val)+1];
    strcpy(input,val);
    in = input;
    return ic;
}


