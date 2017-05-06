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
        if(node->data > iter->data)
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
        if(node->data > prev->data)
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
 
void main()
{
    BST *tree, *tmp;
    int k = 6;
    bool found = false;
    int arr[]= {2,30,12,10,22,6};
    tree = convert_arr_bst(arr, 6);
    tmp = tree;
    while(tmp && !found)
    {
        if(tmp->data == k) found = true;
        if(tmp->data < k) tmp = tmp->left;
        else {
            tmp = tmp->right;
        }
    }
    if(found == true)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
}
