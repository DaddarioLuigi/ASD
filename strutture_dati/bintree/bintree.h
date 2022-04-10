
/***************************************************************************
 *   Alberi Binari                                 						   *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene la definizione delle funzioni della classe 	   *
 *   bintree, che rappresenta struttura dati degli alberi binari.	       *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <queue>
#include <stdio.h>


using namespace std;




template <typename T>
struct Node 
{
		T key;
		Node *left;
		Node *right;
};
	
template <class T>
class bintree {
	public:
		bintree<T>() //costruttore
		{
			root = NULL;
		}
		void insert(T); //inserimento di un nodo
		Node<T>* getRoot(); 
		int getLeafs(); //calcola le foglie
		int getLevelUtil(Node<T>* node, T data, int level); //util per il calcolo del livello
		int getLevel(Node<T>* node, T data); //Dato un nodo calcola il livelllo corrispondente
		bool isZero();
		Node<T>* search(T key); //ricerca di un nodo 
		void deleteNode(T key); //cancella nodo
		void printTree(); //stampa a video, molto semplice
	private:
		Node<T> *root;
		Node<T>* createNode(T key) //crea una nuova istanza della struct nodo
		{
			Node<T> *node = new Node<T>(); 
			node->key = key;
			node->left = NULL;
			node->right = NULL;
			return node;
		}	
};

//
//void deleteNode(Node *root, char *key);
//int getNumberOfLeafs(Node *root);

#endif
