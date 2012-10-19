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

void QuickSort::tradQSRec(int*	arr,	int from,	int to){

	if	(to-from	+1	<=	1)
	{
		return;
	}
	int index_pivote	=	pivotFirst(arr,from,to);
	tradQSRec(arr,from,index_pivote	-1);
	tradQSRec(arr,index_pivote+1,to);
}

void QuickSort::tradQS(int* arr,int length)
{
	tradQSRec(arr,0,length-1);
}

int QuickSort::pivotFirst(int*	arr,int from,int	to)
{
	int index_pivote	=	from;
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

void QuickSort::randQSRec(int*	arr,	int from,	int to){

	if	(to-from	+1	<=	1)
	{
		return;
	}
	int index_pivote	=	pivotRandom(arr,from,to);
	tradQSRec(arr,from,index_pivote	-1);
	tradQSRec(arr,index_pivote+1,to);
}
void QuickSort::randQS(int* arr,int length){
	randQSRec(arr,0,length-1);

}
int QuickSort::pivotRandom(int*	arr,int from,int	to)
{
	int index_pivote	=	chooseRandom(from,to);
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

int QuickSort::pivotMedian(int*	arr,int from,int	to)
{
	int index_pivote	=	chooseMedian(arr,from,to);
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

int QuickSort::chooseRandom(int from,	int to)
{
	int random;
	random = from + rand() % (to +1 - from);
	return random;
}
void QuickSort::medQS(int* arr,int length){
	medQSRec(arr,0,length-1);

}
void QuickSort::medQSRec(int*	arr,	int from,	int to){

	if	(to-from	+1	<=	1)
	{
		return;
	}
	int index_pivote	=	pivotMedian(arr,from,to);
	tradQSRec(arr,from,index_pivote	-1);
	tradQSRec(arr,index_pivote+1,to);
}

int QuickSort::chooseMedian(int*	arr,	int from,	int to)
{
	// data[0], data[(length-1)/2] y	data[length-1]
	if(to<2){
		return 0;
	}

	int a,b,c;
	a=arr[0];
	b=arr[to/2];
	c=arr[to];

	if(a>b){
		if(a>c){
			//a es el mayor
			if(b>c){
				//a>b>c
				return to/2;
			}
			else{
				//a>c>d
				return to;
			}
		}
		else{
			//c>a>b
			return 0;
		}
	}
	else{
		if(b>c){
			//b es el mayor
			if(a>c){
				//b>a>c
				return 0;
			}
			else{
				//b>c>a
				return to;
			}
		}
		else{
			//c>b>a
			return to/2;
		}

	}
}
