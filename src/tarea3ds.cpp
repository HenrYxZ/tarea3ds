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
#include <fstream>
#include "TraditionalHeap.h"
#include "QuickSort.h"
#include "Heap.h"

using namespace std;


int main() {
	srand(time(NULL));


	//instanciar ordenadores
	TraditionalHeap t = TraditionalHeap();
	QuickSort q=QuickSort();
	Heap h = Heap();



	//tiempos randoms
	//TODO: cambiar a 5 para poner los tiempos de todos los algortms
	//son 300 arreglos por ordenar, 100 instancias para cada uno de los 3 tipos
	int tiempos[5][300];


	//arreglos de prueba
	int Random[10000];
	int OrdMay[10000];
	int OrdMen[10000];

	int May2[10000];
	int May3[10000];
	int May4[10000];
	int May5[10000];

	int Men2[10000];
	int Men3[10000];
	int Men4[10000];
	int Men5[10000];

	int Ran2[10000];
	int Ran3[10000];
	int Ran4[10000];
	int Ran5[10000];

	cout << "creando arreglos y ordenando..." << endl << endl;

	for(int j = 1; j < 100; j++)
	{
		cout << "iteracion:" << j << endl;

		/* generar los distintos
		 * arreglos ordenados o no ordenados
		 * 100 veces
		 */

		//distancia que tendrán los numeros ordenados entre si
		int distancia = rand() % j + 1;

		OrdMay[0] = 20000;
		May2[0] = 20000;
		May3[0] = 20000;
		May4[0] = 20000;
		May5[0] = 20000;

		OrdMen[0] = 1;
		Men2[0] = 1;
		Men3[0] = 1;
		Men4[0] = 1;
		Men5[0] = 1;

		Random[0] = rand() % 20000 + 1;
		Ran2[0]=Random[0];
		Ran3[0]=Random[0];
		Ran4[0]=Random[0];
		Ran5[0]=Random[0];

		for(int i = 1; i < 10000; i++)
		{
			distancia = rand() % j + 1;
			OrdMay[i] = OrdMay[i-1] - distancia;
			May2[i]=OrdMay[i];
			May3[i]=OrdMay[i];
			May4[i]=OrdMay[i];
			May5[i]=OrdMay[i];

			distancia = rand () % j + 1;
			OrdMen[i] = OrdMen[i-1] + distancia;
			Men2[i]=OrdMen[i];
			Men3[i]=OrdMen[i];
			Men4[i]=OrdMen[i];
			Men5[i]=OrdMen[i];


			Random[i] = rand() % 20000 + 1;
			Ran2[i]=Random[i];
			Ran3[i]=Random[i];
			Ran4[i]=Random[i];
			Ran5[i]=Random[i];


		}



		//ocupa sort en el arreglo generado
		//los tiempos de 0 a 99 son de mayor a menor
		// de 100 a 199 son menor a mayor
		// de 200 a 299 son random

		tiempos[0][j] = t.sort(OrdMay,10000);
		tiempos[0][j+100] = t.sort(OrdMen,10000);
		tiempos[0][j+200] = t.sort(Random,10000);

		tiempos[1][j] = h.sort(May2,10000);
		tiempos[1][j+100] = h.sort(Men2,10000);
		tiempos[1][j+200] = h.sort(Ran2,10000);

		tiempos[2][j] = q.tradQS(May3,10000);
		tiempos[2][j+100] = q.tradQS(Men3,10000);
		tiempos[2][j+200] = q.tradQS(Ran3,10000);

		tiempos[3][j] = q.randQS(May4,10000);
		tiempos[3][j+100] = q.randQS(Men4,10000);
		tiempos[3][j+200] = q.randQS(Ran4,10000);

		tiempos[4][j] = q.medQS(May5,10000);
		tiempos[4][j+100] = q.medQS(Men5,10000);
		tiempos[4][j+200] = q.medQS(Ran5,10000);

	}


	cout << "Orden mayor a menor heap 2.0 " << tiempos[0][0] << " operaciones\t";
	cout << ( (float)tiempos[0][0] )/CLOCKS_PER_SEC << " segundos" << endl ;
	cout << "Orden mayor a menor heap 2.0 " << tiempos[0][1] << " operaciones\t";
	cout << ( (float)tiempos[0][1] )/CLOCKS_PER_SEC << " segundos" << endl ;
	cout << "Orden mayor a menor heap 2.0 " << tiempos[0][2] << " operaciones\t";
	cout << ( (float)tiempos[0][2] )/CLOCKS_PER_SEC << " segundos------------" << endl ;
	cout << "Orden menor a mayor heap 2.0 " << tiempos[0][100] << " operaciones\t";
	cout << ( (float)tiempos[0][100] )/CLOCKS_PER_SEC << " segundos" << endl ;
	cout << "Orden random heap 2.0 " << tiempos[0][200] << " operaciones\t";
	cout << ( (float)tiempos[0][200] )/CLOCKS_PER_SEC << " segundos" << endl ;

	cout << "Orden mayor a menor heap  " << tiempos[1][0] << " operaciones\t";
	cout << ( (float)tiempos[1][0] )/CLOCKS_PER_SEC << " segundos" << endl ;
	cout << "Orden menor a mayor heap  " << tiempos[1][1] << " operaciones\t";
	cout << ( (float)tiempos[1][100] )/CLOCKS_PER_SEC << " segundos" << endl ;
	cout << "Orden random heap  " << tiempos[1][2] << " operaciones\t";
	cout << ( (float)tiempos[1][200] )/CLOCKS_PER_SEC << " segundos" << endl ;



	ofstream output;
	output.open("output.csv");
	for(int j = 0; j < 300; j++)
		{
		for(int i = 0; i < 5; i++){

			output << tiempos[i][j]<< ";";
				}
		output<<endl;
		}


	output.close();



	/*
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


	cout << endl;
	int ar2[] = {2,3,5,18,7,91,112,1,23,40,3,6};
	cout << "heap" << endl << endl;

	h.sort(ar2,12);
	*/
	return 0;
}
