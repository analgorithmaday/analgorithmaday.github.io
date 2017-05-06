#define BASE 10
 
void counting_sort_radix(int*& arr, int k, int size)
{
    int *B, *C;
    C = (int*) malloc(sizeof(int)*BASE);
    B = (int*) malloc(sizeof(int)*(size+1));
 
    for(int i=0;i<BASE; i++) C[i] = 0;
 
    // only the last digit need to be used 
    // for sorting
    for(int i=0;i<size;i++){
        int val = arr[i]/k;
        int idx = val%BASE;
        C[idx]++;
    }
 
    for(int i=1;i<BASE;i++) C[i] += C[i-1];
 
    for(int j=size-1;j>=0;j--) {
        int val = arr[j]/k;
        int idx = val%BASE;
        B[C[idx]] = arr[j];
        C[idx]--;
    }
 
    free(C);
    for(int i=0; i<size; i++) arr[i] = B[i+1];
    free(B);
}
 
void radix_sort(int* arr, int d, int size)
{
    //d = number of digits
    // must calculate d from the max val in array
 
    for(int i=0;i<d; i++) {
        counting_sort_radix(arr, pow((float) BASE, (float) i), size);
    }
}
 
void main()
{
    int A[] = {329,457,657,89,46,720,355};
 
    radix_sort(A, 3, 7);
 
 
}
