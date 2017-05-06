class BST {
public:
    int data;
    BST* parent;
    BST* left;
    BST* right;
};
 
// inorder traversal of BST
// MUST GIVE SORTED OUTPUT
void printBST(BST* root)
{
    if(root == NULL) return;
    printBST(root->left);
    cout<<root->data;
    printBST(root->right);
}
 
// left most is MIN
int min(BST* root)
{
    int minval=0;
    while(root != NULL) {
        minval = root->data;
        root = root->left;
    }
 
    return minval;
}
 
// right most is MAX
int max(BST* root)
{
    int maxval=0;
    while(root != NULL) {
        maxval = root->data;
        root = root->right;
    }
    return maxval;
}
