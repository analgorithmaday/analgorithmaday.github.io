int partition_sign(int* arr, int start, int end)
{
    int i,j, pivot;
    pivot = 0;
    i=start-1;
    for(j=start; j<=end; j++)
    {
        if(arr[j] <= pivot) {
            i=i+1;
            if(i!=j)
                swap(arr[i], arr[j]);
        }
    }
    return i+1;
}
 
 
void main()
{
    int A[] = {-3,4,3,-2,-8,6,13,-15};
    int pos = partition_sign(A, 0, 7);
}
