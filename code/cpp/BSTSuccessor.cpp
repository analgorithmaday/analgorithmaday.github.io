int find_successor(BST* root)
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
    return ancestor->data;
}
