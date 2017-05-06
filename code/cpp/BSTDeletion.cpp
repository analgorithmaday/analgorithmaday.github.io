 
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
 
BST* bst_search(BST* tree, int key)
{
    BST* skey = NULL;
    while(tree != NULL)
    {
        skey = tree;
        if(tree->data == key)
            return skey;
        else {
            if(key < tree->data)
                tree = tree->left;
            else
                tree = tree->right;
        }
    }
    return skey;
}
 
// left most is MIN
BST* min(BST* root)
{
    BST* minnode=NULL;
    while(root != NULL) {
        minnode = root;
        root = root->left;
    }
 
    return minnode;
}
 
BST* find_successor(BST* root)
{
    if(root == NULL) return NULL;
 
    // min of right subtree
    if(root->right != NULL) return min(root->right);
 
    // ancestor of node without right subtree
    BST* ancestor = root->parent;
    while(ancestor != NULL && ancestor->right == root)
    {
        root = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}
 
void bst_delete(BST*& tree,BST* node)
{
    // Case 1: node has no children = remove
    // Case 2: node has 1 children = move right or left, ignore node
    // Case 3: node has 2 children = find the successor and swap content
    BST* y = NULL;
    BST* x = NULL;
 
    // Case 3: both nodes present, find successor
    if(node->left != NULL && node->right != NULL)
        y = find_successor(node);
    else
        y = node;
 
    // Case 2, check for right or left node
    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;
 
    // Case 1 & 2: ignore node
    // Case 3: ignore successor
    if(x != NULL)
        x->parent = y->parent;
    
    if(y->parent == NULL) {
        // this means this is the root node DELETION!!
        tree = y;
    } else {
        // now change the y's parent node left & right pointers
        if( y == y->parent->left) {
            // y is the left node of parent then
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    }
 
    // Case 1 & Case 2: y is always equal to node
    // Case 3: y = successor(node) 
    // Case 3: pending thing, swap content between node & y
    if(y != node) {
        node->data = y->data;
        // we can ignore left, right, parent
        // as successor is greater than left and lesser than right
    }
    free(y);
}
 
void main()
{
    int A[]={1,2,3,4,5,6,6,7,8};
    BST* sort = convert_array_bst(A, 9);
    BST* del = bst_search(sort, 6);
    bst_delete(sort, del);
    del = bst_search(sort, 6);
    bst_delete(sort, del);
 
}
