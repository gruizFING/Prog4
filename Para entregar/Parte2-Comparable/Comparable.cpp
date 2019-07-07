/*
 * Comparable.cpp
 *
 *  Created on: Mar 22, 2011
 *      Author: p4gr22
 */

#include "Comparable.h"




void Comparable::ordenar(Comparable** c, int largo){
	for (int i=0;i<largo-1;i++){
		int min = i;
		for (int j=i+1; j<largo;j++){
			if (c[j]->comparar(*c[min]) < 0)
				min = j;
		}

		Comparable* temp;
		temp = c[i];
		c[i] = c[min];
		c[min] = temp;
	}
}



