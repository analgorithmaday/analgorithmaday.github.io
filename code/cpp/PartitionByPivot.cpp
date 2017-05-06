void swap(int& a, int& b)
{
    register int tmp;
    tmp = a;
    a=b;
    b=tmp;
}
 
int partition(int* arr, int start, int end)
{
    /* 
      1. decide a pivot element, let it be arr[end]
      2. categorize arr the remainting start -> end-1 
      3. consider 2 indeces = i,j: initially i=start-1, j=start
      4. make sure that i+1 to j-1 always contains element > pivot
      5. the above means, i marks end of smaller elements array
      6. j marks the end of larger elements array
     */
 
    /*
    Example:
      start=0                                           end=12
  i=-1   j=0                                            
        3    6    2    1    9    4    12    19    13    10    8    5    11
        
        After you do this partition,
        start                            i            j       end
        3    6    2    1    9    4    10    8    5    [11]    12    19    13    
    The important point here is, after 4, we see 8 which is < 11.
    So, it needs to be inserted.
    Because of the above point we need 2 indeces.
    */
 
    int i,j, pivot;
    pivot = arr[end];
    i=start-1;
    for(j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot) {
            i=i+1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}
 
 
 
void main()
{
    int A[]={3,    6,    2,    1,    9,    4,    12,    19,    13,    10,    8,    5,    11};
    int B[]={6,10,2};
    partition(A,0,12);
 
    //sorting 3 elements
    int div = partition(B,0,2);
    //small list= 0->div-1
    //large list = div->3
    int l1 = partition(B,div+1,2);
    int l2 = partition(B,l1+1,2);
}
