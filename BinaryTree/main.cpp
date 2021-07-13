#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType>* l_link;
	binaryTreeNode<elemType>* r_link;
};
template <class elemType>
void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,binaryTreeNode<elemType>*otherTreeRoot)
{
	if(otherTreeRoot==NULL)
	{
	  copiedTreeRoot=NULL;
	}
	else
	{
		copiedTreeRoot= new binaryTreeNode<elemType>;
		copiedTreeRoot->info=otherTreeRoot->info;
		copyTree(copiedTreeRoot->l_link,otherTreeRoot->l_link);
		copyTree(copiedTreeRoot->r_link,otherTreeRoot->r_link);		
	}	
}
template <class elemType>
int heigth(binaryTreeNode<elemType>*p) 
{
	if(p=NULL)
	return 0;
	else 
	return max(height(p->l_link),height(p->r_link));
}
template <class elemType>
void inorder(binaryTreeNode<elemType>*p)
{
   if(p!=NULL)
   {
    inorder(p->l_link);
	cout<<p->info<<" ";
	inorder(p->r_link);
   }
}

template<class elemType>
void preorder(binaryTreeNode<elemType>*p)
{
	 if(p!=NULL)
   {
    inorder(p->l_link);
	cout<<p->info<<" ";
	inorder(p->r_link);
   }
}
template<class elemType>
void postorder(binaryTreeNode<elemType>*p)
{
	 if(p!=NULL)
   {
    inorder(p->l_link);
	inorder(p->r_link);
	cout<<p->info<<" ";
   }
}
int main() 
{
  	
	return 0;
}
