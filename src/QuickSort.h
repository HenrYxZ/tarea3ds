/*
 * QuickSort.h
 *
 *  Created on: 18-10-2012
 *      Author: Sebastián
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

class QuickSort {
public:
	QuickSort();
	virtual ~QuickSort();
	void tradQuickSort(int*	arr,	int from,	int to);
	int pivot(int*	arr,int from,int	to);
	int chooseFirst(int*	arr,	int from,	int to);
	int chooseRandom(int*	arr,	int from,	int to);
	int chooseMedian(int*	arr,	int from,	int to);

};

#endif /* QUICKSORT_H_ */
