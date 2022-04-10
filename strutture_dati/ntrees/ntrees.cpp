
/***************************************************************************
 *   Alberi n-ari                                 						   *
 *   l.daddario@studenti.uniba.it (mat. 685195)                            *
 *                                                                         *
 *   Questo file contiene l'implementazione delle funzioni della classe    *
 *   ntrees, che rappresenta struttura dati degli alberi n-ari.	 	       *
 *        																   *
 *                                      								   *
 *                                                                         *
 ***************************************************************************/

#include <iostream>
#include "ntrees.h"

using namespace std;


/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Restituisce il numero di nodi al livello k in un generic tree
***************************************************************************
***************************************************************************
*/
template <typename T> int ntrees<T>::n_level(Node<T> *root, int k, <T> Tree);
{
	int num_nodi = 0;
	int s = root->child.size();
	for(int i=0;i<s;i++)
	{
		if(getLevel(root->child[i], root, Tree) == k)
			{
				num_nodi++;
			}
		else n_level(root->child[i],k,Tree);
	}
	
	return num_nodi;
}


/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Restituisce il livello del nodo in input, partendo dalla root
***************************************************************************
***************************************************************************
*/
template <typename T> int ntrees<T>::getLevel(Node<T> *node, Node<T> *root, ntrees<T> Tree)
{
	int s = root->child.size();
	int level = 0;
	
	if(root->key == node->key)
		return 1; //level 1
	
	for(int i=0;i<s;i++)
	{
		if(root->child[i]->key == node->key)
		{
			return 2; //level 2
		}
		int _s = root->child[i]->child.size();
		for(int j=0;j<_s;j++)
		{
			level++;
		}
		
	}
	return level;
}

/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Restituisce il numero di foglie 
***************************************************************************
***************************************************************************
*/
template <typename T> int ntrees<T>::n_leaf(Node<T> *root, ntrees<T> Tree)
{

	if(root->child.size() == 0)
		return 1;
	else
	{
		
	int i = root->child.size();
	for(int j=0;j<i;j++)
	{
		int s = root->child[j]->child.size();
		if(s == 0)
		{
			Tree.leaf++;
		}
		else if(s>0)
		{
			
			for(int k=0;k<s;k++)
			{
				int _s = root->child[j]->child[k]->child.size();
				if(_s == 0)
					Tree.leaf++;
			}
		}
		else n_leaf(root->child[j],Tree);
		//n_leaf(Tree);
	
	}
	return Tree.leaf;
		
	}
}


/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Inserisce un nuovo nodo nell'albero utilizzando T come parent
***************************************************************************
***************************************************************************
*/
template <typename T> void ntrees<T>::insertTree(Node<T> *root, T key, T parent)
{
	Node<T> *node = createNode(key);

	if(root->key == parent)
		root->child.push_back(node);

	else
	{
		int i = root->child.size();
		for(int j=0;j<i;j++)
		{
			if(root->child[j]->key == parent)
				insertTree(root->child[j], node->key, parent);
			else
				insertTree(root->child[j], node->key, parent);
		}  
	}
}

/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Ricerca una chiave 
***************************************************************************
***************************************************************************
*/
template <typename T> Node<T>* ntrees<T>::search(T key)
{

	Node<T> *out;
	if(root->key == key)
	{
		return root;
	}
	else
	{
		int i = root->child.size();
		for(int j=0;j<i;j++)
		{
			if(root->child[j]->key == key)
			{
				
				out = root->child[j];
				return out;
			}
			else search(key);
		}
	}
	
}

/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Ricerca del nodo con chiave "key" più a destra
***************************************************************************
***************************************************************************
*/
template <typename T> Node<T>* ntrees<T>::searchDeepestRight(T key)
{
	Node<T> *deepestRight = NULL;
	Node<T> *nodeToDelete = search(key);
	int size = root->child.size();
	for(int i=size;i=0;i--)
	{
		if(root->child[i]->key == key)
			{
				deepestRight->key = root->child[i]->key;
				nodeToDelete = deepestRight;
				root->child[i] = NULL;
				return deepestRight;
			}
		else searchDeepestRight(key);
	}
}

/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Ricerca del nodo più a destra
***************************************************************************
***************************************************************************
*/
template <typename T> Node<T>* ntrees::getDeepest(Node<T> *node)
{
	int i = root->child.size();
	for(int j=0;j<i;j++)
	{
		if(root->child[i]->child == NULL)
			{
				return root->child[j];
			}
		else getDeepest(root->child[j]);
	}
}


/*
***************************************************************************
***************************************************************************
INPUT:  
OUTPUT: 
ALGORITMO: Cancellazione di un nodo
***************************************************************************
***************************************************************************
*/
template <typename T> void ntrees<T>::deleteNode(T key)
{
	/*
		1) Trovo il nodo con la key = key
		2) cerco l'elemento più a destra dell'albero
		3) scambio
	*/
			
	Node<T> *nodeToDelete = search(key);
	Node<T> *deepest = getDeepest(getRoot());
	
	nodeToDelete = deepest;
	deepest = NULL;	

}
	
	

