/*
 * StackWithLinkedList.cpp
 *
 *  Created on: 1 May 2021
 *      Author: Aly
 */
#include <iostream>

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

using namespace std;



template <class T>
LinkedStack<T>::LinkedStack()
{
 stack_top=NULL;
}

template <class T>
bool LinkedStack<T>::isEmptyStack() const
{
	return (stack_top==NULL);
}

template <class T>
void LinkedStack<T>::initializeStack()
{
  node<T>* temp;
    while(stack_top!=NULL)
    {
    	temp=stack_top;
    	stack_top=stack_top->link;
    	delete temp;
    }
}

template <class T>
T LinkedStack<T>::pop()
{
	node<T>* temp;
	T data;
  if(stack_top!=NULL)
  {
    temp=stack_top;
    stack_top=stack_top->link;
    data=temp->info;
    delete temp;
    return data;
  }
  else
  {
	  stack_top=NULL;
	  cout << "Cannot remove from an empty stack." << endl;
  }
}
template <class T>
void LinkedStack<T>:: push(const T& newItem)
{
	if(stack_top==NULL)
	{
		stack_top= new node<T>;
		stack_top->info=newItem;
		stack_top->link=NULL;
	}
	else
	{
	node<T>* temp= new node<T>;
	temp->info=newItem;
	temp->link = stack_top;
	stack_top=temp;
	}
}
template <class T>
void LinkedStack<T>::copyStack(const LinkedStack<T>& otherstack)
{
	node<T>* temp1;
	node<T>* temp2=otherstack.stack_top;
	node<T>* temp3;

	if(stack_top!=NULL)
	{
		initializeStack();
	}

	if(otherstack.stack_top==NULL)
	{
		stack_top=NULL;
	}
	else
	{
		stack_top=new node<T>;
		temp1=stack_top;
		temp1->info=temp2->info;
		temp2=temp2->link;
		while(temp2!=NULL)
		{
			temp3= new node<T>;
			temp3->info=temp2->info;
		    temp3->link=NULL;
			temp1->link=temp3;
			temp1=temp3;
			temp2=temp2->link;
		}
	}
}
template <class T>
LinkedStack<T>::~LinkedStack()
{
	initializeStack();
}

int main()
{
	LinkedStack<int> grades,st;
	int marks[10]={50,49,50,60,70,70,70,70,60,30};
	int max;
	max=marks[0];
	for(int i=0; i<10;i++)
	{
		if(marks[i]>max)
		{
		  max=marks[i];
		  grades.initializeStack();
		  grades.push(marks[i]);
	    }
		else if(marks[i]==max)
		{
			grades.push(marks[i]);
		}
	}
//     while(!grades.isEmptyStack())
//       {
//    	 cout<<grades.pop()<<endl;
//        }
	st.copyStack(grades);
	int j=0;
	 while(!st.isEmptyStack())
	    {
//		     if(j==4)
//		    	 st.stack_top=NULL;
	    	 cout<<st.pop()<<endl;
//	    	 j++;
	    }
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
