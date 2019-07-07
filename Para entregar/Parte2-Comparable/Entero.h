/*
 * Entero.h
 *
 *  Created on: Mar 22, 2011
 *      Author: p4gr22
 */

#ifndef ENTERO_H_
#define ENTERO_H_

#include "Comparable.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Entero : public Comparable {

private:
	int valor;
	
	char* getCadena() { return NULL; }

public:
	Entero(int = 0);
	int getValor() { return valor; }

	int comparar (Comparable&);

};


#endif /* ENTERO_H_ */
