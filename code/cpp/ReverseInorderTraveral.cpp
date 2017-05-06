#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <iostream>
 
class BST {
public:
    int data;
    BST* parent;
    BST* left;
    BST* right;
};
 
 
BST* createBSTNode(int data)
{
    BST* newNode = new BST();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}
 
void bst_insert(BST*& tree, BST* node)
{
    BST* prev = NULL;
    BST* iter=tree;
    while(iter != NULL)
    {
        prev = iter;
        if(node->data < iter->data)
            iter = iter->left;
        else
            iter = iter->right;
    }
    // found node is parent to our node
    node->parent = prev;
 
    // if prev is NULL
    // then this is the first node
    // change the root NODE
    if(prev == NULL)
        tree = node;
    else {
        // now we need to decide where the node
        // should go: left or right
        if(node->data < prev->data)
            prev->left = node;
        else
            prev->right = node;
    }
 
}
 
BST* convert_arr_bst(int* arr, int size)
{
    BST* tree=NULL;
    for(int i=0;i<size;i++) {
        bst_insert(tree, createBSTNode(arr[i]));
    }
    return tree;
}
 
void ascending(BST* root)
{
    if(root == NULL) return;
    ascending(root->left);
    std::cout<<root->data<<" ";
    ascending(root->right);
}
 
void descending(BST* root)
{
    if(root == NULL) return;
    descending(root->right);
    std::cout<<root->data<<" ";
    descending(root->left);
}
 
 
void main()
{
    int A[] = {4,5,3,2,8,10,1,2};
    BST* root = convert_arr_bst(A, sizeof(A)/sizeof(int));
    ascending(root);
    std::cout<<std::endl;
    descending(root);
    std::cout<<std::endl;
}
