/*
 * StackWithArray.cpp
 *
 *  Created on: 28 Apr 2021
 *      Author: Aly
 */
#include <iostream>

using namespace std;

#include "StackWithArray.h"

template <class T>
Stack<T>::~Stack()
{
  delete [] arr;
}

template <class T>
Stack<T>::Stack()
{	
  size=10;
  arr= new T[size];
  Stacktop=-1;/*no members yet in the stack*/
}
template <class T>
Stack<T>::Stack(int stack_size)
{
	Stacktop=-1;/*no members yet in the stack*/
	size=stack_size;
	arr= new T[size];
}
template <class T>
bool Stack<T>:: isEmpty()
{
	return(Stacktop==-1);/*if the Stacktop index is -1 then no member is in the stack*/
}
template <class T>
bool Stack<T>:: isFull()
{
	return(Stacktop==size-1);/*if the Stacktop index is the last element of the array  then no member is in the stack*/
}
template <class T>
void Stack<T>::destroy()
{
	delete [] arr;
	Stacktop=-1;
}
template <class T>
void Stack<T>::push(T&data)
{
	if(!isFull())
	{
		arr[++Stacktop] = data;
	}
	else
	{
		std::cout << "Stack Full" << endl;
	}
}
template <class T>
T Stack<T>::pop()
{
//	assert(!isEmpty ());
// If function evaluates to false, abort (FOR DEBUGGING)
return arr[Stacktop--];
}
template <class T>
void Stack<T>::copy(Stack<T> &st)
{
  delete[] arr; /* de-allocating the old stack*/
  size=st.size;
  top=st.top;
  arr = new T[size];
  for(int n = 0; n<Stacktop; n++)
  {
	  arr[n]=st.arr[n];
  }
}

/*int main()
{
	Stack<int> numbers(5);
	int x;
	int arr[5]={1,2,3,4,5};
	for (int i=0; i<5; i++)
	{
       numbers.push(arr[i]);
	}
	 while(!numbers.isEmpty())
		{
	       x=numbers.pop();
	       cout<<x;
		}
        cout<<endl;
	  cout << "!!!Hello World!!!" << endl;
	return 0;
}*/






















