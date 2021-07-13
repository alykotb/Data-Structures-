/*
 * StackDerivedFromLinkedList.cpp
 *
 *  Created on: 2 May 2021
 *      Author: Aly
 */

#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T info;
    Node<T>* link;
    /* data */
};
template <class T>
class LinkedList
{
    private:
    int count;
    protected:
    struct Node<T> *head;
    struct Node<T> *last;
    LinkedList();
    bool emptyList();
    int lenght();
    Node<T>* search(T& val);
    void insertFirst(const T& item);
    void insertLast(const T& item);
    void deleteNode(T& item);
    void destroyList();
    void copyList(LinkedList<T> &);
    ~LinkedList();
    T front();
    T back();
    template <class S>
    friend std::ostream & operator<<(std::ostream &os, const LinkedList<S> &list);
};

template <class T>
class OLinkedList : public LinkedList<T> /*inheritance is done*/
{
    public:
            bool search(T&);
            void insert (T&);
            void  deleteNode(T&);
};

template <class T>
 bool  OLinkedList<T>::search(T& item)
 {
    Node<T> *p = NULL;
    bool found = false;

while((p!=NULL)&&(p->info!=item))
 {
    p=p->link;
 }

 if(p->info==item)
 {
      found = true;
      return found;
 }
    else
    {
        return found;
    }
 }


template <class T>
LinkedList<T>::LinkedList()
{
   head=NULL;
   last=NULL;
   count=0;
}
template <class T>
int LinkedList<T>:: lenght()
{
   return count;
}

template <class T>
void LinkedList<T>:: destroyList()
{
   Node<T> *p;

   while(head!=NULL)
   {
     p=head;
     head=head->link;
     delete  p;
   }

    count=0;
    last=NULL;
}
template <class T>
LinkedList<T>:: ~LinkedList()
{
    destroyList();
}
template <class T>
T LinkedList<T>:: front()
{
//    assert(head!=NULL);
    return head->info;

}
template <class T>
T LinkedList<T>:: back()
{
    assert(head!=NULL);
    return head->info;
}

template <class T>
Node<T>* LinkedList<T>::search(T& val)
{
 Node<T> *p = head;
 while((p!=NULL)&&(p->info!=val))
 {
    p=p->link;
 }
 return p;
}
template <class T>
void LinkedList<T>:: insertFirst(const T& item)
 {

Node<T> *p = new Node<T>;
p->info=item;
p->link =head;
head=p;
if(last==NULL)
{
    last=head;
}
count++;
}
template <class T>
void LinkedList<T>::insertLast(const T& item)
{
Node<T> *p = new Node<T>;
p->info=item;
p->link =NULL;
if(head!=NULL)
{
last->link=p;
last=p;
}
else
{
    head=last=p; /* right to lef associativity*/

}
 count++;
}

template <class T>
bool LinkedList<T>::emptyList()
{
return(head==NULL);
}

template <class T>
std::ostream & operator<<(std::ostream &os, const LinkedList<T> &list)
{
        Node<T> *p = list.head;
        while(p!=NULL)
        {
             os<<p->info<<" ";
             p = p->link;
        }
        return os;
}

template <class T>
void LinkedList<T>:: deleteNode(T& item)
{
  Node<T> *p = head;
  Node<T> *q;

  if(count==0)/*list is empty*/
    return;

 while((p!=NULL)&&(p->info!=item))
 {
    q=p;
    p = p->link;
 }

 if(p!=NULL)
{
    q->link = p->link;
    delete p;
}

else if(p==head)
{
    head=head->link;
    delete p;
}

 else
{
   /*Node is not in the list*/

}

};

template <class T>
class DerivedLinkedStack :public LinkedList<T>
{
public:
	    DerivedLinkedStack();
	    bool isEmpty();
	    void push(const T& data);
	    T showTop();
	    T pop();
	    ~DerivedLinkedStack();
};
template <class T>
DerivedLinkedStack<T>::DerivedLinkedStack()
{
}
template <class T>
DerivedLinkedStack<T>::~DerivedLinkedStack()
{

}
template <class T>
bool DerivedLinkedStack<T>::isEmpty()
{
   return LinkedList<T>::emptyList();
}
template <class T>
void DerivedLinkedStack<T>::push(const T& data)
{
	 LinkedList<T>::insertFirst(data);
}
template <class T>
T DerivedLinkedStack<T>::showTop()
{
  return LinkedList<T>::front();
}

template <class T>
T DerivedLinkedStack<T>:: pop()
{

	Node<T>* temp;
	T data;
  if(!isEmpty())
  {
    temp=LinkedList<T>::head;
    LinkedList<T>::head=LinkedList<T>::head->link;
    data=temp->info;
    delete temp;
  }
  else
  {

	  cout << "Cannot remove from an empty stack." << endl;
  }
return data;
}
//int main()
//{
//
//	DerivedLinkedStack<int> st;
//	int numbers[10]={50,49,50,60,70,70,70,70,60,30};
//	int i;
//	for(i=0;i<10;i++)
//	{
//	  st.push(numbers[i]);
//	}
//	int x=st.showTop();
//	cout<<x<<endl;
//
//	while(!st.isEmpty())
//	{
//       x=st.pop();
//       cout<<x;
//	}
//
//return 0;
//}
//


