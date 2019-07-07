/*
 * Comparable.h
 *
 *  Created on: Mar 22, 2011
 *      Author: p4gr22
 */

#ifndef COMPARABLE_H_
#define COMPARABLE_H_

class Comparable {

public:
	virtual ~Comparable() {};
	virtual int getValor() = 0;
    virtual char* getCadena() = 0;

	virtual int comparar(Comparable&) = 0;
	static void ordenar(Comparable**, int);
};

#endif /* COMPARABLE_H_ */
