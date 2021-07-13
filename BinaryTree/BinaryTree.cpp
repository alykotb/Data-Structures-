#include <iostream>
#include "BinaryTree.h"

using namespace std;


template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root=NULL;
}
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType> &otherTree)/*copy constructor*/
{
  if(this!=&otherTree)
  {
	if(otherTree==NULL)
     {
       root=NULL;
	 }
	 else
	 {
	 	 copyTree(root,otherTree.root);
	 }
  }
}
template <class elemType>
void binaryTreeType<elemType>::copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,binaryTreeNode<elemType>* otherTreeRoot)
{

   if (otherTreeRoot == NULL)
       copiedTreeRoot = NULL;
     
   else
	{
	copiedTreeRoot = new binaryTreeNode<elemType>;
	copiedTreeRoot->info = otherTreeRoot->info;
	copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
	copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>&otherTree)
{
	if(this!=&otherTree)
	{
		if(root!=NULL)
		  destroy(root);
		if(otherTree.root==NULL)
		{
			root=NULL;
		}
		else
		{
			copyTree(root,otherTree.root);
		}	
	}
	return this;
}
template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return(root==NULL);
}
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
  inorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
	inorder(p->llink);
	cout << p->info << " ";
	inorder(p->rlink);
	}
}
template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
	cout << p->info << " ";
	preorder(p->llink);
	preorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
  preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
  postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
 return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	
  return leavesCount(root);
  
}
template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
   if (p == NULL)
     return 0;
   else
      return 1 + max(height(p->llink), height(p->rlink));
}
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
   if (x >= y)
	return x;
   else
	return y;
}
template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const
{
	int count=0;
  if(p!=NULL)
    return 0;
   else
     return 1+(p->l_link)+(p->r_link);	
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const
{
  if(p!=NULL)
  {
    return 0;
  }
  else if(!(p->l_link)&&(p->r_link))
   {
 	 return 0;  
   }  
   else
   {
     return 1+(p->l_link)+(p->r_link);		
   }
}

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>&p)
{
	 if(p!=NULL)
	{
		destory(p->l_link);
		destory(p->r_link);
		delete p;
	}
}
template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
  destroy(root);
}
template<class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}





