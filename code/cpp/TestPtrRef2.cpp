void ptrTest(int** a, int** b)
{
    *a = *b;
}
void main()
{
    int A[]={5,13,2,25,7,17,20,8,4};
    int B[]={1,2,3,4,5,6,7,8,9};
    int *ptrA = A;
    int *ptrB = B;
    ptrTest(&ptrA, &ptrB);
}
