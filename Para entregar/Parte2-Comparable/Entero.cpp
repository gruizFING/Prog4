/*
 * Entero.cpp
 *
 *  Created on: Mar 22, 2011
 *      Author: p4gr22
 */

#include "Entero.h"

Entero::Entero(int i) {
	valor = i;
}

int Entero::comparar (Comparable& e) {
	return (valor - e.getValor());
}



