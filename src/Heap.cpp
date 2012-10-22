/*
 * Heap.cpp
 *
 *  Created on: 20-10-2012
 *      Author: Jesús
 */

#include "Heap.h"

Heap::Heap() {
	// TODO Auto-generated constructor stub

}

Heap::~Heap() {
	// TODO Auto-generated destructor stub
}

int Heap::left(int i){
	return 2*i;
}

int Heap::right(int i){
	return 2*i+1;
}

int Heap::parent(int i){
	return i/2;
}

void Heap::buildHeap(int* data, int length){

	//se inserta i con sus hijos, se verifica que sus hijos no sean menores
	//si lo son cambia al mayor


	for(int i = 2; i <= length; i++)
	{
		heapify(data,i/2,i);
	}

}

int Heap::heapify(int* data, int i, int length){

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

		//swap largest
		if(largest != i)
		{
			int tmp = data[i-1];
			data[i-1] = data[largest-1];
			data[largest-1] = tmp;

			//verifica estructura correcta con su padre
			//TODO: puede que sea necesario sacar esto para remove
			heapify(data, parent(i), length);

			//verifica denuevo en el lugar actual, por si el padre bajó
			//heapify(data, i, length);

		}
		return largest;
}

int Heap::hundir(int* data, int i, int length){

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

		//swap largest
		if(largest != i)
		{
			int tmp = data[i-1];
			data[i-1] = data[largest-1];
			data[largest-1] = tmp;

		}
		return largest;
}

void Heap::remove(int* data, int length){

	//deja al final el elemento a remover
	//y al principio el que estaba al final
	int temp;
	temp = data[0];
	data[0] = data[length-1];
	data[length-1] = temp;

	length --;

	//el nuevo elemento se ¿hunde? si es menor q sus hijos
	int i = 1;
	int nuevoi;
	while( true )
	{
		//heapify devuelve el indice donde queda el elemento heapificado
		nuevoi = hundir(data,i,length);
		if(nuevoi == i)
			break;
		else
			i = nuevoi;
	}


}

int Heap::sort(int* data, int length){


	clock_t t0 = clock();
	//deja el arreglo como heap, probado, funciona
		buildHeap(data, length);


		/*
		cout << "Heap" << endl << endl;
		for(int i = 0; i < length; i++)
		{
				cout << data[i] << "\t";
		}
		cout << endl << endl;
	*/


	for(int i = length; i>1; i--)
	{
		remove(data,i);
	}



	cout << endl << "Arreglo ordenado (";
		//arreglo está ordenado de menor a mayor
		for(int i = 0; i < length; i++)
		{
			cout << data[i] << ",";
		}
	cout <<")"<<endl;

	clock_t t1 = clock();
	return t1-t0;
}
