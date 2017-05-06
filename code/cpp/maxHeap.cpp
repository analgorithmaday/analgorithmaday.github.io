#define LEFT(x) 2*x+1 // since we start with index 0
#define RIGHT(x) 2*x+2
#define heap_size(x) (sizeof(x)/sizeof(x[0])) //similar to ARRAYSIZE macro
 
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
    int A[]={16,4,10,14,7,9,3,2,8,1};
    int val = heap_size(A);
    max_heapify(A, 1);
    
}
