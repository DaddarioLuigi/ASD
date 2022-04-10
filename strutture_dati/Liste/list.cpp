
/***************************************************************************
 *   Liste                                 						           *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene la definizione delle funzioni della classe 	   *
 *   Liste.			       												   *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/

#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

template <typename T> List<T>::List(){
	head = NULL;
	current = NULL;
	temp = NULL;
}

/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::AddNode(T addData){
	
	node<T> *n = new node<T>;
	n->next =  NULL;
	n->data = addData;
	
	//se la lista esiste gia
	if(head != NULL) {
		current = head;
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = n;
	}
	else
	{
		head = n;
	}
	
}

/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::PrintList()
{
	current=head;
	while(current != NULL)
		{
			cout << current->data << endl;
			current = current->next; //devo puntare a quello successivo
		}
}

/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
SCOPO: 
***************************************************************************
***************************************************************************
*/
template <typename T> node<T>* List<T>::getNode(T el)
{
	node<T> *pointerToel = NULL;
	current = head;
	while(current->data != el)
	{
		current=current->next;
	}
	
	pointerToel = current;
	
	return pointerToel;
	
}

/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
SCOPO: Scambia due elementi nella lista
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::exchange(T p1, T p2)
{
	node<T> *pointerTop1 = getNode(p1);
	node<T> *pointerTop2 = getNode(p2);
	

	pointerTop1->data = pointerTop2->data;
	pointerTop2->data = p1;	
}

/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
SCOPO: Trova il minimo con la ricorsione 
***************************************************************************
***************************************************************************
*/
template <typename T> T List<T>::findMin(node<T> *head)
{

	current = head;
	T min = head->data;
	
	while(current->next != NULL)
	{
		if(current->next->data < min)
			min = current->next->data;
			
		current=current->next;
	}
	return min;
}

/*
***************************************************************************
***************************************************************************
INPUT: 
OUTPUT: 
SCOPO: Trova il massimo con la ricorsione 
***************************************************************************
***************************************************************************
*/
template <typename T> T List<T>::findMax(node<T> *head)
{
	current = head;
	T max = head->data;
	
	while(current->next != NULL)
	{
		if(current->data > max)
			max = current->data;
			
		current = current->next;
	}
	return max;
}


template <typename T> node<T>* List<T>::findEnd()
{
	current = head;
	while(current->next != NULL)
		current = current->next;
		
	return current;
}



template <typename T> void List<T>::move_min_max()
{
	T min = findMin(head);
	node<T> *end = findEnd();
	T max = findMax(end);
	
	exchange(min,max);

}


/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> int List<T>::num_elements(T p1, T p2)
{
	//dobbiamo trovare prima la posizione p1
	current = head;
	int x =0,elements=0;
	while(current->data != p1)
	{	
		x++;
		current = current->next;
	}
	
	current = head;
	current = current + x;
	while(current->data != p2)
	{
		elements++; //count elements
		current = current->next;
	}
	
	return elements;
	
}


/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> bool List<T>::operator!=(List<T> &l)
{
		if (this == &l) return true;
	else {
		int lenght = this->ListLenght();
		int lenghtl2 = l.ListLenght();
		if(lenght == lenghtl2)
			return true;
		else return false;
	}

}


/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::deleteNode(T delData)
{
	node<T>* delPointer = NULL;
	temp =  head;
	current = head;
	
	/*
	quello che facciamo è cercare di capire
	dove è presente il dato che vogliamo 
	eliminare. Ci posizioniamo quindi all'inizio
	per capire se effettivamente è li che 
	abbiamo il dato, altrimenti dobbiamo scorrere
	come se fosse un puntatore a lista (è cosi!!)
	*/
	
	while(current != NULL && current->data != delData)
	{
		temp = current;
		current = current->next;
	}
	
	//if i did not found it 
	if(current == NULL)
	{
		cout << delData <<  "not in list" << endl;
	}
	else 
	{
		delPointer = current;
		current = current->next;
		temp->next = current;
		delete delPointer;
		cout << "The value " << delData << "has been deleted\n" << endl;
	}
	
}


/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> int List<T>::ListLenght()
{
	current = head;
	int lenght = 0;
	while(current->next != NULL)
	{
		current = current->next;
		lenght++;
	}
	return lenght;
}

/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::calculateEnd()
{
	
	temp = head;
	while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
	
}

/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::reverse()
{
 		
	node<T>* current = head;
	node<T>* temp = NULL;
	node<T>* next = NULL;
	
	while(current != NULL)
	{
		next = current->next;
		current->next = temp;
		
		temp = current;
		current = next;
	}
 	head = temp;
}

/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> bool List<T>::isPalindrome() 
{
	node<T>* current = head;
	calculateEnd(); //temp will be at last 
	node<T>* next = NULL;
	int counter = 0;
	
	while(current != temp)
	{
		
		if(current->data == temp->data)
			{
				counter++;
			}
		else
		{
			return false;
		}
		current = current->next;
		getPrec();
	}
	

	return true;
}

/*
***************************************************************************
***************************************************************************
INPUT: righe e colonne da inizializzare a 0
OUTPUT: M'
ALGORITMO: allocazione di r righe e c colonne e set dei valori a 0
***************************************************************************
***************************************************************************
*/
template <typename T> void List<T>::getPrec()
{
	node<T>* prec = head;
	node<T>* temp_2 = temp;
	while(prec != temp_2)
	{
		temp = prec;
		prec = prec->next;
	}
	
}
