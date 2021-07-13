#include <iostream>
#include <assert.h>
#include "linked_list.h"

using namespace std;
 
static struct Node *last_element;

struct Node * Add_at_Begin(struct Node *head)
{
    struct Node *temp;

    temp= new Node;
    assert (temp!=NULL);
    
    if(head==NULL) /*here is a check if the linked list is empty*/
    {
        head=temp;
        head->link=NULL;
        last_element=head;
    }

    else
    {
        temp->link=head;
        head=temp;
    }
    return head;
}

struct Node * Add_at_end()
{
    struct Node *temp;
    temp= new Node;
    assert (temp!=NULL);
    
    if(last_element==NULL) /*here is a check if the linked list is empty*/
    {
        last_element=temp;
        last_element->link=NULL;
    }

    else
    {
        last_element->link= temp;
        last_element= temp;
        last_element->link=NULL;
    }
    return last_element;
}

struct Node * Add_Element_at_Position(struct Node *head ,int position)
{
/*	if (idx > count){
//		cout << "Given index is greater than the number of element, so appending to list"<<endl;
		insertLast(val);
	}
	else if (idx <= 1){
//		cout << "Given index value is less than or equal to 1, so inserting as the first element"<<endl;
		insertFirst(val);
	}*/
    struct Node *temp;
    int i=0;
    while(i<(position-1))
    {
        head=head->link;
        i++;
    }

    temp= new Node;
    temp=head->link;
    head->link=temp;

    return temp;
}

struct Node* Search_element(struct Node* head, int data)
{
 
 while((head!=NULL) && (head->info!= data))
  {
    head=head->link;
  }
if(head!=NULL)
  { 
     return head;
  }
 else
  {
  	cout<<"was not found"<<endl;
    return NULL;
  }
}

bool Delete_Node(struct Node *head,int info)
{
    struct Node *p;
while((head!=NULL) && (head->info!= info))
{
  p=head;  
  head=head->link;
}

if(head!=NULL)
{
   p->link=head->link;
   delete head;
   return true;
}
else
 {
   return false;

 }
}
void print_list_elements(struct Node *head)
 {
    while(head!=NULL)
    {
        cout << head->info;
        head = head->link;
    }
      cout << endl;
 }
/*int main()
{	
	LinkedList<int> myList;
	LinkedList<int> myList1;
	OLinkedList<int> my_O_List;
	int arr[10]={1,2,3,4,5,7,8,9,10};
	int num;
	for(int i=0 ;i<10;i++)
	{
	   my_O_List.insert(arr[i]);
	}
    cout<<my_O_List;
	num=6;
	my_O_List.insert(num);
	num=0;
	my_O_List.deleteNode(num);
	cout<<my_O_List;
	
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
}*/
