struct BinaryTree 
{
    int data;
    BinaryTree* left;
    BinaryTree* right;
};
 
BinaryTree* newTreeNode(int data)
{
    BinaryTree* newNode = new BinaryTree;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    return newNode;
}
 
int getIndex(int* arr, int val, int size)
{
    for(int i=0; i<size;i++) {
        if(arr[i] == val) 
            return i;
    }
    return -1;
}
 
 
 
BinaryTree* create_bintree(int* parray, int* iarray, int size)
{
    if(size == 0) return NULL;
 
    int rootVal = parray[0];
    BinaryTree* root  = newTreeNode(rootVal);
    int newIdx = getIndex(iarray, rootVal, size);
    root->left = create_bintree(parray+1, iarray, newIdx);
    root->right = create_bintree(parray+newIdx+1, iarray+newIdx+1, size-newIdx-1);
    return root;            
}
void main()
{
    int preorder[] = {7,10,4,3,1,2,8,11};
    int inorder[] = {4,10,3,1,7,11,8,2};
 
    BinaryTree* tree = create_bintree(preorder, inorder, 8);
 
}
