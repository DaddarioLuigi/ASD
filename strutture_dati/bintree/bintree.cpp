
/***************************************************************************
 *   Alberi Binari  (bintree.cpp)                               		   *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene l'implementazione delle funzioni della classe    *
 *   bintree, che rappresenta struttura dati degli alberi binari.	       *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/
 
#include <queue>
#include <iostream>
#include <string.h>


#include "bintree.h"

using namespace std;


//check if tree is a 0 tree
template <typename T> bool bintree<T>::isZero()
{
	queue<Node<T>*> q;
	q.push(root);
	
	while(!q.empty())
	{
		Node<T> *temp = q.front();
		q.pop();
		if((temp->left != NULL) && (temp->right != NULL))
		{
			//se il nodo è 0 i figli devono essere due uno
			if(temp->key == 0)
			{
				if((temp->left->key == 1)	&& (temp->right->key == 1))
				{
					q.push(1);
				}
				else return;
			}
			
			if(temp->key == 1)
			{
				if((temp->left->key == 0)	&& (temp->right->key == 0))
				{
					q.push(0);
				}
				else return;
			}
			
		}
		else return;
	}
	
}


/*
***************************************************************************
***************************************************************************
INPUT: chiave del nodo 
OUTPUT: void
ALGORITMO: Data una chiave da inserire, la inserisce nell'albero binario
***************************************************************************
***************************************************************************
*/
template <typename T> void bintree<T>::insert(T key)
{
	
	if(root == NULL)
	{
		root = createNode(key);
		return;
	}
	
	Node<T> *nodeToInsert = createNode(key); //nodo da inserire 
	queue<Node<T>*> q; //coda di supporto
	q.push(root);
	

	while(!q.empty())
	{
		Node<T> *temp = q.front();
		q.pop();
		if(temp->left == NULL)
		{
			temp->left = nodeToInsert;
			return;
		}
		else
		{
			q.push(temp->left);
		}
		
		if(temp->right == NULL)
		{
			temp->right = nodeToInsert;
			return;
		}
		else
		{
			q.push(temp->right);
		}
	}
	
}

/*
***************************************************************************
***************************************************************************
INPUT: Nodo da confrontare, valore di cui si cerca il livello, int
OUTPUT: livello corrispondente al dato 
ALGORITMO: Chiama ricorsivamente se stessa, finchè non trova il lv piu basso
***************************************************************************
***************************************************************************
*/
template <typename T> int bintree<T>::getLevelUtil(Node<T>* node, T data, int level)

{
    if (node == NULL)
        return 0;
 
 	//cosa succede se node->key è di tipo char?
    if (node->key == data)
        return level;
 
    int down_lv = getLevelUtil(node->left,data,level+1);
    
    if (down_lv != 0)
        return down_lv;
 
    down_lv = getLevelUtil(node->right,data,level + 1);
    
    return down_lv;
}

/*
***************************************************************************
***************************************************************************
INPUT: Nodo da analizzare e il valore di cui cerchiamo il livello
OUTPUT: livello
ALGORITMO: effettua una chiamata ad una funzione di util
***************************************************************************
***************************************************************************
*/
template <typename T>  int bintree<T>::getLevel(Node<T> *node, T data)
{
    return getLevelUtil(node, data, 1);
}

/*
***************************************************************************
***************************************************************************
INPUT: null (bintree)
OUTPUT: void
ALGORITMO: Visita l'abero e stampa gli elementi, contanto il numero di nodi
***************************************************************************
***************************************************************************
*/
template <typename T> void bintree<T>::printTree()
{
	queue<Node<T>*> q;
	q.push(root);
	int nodes = 0;
	int lv = 1;
	int lv_counter = 2;
	
	while(!q.empty())
	{
		Node<T> *temp = q.front();
		q.pop();
		if(temp->left != NULL)
		{
			q.push(temp->left);
			nodes++;
		}
		if(temp->right != NULL)
		{
			q.push(temp->right);
			nodes++;
		}
		
		cout << temp->key << endl;
	
		
	}
}

/*
***************************************************************************
***************************************************************************
INPUT: bintree
OUTPUT: int, numero di foglie
ALGORITMO: visità l'albero finchè non trova dei nodi senza figli
***************************************************************************
***************************************************************************
*/
template <typename T> int bintree<T>::getLeafs()
{
	queue<Node<T>*> q;
	q.push(root);
	int count=0;
	
	while(!q.empty())
	{
		Node<T> *temp = q.front();
		q.pop();
		if(temp->left != NULL)
		{
			q.push(temp->left);
		}
		if(temp->right != NULL)
		{
			q.push(temp->right);
		}
		if((temp->right == NULL) && (temp->left == NULL))
		{
			count++;
		}
		
	}
	return count;
	
}

/*
***************************************************************************
***************************************************************************
INPUT: bintree
OUTPUT: Nodo radice
ALGORITMO: ritorna la variabile privata della classe
***************************************************************************
***************************************************************************
*/
template <typename T> Node<T>* bintree<T>::getRoot()
{
	return root;
}

/*
***************************************************************************
***************************************************************************
INPUT: Nodo root, chiave da cercare
OUTPUT: Nodo ricercato / null
SCOPO: Cercare un nodo all'interno dell'albero
***************************************************************************
***************************************************************************
*/
template <typename T> Node<T>* bintree<T>::search(T key)
{
	queue<Node<T>*>q;
	q.push(root);
	Node<T>* temp = NULL;
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp->left != NULL)
		{
			if(temp->left->key == key)
			{
				cout << "found" << endl;
				return temp->left;
			}
			else
			{
				q.push(temp->left);
			}
		
		}
		if(temp->right != NULL)
		{
			if(temp->right->key == key)
			{
				cout << "found" << endl;
				return temp->right;
			}
			else
			{
				q.push(temp->right);
			}
		}
	}
	
	cout << "nothing found" << endl;
	
}

/*
***************************************************************************
***************************************************************************
INPUT: Chiave del nodo (type typename)
OUTPUT: void
ALGO: cancella il nodo avente come chiave "key". Il funzionamento è il seguente: cerca il nodo 
da cancellare e lo elimina, sostituendolo con il nodo più a destra e più profondo.
***************************************************************************
***************************************************************************
*/
template <typename T> void bintree<T>::deleteNode(T key)
{
	Node<T> *nodeToDelete = search(key); //nodo da eliminare
	queue<Node<T>*> q;
	q.push(root);
	
	//temp alla fine contiene il nodo più a destra
	Node<T> *temp;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp->left != NULL)
		{
			q.push(temp->left);
		}
		if(temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
	
	//qui sto cercando il nodo più profondo, a destra. Potrei applicare astrazione funzionale!!
	T keyAtDeepestRight = temp->key;
	queue<Node<T>*> q2;
	q2.push(root);
	Node<T> *temp2;
	while(!q2.empty())
	{
		temp2 = q2.front();
		q2.pop();
		if(temp2->left != NULL)
		{
			if(temp2->left == temp)
			{
				temp2->left = NULL;
				return;
			}
			
		}
		
		if(temp2->right != NULL)
		{
			if(temp2->right == temp)
			{
				temp2->right = NULL;
				return;
			}
			
		}
		
		
	}
	
	nodeToDelete->key = keyAtDeepestRight;
	
}
