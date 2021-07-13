/*
 * StackWithLinkedList.h
 *
 *  Created on: 2 May 2021
 *      Author: Aly
 */

#ifndef STACKWITHLINKEDLIST_H_
#define STACKWITHLINKEDLIST_H_

template <class T>


struct node
{
    T info;
	node<T> *link;
};

template <class T>
class LinkedStack
{
public:
	  node<T>* stack_top;
	  LinkedStack();
	  bool isEmptyStack() const;
	  void initializeStack();
	  void push(const T& newItem);
	  T top() const;
	  T pop();
	  void copyStack(const LinkedStack<T>& stack);
	  ~LinkedStack();
};
//template <class T>
//LinkedStack<T>::~LinkedStack();




#endif /* STACKWITHLINKEDLIST_H_ */
