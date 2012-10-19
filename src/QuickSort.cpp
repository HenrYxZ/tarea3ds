/*
 * QuickSort.cpp
 *
 *  Created on: 18-10-2012
 *      Author: Sebastián
 */

#include "QuickSort.h"

QuickSort::QuickSort() {
	// TODO Auto-generated constructor stub

}

QuickSort::~QuickSort() {
	// TODO Auto-generated destructor stub
}

void QuickSort::tradQuickSort(int*	arr,	int from,	int to){

	if	(to-from	+1	<=	1)
	{
		return;
	}
	int index_pivote	=	pivot(arr,from,to);
	tradQuickSort(arr,from,index_pivote	-1);
	tradQuickSort(arr,index_pivote+1,to);
}

int QuickSort::pivot(int*	arr,int from,int	to)
{
	int index_pivote	=	chooseFirst(arr,from,to);
	int temp	=	arr[index_pivote];
	arr[index_pivote]	=	arr[from];
	arr[from]	=	temp;
	index_pivote	=	from;
	int valor_pivote	=	arr[index_pivote];
	for	(int i=from+1;	i<=to;	i++){
		 	if	(arr[i]	<	valor_pivote){
		 	 	index_pivote++;
	temp=arr[i];
		 	 	arr[i]=arr[index_pivote];
		 	 	arr[index_pivote]=temp;
		 	}
	}
	temp=arr[from];
	arr[from]=arr[index_pivote];
	arr[index_pivote]=temp;
	return	index_pivote;
}
int QuickSort::chooseFirst(int*	arr,	int from,	int to)
{
	return from;
}
int QuickSort::chooseRandom(int*	arr,	int from,	int to)
{
	return from;//falta implementar el random
}
int QuickSort::chooseMedian(int*	arr,	int from,	int to)
{
	return from;//falta implementar la mediana
}
