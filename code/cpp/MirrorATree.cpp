Tree* mirror(Tree* node)
{
    if(node == NULL)
        return NULL;
 
    node->left = mirror(node->right);
    node->right = mirror(node->left);
 
    return node;
} 
