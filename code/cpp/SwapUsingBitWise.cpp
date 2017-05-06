void swap(int *a, int *b)
{
    *a ^= *b; // a ^ b
    *b ^= *a; // b ^ a
    *a ^= *b; // a ^ b
}
 
void main()
{
    int a=5, b=8;
    int c=10, d=10;
    swap(&a,&b);
    swap(&c, &d); // it works
 
}
