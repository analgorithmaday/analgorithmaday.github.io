void ptrTest(int* a, int* b)
{
    *(&a) = b;
}
void main()
{
    int A[]={5,13,2,25,7,17,20,8,4};
    int B[]= {2,3,4,5,6};
    ptrTest(A,B);
}
