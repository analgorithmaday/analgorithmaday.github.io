Tree* mirror(Tree* node)
{
    if(node == NULL)
        return NULL;
 
    mirror(node->left);
    mirror(node->right);
    Tree *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
 
    return node;
}
