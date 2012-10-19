//============================================================================
// Name        : tarea3ds.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include<time.h>
#include "TraditionalHeap.h"
#include "QuickSort.h"

using namespace std;


int main() {
	srand(time(NULL));
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	TraditionalHeap t = TraditionalHeap();
	QuickSort q=QuickSort();
	int ar[] = {2,3,5,18,7,91,112,1,23,40,3,6};

	cout << "ANTES" << endl << endl;
		//arreglo está ordenado de menor a mayor
		for(int i = 0; i < 12; i++)
		{
			cout << ar[i] << "\t";
		}
	q.medQS(ar,12);
	cout <<endl<< "DESPUES" << endl << endl;
	for(int i = 0; i < 12; i++)
	{
		cout << ar[i] << "\t";
	}
	return 0;
}
