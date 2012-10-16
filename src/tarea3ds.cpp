//============================================================================
// Name        : tarea3ds.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TraditionalHeap.h"
using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	TraditionalHeap t = TraditionalHeap();
	int ar[] = {2,3,5,18,7,91,112,1,23,40,3,6};
	t.sort(ar,12);
	return 0;
}
