/*
 * TraditionalHeap.h
 *
 *  Created on: 15-10-2012
 *      Author: Jesús
 */

#ifndef TRADITIONALHEAP_H_
#define TRADITIONALHEAP_H_

#include <iostream>
#include<time.h>

using namespace std;

class TraditionalHeap {
public:
	TraditionalHeap();
	virtual ~TraditionalHeap();
	int sort(int* data, int length);
	void buildHeap(int* data, int length);
	void heapify(int* data, int i, int length);
	int left(int i);
	int right(int i);


};

#endif /* TRADITIONALHEAP_H_ */
