 
Tree* makeThreaded(Tree* root)
{
    if(root == NULL)
        return NULL;
 
    Tree* leftPrev = makeThreaded(root->left);
    if(leftPrev != NULL) {
        std::cout<<leftPrev->data;
        std::cout<<":"<<root->data<<std::endl;
        Tree* iter = leftPrev;
        while(iter->right != NULL && iter->right != leftPrev)
            iter = iter->right;
 
        iter->right = root;
    }
    Tree* rightPrev = makeThreaded(root->right);
    if(rightPrev != NULL) {
        std::cout<<rightPrev->data;
        std::cout<<":"<<root->data<<std::endl;
        Tree* iter = rightPrev;
        while(iter->right != NULL && iter->right != rightPrev)
            iter = iter->right;
 
        iter->right = root;
    }
 
    return root;
}
 
Tree* tobj = newTree();
Tree* root = makeThreaded(tobj); // there will be no change in root
