int findKSmall(int* a, int m, int* b, int n, int k)
{
    int i=0;
    int j=0;
    int elem;
    while(k>0)
    {
        if(a[i] < b[j]) {
            if(i>m)
                continue;
            elem = a[i];
            i++;
        }
        else {
            if(j > n)
                continue;
            elem = b[j];
            j++;
        }
        k--;
    }
    return elem;
}
 
 
void main()
{
    int a[] = {2,4,6,9};
    int b[] = {8,10,14,21,32,44};
    int val = findKSmall(a,4,b,6, 10);
}
