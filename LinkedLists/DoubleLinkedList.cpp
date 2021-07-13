#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T info;
    Node<T>* left,right;
    /* data */
};

template <class T>
class DoubleLinkedList
{
	protected:
	int count;
	Node<T> *first,last;
	private:
	void copyList( DoubleLinkedList<T> & );
	public:
	DoubleLinkedList () 
	{
	first=NULL;
	last=NULL;
	}
	~DoubleLinkedList();
	bool search(T &);
	void insertLast(T &);
	void insert(T &);
	void reverse();
	void deleteNode(T &) ;
};
//template <class T>
//bool DoubleLinkedList<T>::insertLast(T &item)
//{
//	
//}
	
	
template <class T>
void DoubleLinkedList<T>::deleteNode(T &item)
{
	
	
}

template <class T>
void DoubleLinkedList<T>::reverse()
{
  Node<T> *p= last;
	while(p!=NULL)
	 {
	cout << p->info;
	p=p->left;
	 }
}

template <class T>
void DoubleLinkedList<T>::insertLast(T &item )
{
	Node<T> *p= last;
	p->info = item;
	p->right=NULL;

 if(first!=NULL)
  {
    p->left=last;
    last->left=p;
    last=p;
  }
  else
  {
      first=last=p;
      p->left=NULL;
  }
}

template <class T>
void DoubleLinkedList<T>::insert(T &item)
{
	Node<T> *p= new Node<T>;    
	Node<T> *current= first;
	Node<T> *previous= NULL;
	p->info=item;
	
	if(first==NULL)
	{
	  first=p;
	  first->left=NULL;
	  first->right=NULL;
	}
  else
  {	
	while((current!=NULL)&&(current->info<item))
	 {
	     previous=current;
	     current=current->link;
	 }
	 if(current==first)
	   {
	     previous->right=p;
	     p->left=previous;
	     current->right=p;
	     current->left=NULL;
	   }
      else  if (current!=NULL)/*insetrion is in the middle*/
     {
        	  previous->right=p;
	          p->left=previous;
	          p->right=current;
	          current->left=p;      
      }
      else /*addition at end of list*/
      {
            last->left=p;
            p->right=NULL;
            p->left=last;
            last=p;
      }
    }
}

/*int main()
{
	
	
	
}*/
