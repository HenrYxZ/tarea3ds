/*
 * QuickSort.h
 *
 *  Created on: 18-10-2012
 *      Author: Sebastián
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <stdlib.h>
using namespace std;

class QuickSort {
private:
	void tradQSRec(int*	arr,	int from,	int to);
	int pivotFirst(int*	arr,int from,int	to);
	void randQSRec(int*	arr,	int from,	int to);
	void medQSRec(int*	arr,	int from,	int to);
	int pivotRandom(int*	arr,int from,int	to);
	int pivotMedian(int*	arr,int from,int	to);
	int chooseRandom(int from,	int to);
	int chooseMedian(int*	arr,	int from,	int to);
public:
	QuickSort();
	virtual ~QuickSort();
	void tradQS(int* arr,int length);
	void randQS(int* arr,int length);
	void medQS(int* arr,int length);


};

#endif /* QUICKSORT_H_ */
