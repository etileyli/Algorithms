#include <iostream>
using namespace std;

struct TreeNode{
  int data;
  struct TreeNode* firstChild;
  struct TreeNode* nextSibling;
};

struct BinaryNode{
  int data;
  struct BinaryNode* leftChild;
  struct BinaryNode* rightChild;
};

void preorder(struct BinaryNode* p){
  if (p !=NULL) {
		cout << p->data << endl;
		preorder(p->leftChild);
		preorder(p->rightChild);
  }
}

void inorder(struct BinaryNode* p){
	if (p !=NULL) {
  	inorder(p->leftChild);
  	cout << p->data << endl;
  	inorder(p->rightChild);
  }
}

void postorder(struct BinaryNode* p){
	if (p !=NULL) {
		postorder(p->leftChild);
		postorder(p->rightChild);
		cout << p->data << endl;
  }
}

int FindMax(struct BinaryNode* p)
{
     int root_val, left, right, max;
     max = -1; // Assuming all values are positive integers

     if (p!=NULL) {
       root_val = p->data;
       left = FindMax(p->leftChild);
       right = FindMax(p->rightChild);

       // Find the largest of the three values.
       if (left > right)
            max = left;
       else
           max = right;
       if (root_val > max)
           max = root_val;
     }
     return max;
}

int add(struct BinaryNode* p){
   if (p == NULL)
      return 0;
   else
      return (p->data + add(p->leftChild)+add(p->rightChild));
}
