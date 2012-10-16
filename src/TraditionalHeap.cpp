/*
 * TraditionalHeap.cpp
 *
 *  Created on: 15-10-2012
 *      Author: Usado según http://www.cs.auckland.ac.nz/~jmor159/PLDS210/heapsort.html enseñado en clases
 */

#include "TraditionalHeap.h"

TraditionalHeap::TraditionalHeap() {
	// TODO Auto-generated constructor stub

}

TraditionalHeap::~TraditionalHeap() {
	// TODO Auto-generated destructor stub
}



int TraditionalHeap::left(int i) {

	return 2*i;

}

int TraditionalHeap::right(int i) {

	return 2*i+1;

}

void TraditionalHeap::heapify(int* data, int i, int length) {

	//setea indices de los hijos
	int l = left(i);
	int r = right(i);

	int largest;

	//si el hijo izquierdo es mayor lo guarda
	if(l <= length && data[l-1] > data[i-1])
		largest = l;
	else {
		largest = i;
	}
	//si el hijo derecho es mayor que el "menor" lo deja como el menor de todos
	if(r <= length && data[r-1] > data[largest-1])
		largest = r;

	//swap smallest
	if(largest != i)
	{
		int tmp = data[i-1];
		data[i-1] = data[largest-1];
		data[largest-1] = tmp;

		//restablecer estructura en los descendientes
		heapify(data, largest, length);
	}

}

void TraditionalHeap::buildHeap(int* data, int length) {

	for(int i = length/2; i >0; i--)
	{
		heapify(data, i, length);
	}

}

void TraditionalHeap::sort(int* data, int length) {

	//deja el arreglo como heap, probado, funciona
	buildHeap(data, length);


	cout << "Heap" << endl << endl;
	for(int i = 0; i < length; i++)
	{
			cout << data[i] << "\t";
	}
	cout << endl << endl;

	int temp;
	for(int i = length; i >1 ; i--)
	{
		//swap "last" in the heap with the first
		temp = data[0];
		data[0] = data[i-1];
		data[i-1] = temp;

		heapify(data, 1, i-1);
	}

	cout << "Arreglo ordenado" << endl << endl;
	//arreglo está ordenado de menor a mayor
	for(int i = 0; i < length; i++)
	{
		cout << data[i] << "\t";
	}

}
