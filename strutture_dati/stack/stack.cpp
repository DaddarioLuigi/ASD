
/***************************************************************************
 *   Stack                                 						           *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene l'implementazione delle funzioni della classe    *
 *   Stack.			       												   *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/

#include <iostream>
#include "stack.h"

using namespace std;

template <class E> stack<E>::stack() {
	elementi = new tipoelem[MAXLUNGH]; //dim standard della pila
	head = 0;
}

template <class E> stack<E>::stack(int x)
{
	MAXLUNGH = x;
	elementi = new tipoelem[MAXLUNGH];
	head = 0;
}

template <class E> stack<E>::~stack() {
	delete[] elementi;
}

template <class E> void stack<E>::createStack() {
	head = 0;
}

template <class E> bool stack<E>::isEmpty()
{
	if(head==0)return true;
	else return false;
}

template <class E> E stack<E>::readStack() //read last inserted value
{
	return elementi[head-1];
}

template <class E> void stack<E>::pop()
{
	if(!isEmpty())
		head-=1;
	else
		cout << "no elements in list" << endl;	
} 

template <class E> void stack<E>::push(tipoelem el)
{
	if(head==MAXLUNGH) {
		cout << "over cap" << endl;
	}
	else
	{
		elementi[head] = el;
		head++;
	}
}
