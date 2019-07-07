/*
 * File:   String.h
 * Author: p4gr22
 *
 * Created on March 18, 2011, 1:40 PM
 */

#ifndef STRING_H
#define	STRING_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>
using namespace std;

class String {
private:
    char* valor;
    int largo;

public:
    String();
    String(const char*);
    String(const String&);
    virtual ~String();

    char* getValor();
    int length() { return largo; }
    String substring(int, int);

    String& operator= (const String&);
    String& operator+ (const String&);
    char operator[] (int);

    bool operator< (const String&);
    bool operator> (const String&);
    bool operator<= (const String&);
    bool operator>= (const String&);
    bool operator== (const String&);
    bool operator!= (const String&);

};

bool operator< (const char*, String&);
bool operator> (const char*, String&);
bool operator<= (const char*, String&);
bool operator>= (const char*, String&);
bool operator== (const char*, String&);
bool operator!= (const char*, String&);

ostream& operator<< (ostream&, String&);
istream& getline(istream&, String&);
istream& operator>> (istream&, String&);

ofstream& operator<<(ofstream&, String&);
ifstream& getline(ifstream&, String&);
ifstream& operator>>(ifstream&, String&);

#endif	/* STRING_H */
