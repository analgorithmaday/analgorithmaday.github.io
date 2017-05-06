int* counting_sort(int* arr, int k, int size)
{
    int *B, *C;
    C = (int*) malloc(sizeof(int)*k);
    B = (int*) malloc(sizeof(int)*size);
 
    for(int i=0;i<k; i++) C[i] = 0;
    // get the count of elements in arr. 
    // ASSUMPTION: All elements in arr is < k
    for(int i=0;i<size;i++) C[arr[i]]++;
 
    for(int i=k-1;i>0;i--) C[i-1] += C[i];
 
    for(int j=0;j<size;j++) {
        B[C[arr[j]]] = arr[j];
        C[arr[j]]--;
    }
    return B;
}
void main()
{
    int A[] = {2,3,4,1,6,8,7,5};
    int *b;
    b = counting_sort(A, 9, 8);
    // b[0] is garbage, unused entry
    std::cout<<b[0]<<std::endl;
 
    // b[1]..b[size] is filled with sorted
    std::cout<<b[1];
}
