#define LEFT(x) 2*x+1 // since we start with index 0
#define RIGHT(x) 2*x+2
#define heap_size(x) (sizeof(x)/sizeof(x[0])) //similar to ARRAYSIZE macro
 
 
void max_heapify(int *arr, int idx, int size)
{
    int l = LEFT(idx);
    int r = RIGHT(idx);
    int largest;
    if( l <= size && arr[l] > arr[idx])
        largest = l;
    else
        largest = idx;
 
    if(r <= size && arr[r] > arr[largest])
        largest = r;
 
    if(largest != idx) {
        int temp = arr[idx];
        arr[idx] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, largest, size);
    }
 
}
 
void build_max_heap(int *arr, int size)
{
    for(int i=(int) floor((float)size/(float)2);i>=0; i--)
    {
        // if size = 10, then,
        // initial max_heapify call will be like, max_heapify(arr, 5)
        // But note that, we run until 0 and zero is root for this code
        max_heapify(arr, i, size); 
    }
}
 
void heap_sort(int *arr, int size)
{
    int length = size;
    build_max_heap(arr, length);
    for(int i=length; i>=1; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        size = size-1;
        max_heapify(arr, 0, size);
    }
}
 
void main()
{
    int A[]={5,13,2,25,7,17,20,8,4};
    heap_sort(A, 8);
}

