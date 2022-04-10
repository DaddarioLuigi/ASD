
/*

matrice.cpp

*/

#include "matrice.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;


/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> matrice<T>::init(int r, int c){ 

  colonne = c;
  righe = r;
  
  int i,j;
	// allocazione del vettore di puntatori a tipoelem
  elementi = new T* [righe]; 
  for (i=0; i < righe; i++)
		// allocazione dei singoli vettori righe di elementi di tipo tipoelem
    elementi[i] = new T[colonne];
  // inizializzazione degli elementi a valore nullo
  for (i=0;i<righe;i++)
		for (j=0;j<colonne;j++)
			elementi[i][j]=0;
}


/*
***************************************************************************
***************************************************************************
INPUT: r->posizione riga c->posizione colonna T e-> elemento e da aggiungere
OUTPUT: void
ALGORITMO: scrive in posizione r,c
***************************************************************************
***************************************************************************
*/
template <typename T> void matrice<T>::scrivimatrice(int r, int c, T e)
{
	elementi[r][c] = e;
}


/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
template <typename T> T matrice<T>::leggimatrice(int r, int c) {
	return elementi[r][c];
}


/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
template <typename T> matrice<T>::~matrice(){
	for (int j=0; j<colonne; j++)
		delete[] elementi[j];
	delete [] elementi;
}

/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
template <typename T> int matrice<T>::getRighe()
{
	int __righe=righe;
	return __righe;
}

/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
template <typename T> int matrice<T>::getColonne()
{
	int __colonne=colonne;
	return __colonne;
}


/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
template <typename T> void matrice<T>::riempiRandom(){
	srand(time(NULL));
	for (int i=0; i<righe; i++)
		for (int j=0; j<colonne; j++)
			elementi[i][j] = rand() % 100;
}


/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
//stampa una matrice
template <typename T> void matrice<T>::stampa(){
	std::cout << std::endl;
	for (int i=0; i<righe; i++){
		std::cout << std::endl;	
		cout << "\n";	
		for (int j=0; j<colonne; j++)
			std::cout << elementi[i][j] << " ";
	}
	std::cout << std::endl;
}


/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
ALGORITMO: 
***************************************************************************
***************************************************************************
*/
template <typename T> matrice<T> &matrice<T>::operator=(const matrice &m){
	// evita gli auto assegnamenti
	if (this == &m) return *this;
	else {
		int i,j;
		if (colonne != m.colonne || righe != m.righe){
			this->~matrice();
			colonne = m.colonne;
			righe = m.righe;
			elementi = new T* [righe]; 
			for (i=0; i < righe; i++)
				elementi[i] = new T[colonne];
		}
		for (i=0;i<righe;i++)
			for (j=0;j<colonne;j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return *this;
}




