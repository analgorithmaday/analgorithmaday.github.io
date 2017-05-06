int qpartition( int *a, int low, int high )
{
    int left, right;
    int pivot_item;
    pivot_item = a[low];
    left = low;
    right = high;
    while ( left < right ) {
        /* Move left while item < pivot */
        while( a[left] <= pivot_item ) left++;
        /* Move right while item > pivot */
        while( a[right] > pivot_item ) right--;
        if ( left < right ) swap(a[left],a[right]);
    }
    /* right is final position for the pivot */
    a[low] = a[right];
    a[right] = pivot_item;
    return right;
}
 
void main()
{
    int A[] = {9,5,7,1,10,2,3};
    int loc = qpartition(A, 0,6);
}
