/* LinkedQueue.cpp
   Created on: 4 May 2021
     Author: Aly
 */
#include <iostream>
using namespace std;

template<class T>
class queueADT
{
public:
  virtual bool isEmptyQueue() const =0;
  virtual bool isFullQueue() const = 0;
  virtual void initializeQueue() = 0;
  virtual T front() const = 0;
//  virtual T back() const = 0;
  virtual void addQueue(const T& queueElement) = 0;
  virtual void deleteQueue() = 0;
};
template<class T>
struct node
{
	T info;
	node<T>* link;
};
template<class T>
class linkedQueue: public queueADT<T>
{
private:
	 node<T>* queueFront;
	 node<T>* queueRear;
	int count;
public:
	const linkedQueue<T>& operator=(const linkedQueue<T>&);
	bool  isEmptyQueue() const;
	bool  isFullQueue() const;
	void  initializeQueue();
	T front() const;
//	T back() const;
    void addQueue(const T& queueElement);
	void deleteQueue();
	T remove(); //Delete, serve, remove,dequeue, pop
	int size() const;
	linkedQueue();
	//Default constructor
	linkedQueue(const linkedQueue<T>& otherQueue);
	//Copy constructor
	~linkedQueue();
	//Destructor
};

template <class T>
T linkedQueue<T>::remove()
{
	T temp = queueFront->info;
	node<T> *p = queueFront;
	queueFront = queueFront->link;
	if(queueFront==NULL)
		queueRear=queueFront;
	delete p;
	count--;
	return temp;
}
template <class T>
linkedQueue<T>::~linkedQueue()
{
	deleteQueue();
}

template <class T>
linkedQueue<T>::linkedQueue()
{
	queueFront = NULL; //set front to null
	queueRear  = NULL; //set rear to null
	count=0;
}
template <class T>
linkedQueue<T>::linkedQueue(const linkedQueue<T>& otherQueue)
{
  queueFront = queueRear = NULL;
  count = 0;
  node<T> *otherQueue_ptr = otherQueue.queueFront;
	while (otherQueue_ptr != NULL)
	{
		addQueue(otherQueue_ptr->info);
		otherQueue_ptr = otherQueue_ptr->link;
	}
}
template <class T>
const linkedQueue<T>& linkedQueue<T>::operator=(const linkedQueue<T>& other)
{
   initializeQueue();
	if (other.count == 0)
		return *this;
    
	node<T> *p = other.queueFront;
	while(p != NULL){
		addQueue(p->info);
		p = p->link;
	}
	return *this;
 }	


template <class T>
bool linkedQueue<T>::isEmptyQueue() const
{
 return(queueFront==NULL);
}
template <class T>
bool linkedQueue<T>::isFullQueue() const
{/*always returns false because queue is never full*/
 return false;/*must provide its definition because it is included as
                an abstract function in the parent class queueADT*/
}

template <class T>
void linkedQueue<T>::initializeQueue()
{
	node<T>* temp;
    while(queueFront!=NULL)
    {
    	temp=queueFront;
    	queueFront=queueFront->link;
    	delete temp;
    }
    queueRear=NULL;
    count=0;
}

template <class T>
void linkedQueue<T>::addQueue(const T& newElement)
{
	node<T>* temp;
	temp= new  node<T>;
	temp->info=newElement;
	temp->link=NULL;;
	if(!isEmptyQueue())
	{
		queueRear->link=temp;
		queueRear=queueRear->link;
	}
	else
	{
		queueRear=queueFront=temp;
	}
     count++;
}

template <class T>
int linkedQueue<T>::size() const{
	return count;
}

template <class T>
void linkedQueue<T>::deleteQueue()
{
	if(isEmptyQueue())
	{
		cout<<"Queue is Empty"<<endl;
	}
	else if(queueFront==queueRear)
	{
		delete queueFront;
		queueFront=queueRear=NULL;
	}
	else
	{
	 node<T>* temp;
	 temp = queueFront;
	 queueFront=queueFront->link;
	 delete temp;
	 temp=NULL;
    }
}
template <class T>
T linkedQueue<T>::front() const
{
  /* if the queue is empty the program is terminated*/
  return queueFront->info;
}

int main()
{
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	linkedQueue<int> Q1;
	linkedQueue<int> Q2;
	for (int i=0;i<10;i++)
	{
	    Q1.addQueue(array[i]);
	} 
	Q2=Q1;
	linkedQueue<int> Q3(Q2);
	Q1.initializeQueue();
	while(!Q2.isEmptyQueue())
	{
	   cout<<Q2.remove()<<endl;
	 
	}
	 while(!Q3.isEmptyQueue())
	{
	   cout<<Q3.remove()<<endl;
	
	}
	
	while(!Q1.isEmptyQueue())
	{
	   cout<<Q1.remove()<<endl;
	}
	if(Q1.isFullQueue())
	{
	   int x=3;
	   x++;	
	}
	Q1.initializeQueue();
	return 0;
}




