
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

#ifndef LIST_H
#define LIST_H

		
template <typename T>
struct node {
		T data;
		node* next; //pointer to next
	};


template <class T>
class List{
	
	private:
		node<T> *head;
		node<T> *current;
		node<T> *temp;
		
	public:
		List();
		void AddNode(T addData);
		bool operator!=(List<T> &);
		int num_elements(T p1, T p2);
		node<T> *getNode(T el);
		void exchange(T p1, T p2);
		void move_min_max();
		T findMin(node<T> *node);
		T findMax(node<T> *head);
		node<T> *findEnd();
		void deleteNode(T delData);
		void PrintList();	
		int ListLenght();
		void reverse();
		node<T> *getHead()
		{
			return head;
		}
		void calculateEnd();
		bool isPalindrome();
		void getPrec();
	
};


#endif /* LIST_H */
