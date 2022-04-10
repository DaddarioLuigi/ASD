
/***************************************************************************
 *   Alberi n-ari                                 						   *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene la definizione delle funzioni della classe 	   *
 *   ntrees, che rappresenta struttura dati degli alberi n-ari.	 	       *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/

#ifndef NTREES_H
#define NTREES_H

#include <vector>
#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

template <typename T> 

struct Node
{
	T key;
	vector<Node*> child;
};

template <class T>
class ntrees
{
	public:
		ntrees<T>(T key) {
			//std::cout << key << std::endl;
			root = createNode(key);
			leaf = 0;
		//	root = createNode(T key);
		};
		
		Node<T> *getRoot()
		{
			return root;
		}
		
		/* Restituisce il numero di nodi in T di livello k */
		int n_level(Node<T> *root, int k, ntrees<T> Tree);
		int getLevel(Node<T> *node, Node<T> *root, ntrees<T> Tree);	
		int n_leaf(Node<T> *root, ntrees<T> Tree);
		void insertTree(Node<T> *root, T key, T parent);
		Node<T> *search(T key);
		Node<T> *searchDeepestRight(T key);
		Node<T> *getDeepest(Node<T> *node);
		void deleteNode(T key);
		Node<T> *createNode(T key)
		{
			Node<T> *node = new Node<T>();
			node->key = key;
			//node->child.push_back(node); // non va bene
		}
		
		private:
			Node<T> *root;
			int leaf;

};





#endif
