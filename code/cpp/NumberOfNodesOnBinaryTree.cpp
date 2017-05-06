Tree* tobj;
 
int count(Tree* root) {
    if(root == NULL)
        return 0;
    else 
        if(root->left == NULL && root->right == NULL)
            return 1;
        else
            return count(root->left) + count(root->right) + 1;    
}
 
cout<<count(tobj);
