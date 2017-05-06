class PerStack
{
    int arr1[100];
    int arr2[100];
    int top1;
    int top2;
 
public:
 
    PerStack() : top1(0), top2(0) {
        arr2[0] = INT_MAX;
    }
 
    void push(int val)
    {
        arr1[top1++] = val;
        if(val < arr2[top2] )
        {
            arr2[++top2] = val;
        }
    }
 
    int pop()
    {
        if(arr1[top1] == arr2[top2])
            arr2[top2--] = INT_MIN;
        return arr1[--top1];
    }
 
    int min() {
        return arr2[top2];
    }
};
 
void main()
{
    int A[] = {9,5,7,1,10,2,3};
    PerStack n;
    for(int i=0; i<7;i++)
        n.push(A[i]);
 
    cout<<"minimum : "<<n.min();
}
