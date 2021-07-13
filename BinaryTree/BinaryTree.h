#include<iostream>
using namespace std;


template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType>* l_link;
	binaryTreeNode<elemType>* r_link;
};
template<class elemType>
class binaryTreeType
{
	protected:
           binaryTreeNode<elemType> *root;
    private:
    	/*because we need to call them recursively with the paramtet root in the public functions called by the user*/
   	      void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,binaryTreeNode<elemType>*otherTreeRoot);
   	      void destroy(binaryTreeNode<elemType> &p);
   	      void inorder(binaryTreeNode<elemType> *p) const;
   	      void preorder(binaryTreeNode<elemType> *p) const;
   	      void postorder(binaryTreeNode<elemType> *p) const;
   	      int  height(binaryTreeNode<elemType> *p) const;
		  int  nodeCount(binaryTreeNode<elemType> *p) const;
		  int  leavesCount(binaryTreeNode<elemType> *p) const;
		  int max(int x, int y) const;
	public:
		  binaryTreeType();
		  binaryTreeType(const binaryTreeType<elemType>& otherTree);
		  const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
		  bool isEmpty() const;
		  void inorderTraversal() const;
		  void preorderTraversal() const;
		  void postorderTraversal() const;
		  int treeHeight() const;
		  int treeNodeCount() const;
		  int treeLeavesCount() const;
		  void destroyTree();
		  ~binaryTreeType();
}; 





