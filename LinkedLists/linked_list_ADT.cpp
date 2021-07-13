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
  protected:
    int count;
    struct Node<T> *head;
    struct Node<T> *last;

    public:
    LinkedList();
    bool emptyList();
    int lenght();
    Node<T>* search(T& val);
    void insertFirst(T& item);
    void insertLast(T& item);
    void deleteNode(T& item);
    void destroyList();
    void copyList(LinkedList<T> &);
    ~LinkedList();
    T front();
    T back();
    LinkedList<T>& operator=(const LinkedList &other); 
    template <class S>
    friend std::ostream & operator<<(std::ostream &os, const LinkedList<S> &list);
};

template <class T>
class OLinkedList : public LinkedList<T> /*inheritance is done*/
{
    public:
    	    OLinkedList();
    	    OLinkedList(const OLinkedList &other); 
            bool search(T&);
            void insert (T&);
            void deleteNode(T&);
            template <class s>
            friend std::ostream & operator<<(std::ostream &os, const OLinkedList<s> &list);
};
template <class T>
OLinkedList<T>::OLinkedList()
{
   LinkedList<T>::head=NULL;
   LinkedList<T>::last=NULL;
   LinkedList<T>::count=0;
}

template <class T>
OLinkedList<T>::OLinkedList(const OLinkedList &other) 
{
	LinkedList<T>::head = LinkedList<T>::last = NULL;
	Node<T> *p = other.head;

	while (p != NULL)
	{
		insertLast(p->data);
		p = p->link;
	}
	LinkedList<T>::count = other.LinkedList<T>::count;
}


template <class T>
std::ostream & operator<<(std::ostream &os, const OLinkedList<T> &list)
{
 	Node<T> *p = list.head;
        while(p!=NULL)
        {
             os<<p->info<<" ";
             p = p->link;
        }
        cout<<endl;
        return os;
}
template <class T>
bool  OLinkedList<T>::search(T& item)
 {
    Node<T> *p = NULL;

while(p!=NULL)
 {
 	if(p->info>=item)
 	{
 	   if(p->info==item)
		{
			return true;
		}
		else
		{
		 return false;	
		}	
	}
 	else
 	{
     p=p->link;
    }
 }
}

template <class T>
void  OLinkedList<T>::insert(T& item)
{
  Node<T>* p ,*q,*temp;
  temp=new Node<T>;
  temp->info=item;
  if(LinkedList<T>::head==NULL)
  {
  	temp->link=NULL;
  	LinkedList<T>::head=LinkedList<T>::last=temp;
  }
  else
  { 
    q=LinkedList<T>::head;
    while((q!=NULL)&&(q->info<item))
    {
      p=q;	
      q=q->link;    	
	}
	 if(q==LinkedList<T>::head)
	 {
	 	temp->link=LinkedList<T>::head;
	 	LinkedList<T>::head=temp;
	 	LinkedList<T>::count++;
	 }
  	else if(q!=NULL)
  	{ 
  	  p->link=temp;
  	  temp->link=q;
  	  LinkedList<T>::count++;
	}
	else /*adding at the end of the list*/
	 {
	   temp->link=NULL;	
	   LinkedList<T>::last->link=temp;
	   LinkedList<T>::last=temp; 
	   LinkedList<T>::count++;
	 }	
   }
}

template <class T>
void  OLinkedList<T>:: deleteNode(T &item)
{
  Node<T> *p = LinkedList<T>::head;
  Node<T> *q;

  if(LinkedList<T>::count==0)/*list is empty*/
   {
   	cout<<"List is empty"<<endl;
	 return;
   }

   while((p!=NULL)&&(p->info<item))
   {
	  q=p;
	  p = p->link;
   }
    
   if(p!=NULL)
   {
   	if(p->info==item)
   	{ 
     if(p==LinkedList<T>::head)
      {
	    LinkedList<T>::head=LinkedList<T>::head->link;
	    if(LinkedList<T>::head==NULL)/*only head node exists*/
	      LinkedList<T>::last=NULL;
	    delete p;
      }
     else
	  {
		 q->link = p->link;
		 if(p==LinkedList<T>::last)
		     LinkedList<T>::last=q;
	     delete p;
      }
      LinkedList<T>::count--;
     }
   else /*case of reaching node>item*/
    {
   	  cout<<"Node is not in the list"<<endl;
    }
  }
   else 
   {
	 cout<<"Node is not in the list"<<endl;
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
    assert(head!=NULL);
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
 if(p->info==val)
 {
   return p;
 }
 else
 {
 	cout<<"Element Not found"<<endl;
 }
}

template <class T>
void LinkedList<T>:: insertFirst(T& item)
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
void LinkedList<T>::insertLast(T& item)
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
std::ostream & operator<<(std::ostream &os, const LinkedList<T> &list)
{
        Node<T> *p = list.head;
        while(p!=NULL)
        {
             os<<p->info<<" ";
             p = p->link;
        }
        cout<<endl;
        return os;
}

template <class T>
void LinkedList<T>:: deleteNode(T& item)
{
  Node<T> *p = head;
  Node<T> *q;

  if(count==0)/*list is empty*/
   {
   	cout<<"List is empty"<<endl;
	 return;
   }

  while((p!=NULL)&&(p->info!=item))
   {
	  q=p;
	  p = p->link;
   }
   if(p!=NULL)
   {
   	if(p->info==item)
   	{
	    q->link = p->link;
	    delete p;
     if(p==head)
      {
	    head=head->link;
	    if(head=NULL)
	       last=NULL;
	      delete p;
      }
     else
	  {
		 q->link = p->link;
		 if(p==last)
		      last=q;
	     delete p;
      }
      LinkedList<T>::count--;
     }
  }
	   else 
	   {
		 cout<<"Node is not in the list"<<endl;
	   } 
};

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &other) 
{
	destroyList();
	
	if (other.count == 0)
		return *this;

	Node<T> *p = other.head;
	while(p != NULL){
		insertLast(p->data);
		p = p->next;
	}
	return *this;
}

template <class T>
void reversePrint(Node<T> *p)
{
	if(p!=NULL){
	reversePrint(p->link);//recursive call
	cout << p->info << endl;
 }
}

 int main()
{	
	LinkedList<int> myList;
	LinkedList<int> myList1;
//	OLinkedList<int> my_O_List;
	int arr[10]={1,2,3,4,5,7,8,9,10};
	int num;
//		for(int i=0 ;i<10;i++)
//	{
//		my_O_List.insert(arr[i]);
//	}
//    cout<<my_O_List;
//	num=6;
//	my_O_List.insert(num);
//	num=3;
//	my_O_List.deleteNode(num);
//	cout<<my_O_List;
	
	for(int i=0 ;i<10;i++)
	{
		myList.insertFirst(arr[i]);
	}
	cout<<myList;
    for(int i=0 ;i<10;i++)
	{
	 	myList1.insertLast(arr[i]);
    }
    num=8;
    myList1.deleteNode(num);
    cout<<myList1;
  	int x=myList.lenght();
  	cout<<x;
    Node<int>* ptr;
    num=7;
    ptr = myList.search(num);	
    return 0;	
}
