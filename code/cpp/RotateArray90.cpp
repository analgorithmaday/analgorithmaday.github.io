int** rotate(int** arr, int N)
{
int** b = (int**)calloc(N, sizeof(int));
for(int i=0; i< N; i++)
b[i] = (int*) calloc(N, sizeof(int));
 
for(int i=N-1; i>=0; i--)
{
for(int j=0; j < N; j++)
{
b[j][(N-1)-i] = arr[i][j];
}
}
return b;
}
 
void printArray(int** arr, int N)
{
for(int i=0;i<N;i++) {
for(int j=0;j<N;j++)
std::cout<<arr[i][j]<<" ";
std::cout<<std::endl;
}
}
 
 
void main()
{
int N=4;
int** rot90;
int c=1;
int **A = (int**)calloc(N, sizeof(int*));
for(int i=0; i<N; i++) {
A[i] = (int*) calloc(N, sizeof(int));
for(int j=0; j<N; j++) {
A[i][j] = c++;
}
}
printArray(A, N);
rot90 = rotate(A, N);
printArray(rot90, N);
}
