#define PARENT(i) i-1/2
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
#define ARRAYSIZE(a) sizeof(a)/sizeof(a[0])
 
int A[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
 
/*
The tree looks like this,
                    1
            2                3
       4        5        6        7
    8    9      10  11  12  13  14
preorder: root=>left=>right
1. is(root) => left => is(root), until root = NULL
2. visited(root) => right => is(root) => left => is(root), until root=NULL 
    1 2 4 8 9 5 10 11 3 6 12 13 7 14
postorder: left=>right=>root
8 9 4 10 11 5 2 12 13 6 14 7 3 1
*/
 
void preorder_stack(int idx)
{
    Stack<int> obj;
    int j= idx;
    while(j < ARRAYSIZE(A)) {
        int i = j;
        // move to root till left
        // note, this runs for all the root
        // even the right root!!
        while(i < ARRAYSIZE(A)) {
            std::cout<<A[i]<<" ";
            obj.push(i);
            i=LEFT(i);
        }
        // move to the right
        int val;
        obj.pop(val);
        j=RIGHT(val);
        // remove leaf less nodes
        while(j > ARRAYSIZE(A)) {
            obj.pop(val);
            j=RIGHT(val);
        }
    }
}
 
void preorder(int idx)
{
     if ( idx < ARRAYSIZE(A)){
         std::cout<<A[idx]<<" ";
         preorder(LEFT(idx));
         preorder(RIGHT(idx));
     }
}
 
void postorder(int idx)
{
    if(idx < ARRAYSIZE(A)) {
        postorder(LEFT(idx));
        postorder(RIGHT(idx));
        std::cout<<A[idx]<<" ";
    }
}
 
void inorder(int idx)
{
    if(idx < ARRAYSIZE(A)) {
        inorder(LEFT(idx));
        std::cout<<A[idx]<<" ";
        inorder(RIGHT(idx));
    }
}
void main()
{
  preorder_stack(0);
  std::cout<<endl;
  preorder(0);
  std::cout<<endl;
  postorder(0);
  std::cout<<endl;
}
