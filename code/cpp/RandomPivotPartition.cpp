int random_partition(int* arr, int size)
{
    srand(time(NULL));
    int pivotIdx = rand() % size;
    int pivot = arr[pivotIdx];
    int i=-1;
    int j=0;
    swap(arr[pivotIdx], arr[size-1]); // move pivot element to the end
    pivotIdx = size-1;
 
    while(j < size)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            swap(arr[i], arr[j]);
        }
        j++;
    }
 
    swap(arr[i+1], arr[pivotIdx]);
    return i+1;
}
 
void main()
{
    int A[] = {2,5,7,1,10,8,9};
    int loc = random_partition(A, 7);
}
