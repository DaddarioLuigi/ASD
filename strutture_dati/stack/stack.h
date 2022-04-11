
/***************************************************************************
 *   Stack                                 						           *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene la definizione delle funzioni della classe 	   *
 *   Stack.			       												   *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/

#ifndef STACK_H
#define STACK_H

template <class E>
class stack
{
	public:
		typedef E tipoelem; //definisco il tipo di dato da utilizzare
		stack();
		stack(int);
		~stack();
		void createStack(); //operator
		bool isEmpty();
		tipoelem readStack();
		void pop();
		void push(tipoelem);
	private:
		tipoelem *elementi; //puntatore a elementi dello stack
		int head;
		int MAXLUNGH = 100;
};

#endif
