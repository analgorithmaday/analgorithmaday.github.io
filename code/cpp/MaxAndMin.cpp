void getRange(int *arr, int size)
{
    int min;
    int max;
    int start=0;
    if((size & 1) == 1) {
        min = arr[0]; 
        max = arr[0];
        start = 1;
    }
    else {
        if(arr[0] < arr[1]) {
            min = arr[0];
            max = arr[1];
        }
        else {
            min = arr[1];
            max = arr[0];
        }
        start = 2;
    }
    for(int i = start; i < size; i+=2)
    {
        int smaller;
        int larger;
        if(arr[i] < arr[i+1]) {
            smaller = arr[i];
            larger = arr[i+1];
        }
        else {
            smaller = arr[i+1];
            larger = arr[i];
        }
 
        if(min > smaller)
             min = smaller;
 
        if(max < larger)
            max = larger;
    }
    cout<<min<<","<<max;
}
 
 
void main()
{
    int A[] = {2,5,8,9,13,4,14,6};
    getRange(A, 8);
}
