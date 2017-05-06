void getRange(int *arr, int size)
{
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0; i < size; i++)
    {
        if(arr[i] < min)
            min = arr[i];
 
        if(arr[i] > max)
            max = arr[i];
    }
    cout<<min<<","<<max;
}
 
 
void main()
{
    int A[] = {2,5,1,8,9,13,4,14,6};
    getRange(A, 9);
}
