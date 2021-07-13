/*
 * StackWithArray.h
 *
 *  Created on: 28 Apr 2021
 *      Author: Aly
 */

#ifndef STACKWITHARRAY_H_
#define STACKWITHARRAY_H_


template <class T>
class Stack
{
protected:
T *arr ;//array hold elements
int Stacktop;//index of empty space after topmost element
int size;//size of array

public:
Stack(int stack_size);
Stack();
bool isEmpty();
bool isFull();
void destroy();
void push(T &);
void copy(Stack<T> &);
T pop();
T top();//retrieve top element
~Stack();
};


#endif /* STACKWITHARRAY_H_ */
