/*
 * Heap.h
 *
 *  Created on: 20-10-2012
 *      Author: Jesús
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>

using namespace std;

class Heap {
public:
	Heap();
	virtual ~Heap();
	void sort(int* data, int length);
	void buildHeap(int* data, int length);
	int heapify(int* data, int i, int length);
	int left(int i);
	int right(int i);
	int parent(int i);

	int hundir(int*data, int i, int length);
	void remove(int* data, int length);
};

#endif /* HEAP_H_ */
