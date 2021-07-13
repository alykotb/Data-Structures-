///============================================================================
// Name        : Queue.cpp
// Author      : aly
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"
using namespace std;

template<class T>
class queueADT
{
public:
  virtual bool isEmptyQueue() const =0;
  virtual bool isFullQueue() const = 0;
  virtual void initializeQueue() = 0;
  virtual T front() const = 0;
  virtual T back() const = 0;
  virtual void addQueue(const T& queueElement) = 0;
  virtual void deleteQueue() = 0;
};

template <class T>
class QueueASArray: public queueADT<T>
{
private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of
	//elements in the queue
	int queueFront; //variable to point to the first
	//element of the queue
	int queueRear; //variable to point to the last
	//element of the queue
	T *list; //pointer to the array
public:
	const QueueASArray<T>& operator=(const QueueASArray<T>&);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	T front() const;
	T back() const;
    void addQueue(const T& queueElement);
	void deleteQueue();
	QueueASArray(int queueSize = 100);
	//Constructor
	QueueASArray(const QueueASArray<T>& otherQueue);
	//Copy constructor
   ~QueueASArray();
	//Destructor
};
template <class T>
const QueueASArray<T>& QueueASArray<T>::operator=(const QueueASArray<T>&otherQueue)
{
	  this->maxQueueSize = otherQueue.maxQueueSize;
	  this->queueFront=otherQueue.queueFront ;
	  this->queueRear = otherQueue.queueRear;
      this->count = otherQueue.count;
	  if(otherQueue.count==0)
	  {	 	
	     
	     
	  }
	  else
	 {
	   int front=otherQueue.queueFront;
	   int rear=otherQueue.queueRear;
	   this->list[front]=otherQueue.list[front];
	   while(front!=rear)
	   {
	   	 front=(front+1)%maxQueueSize;
	     this->list[front]=otherQueue.list[front];	
	   }	
	 } 
	return *this;
}
template <class T>
QueueASArray<T>::QueueASArray(const QueueASArray<T>& otherQueue )
{
		maxQueueSize = otherQueue.maxQueueSize;
	    queueFront =otherQueue.queueFront ;
	    queueRear = otherQueue.queueRear;
        count = otherQueue.count;
        list = new T[maxQueueSize];
	if(otherQueue.count==0)
	{	 	
	
	}
	else
	{
	   int front=otherQueue.queueFront;
	   int rear=otherQueue.queueRear;
	   list[front]=otherQueue.list[front];
	   while(front!=rear)
	   {
	   	 front=(front+1)%maxQueueSize;
	     list[front]=otherQueue.list[front];	
	   }	
	} 
}

template <class T>
QueueASArray<T>::QueueASArray(int queueSize )
{
	list = new T[queueSize];
	maxQueueSize = queueSize;
	queueFront = 0;
	queueRear = maxQueueSize - 1;
    count = 0;
}
template <class T>
QueueASArray<T>::~QueueASArray()
{
	delete [] list;
}

template <class T>
bool QueueASArray<T>::isEmptyQueue() const
{
return (count == 0);
} //end isEmptyQueue
template <class T>
bool QueueASArray<T>::isFullQueue() const
{
return (count == maxQueueSize);
}
template <class T>
void QueueASArray<T>::initializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}
template <class T>
void QueueASArray<T>::addQueue(const T& queueElement)
{
	if(!isFullQueue())
   {
    queueRear=(queueRear+1)%maxQueueSize;
	count++;
	list[queueRear]=queueElement;
   }
	else
	{
		cout<<"Queue is full"<<endl;
	}
}
template <class T>
void  QueueASArray<T>:: deleteQueue()
{
	if (!isEmptyQueue())
	{
	 count--;
	 queueFront = (queueFront + 1) % maxQueueSize; 
	//use the
	//mod operator to advance queueFront
	//because the array is circular
	}
	else
	{
	cout << "Cannot remove from an empty queue" << endl;
	}
}

template <class T>
T QueueASArray<T>::front() const
{
assert(!isEmptyQueue());
return list[queueFront];
} //end front

template <class T>
T QueueASArray<T>::back() const
{
assert(!isEmptyQueue());
return list[queueRear];
} //end front






int main()
{
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	QueueASArray<int> Q1(10);
	QueueASArray<int> Q2(50);
	for (int i=0;i<10;i++)
	{
	    Q1.addQueue(array[i]);
	} 
	Q2=Q1;
	QueueASArray<int> Q3(Q2);
	while(!Q2.isEmptyQueue())
	{
	   cout<<Q2.front()<<endl;
	   Q2.deleteQueue();
	}
	 while(!Q3.isEmptyQueue())
	{
	   cout<<Q3.front()<<endl;
	   Q3.deleteQueue();
	}
	
	while(!Q1.isEmptyQueue())
	{
	   cout<<Q1.front()<<endl;
	   Q1.deleteQueue();
	}
	if(Q1.isFullQueue())
	{
	   int x=3;
	   x++;	
	}
	Q1.initializeQueue();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}