#define LEFT(x) 2*x+1 // since we start with index 0
#define RIGHT(x) 2*x+2
#define heap_size(x) (sizeof(x)/sizeof(x[0])) //similar to ARRAYSIZE macro
 
template <typename T, size_t size>
void build_max_heap(T (&arr)[size])
{
    for(int i=(int) floor((float)heap_size(arr)/(float)2);i>=0; i--)
    {
        // if size = 10, then,
        // initial max_heapify call will be like, max_heapify(arr, 5)
        // But note that, we run until 0 and zero is root for this code
        max_heapify(arr, i); 
    }
}
 
template <typename T, size_t size>
void max_heapify(T (&arr)[size], int idx)
{
    int l = LEFT(idx);
    int r = RIGHT(idx);
    int largest;
    if( l <= heap_size(arr) && arr[l] > arr[idx])
        largest = l;
    else
        largest = idx;
 
    if(r <= heap_size(arr) && arr[r] > arr[largest])
        largest = r;
 
    if(largest != idx) {
        int temp = arr[idx];
        arr[idx] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, largest);
    }
 
}
 
void main()
{
    int A[]={5,3,17,10,84,19,6,22,9};
    build_max_heap(A);
}
