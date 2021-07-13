#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class T>
struct Node
{
   	T info;
   	Node<T>* link;
};
template <class T>
Node<T>* createForwardList()
{
  Node<T>  *head,*current,*last;
  T num;
  cin>>num;
  head=NULL;
  while(num!=-99)
  {
    current=new Node<T>;
	current->info=num;
	current->link=NULL;
	if(head==NULL)
	{
	  head=last=current;  	
    }	
  	else
  	{
  	   last->link=current;
	   last=current; 
	}
	cin>>num;
  }
  return head;
} 
template <class T>
Node<T>* createBackwardList()
{
  Node<T>  *head,*current;
  T num;
  cin>>num;
  head=NULL;
  while(num!=-99)
  {
    current=new Node<T>;
	current->info=num;
	current->link=NULL;
  	current->link=head;
	head=current; 
	cin>>num;
  }
  return head;
} 

/*int main() 
{
	Node<int>*p;
	p=createForwardList<int>();
	  while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->link;
	}
	p=createBackwardList<int>();
	while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->link;
	}
	
	
	return 0;
}*/
