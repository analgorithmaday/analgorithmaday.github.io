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
 
BST* convert_array_bst(int* arr, int size)
{
    BST* tree=NULL;
    for(int i=0;i<size;i++) {
        bst_insert(tree, createBSTNode(arr[i]));
    }
    return tree;
}
 
void main()
{
    int A[]={6,2,3,9,1,3,6,2,4};
    BST* sort = convert_array_bst(A, 9);
}
