void slashZero(int**& arr, int M, int N)
{
    bool *arr_rows = (bool*) calloc(M, sizeof(bool));
    bool *arr_col = (bool*) calloc(N, sizeof(bool));
    
    for(int i=0; i < M; i++) {
        for(int j=0; j < N; j++) {
            if(arr[i][j] == 0) {
                if(arr_rows[i] != true)
                    arr_rows[i] = true;
                if(arr_col[j] != true)
                    arr_col[j] = true;
            }
        }
        //zero rows
        if(arr_rows[i]) {
            for(int j=0; j < N; j++)
                arr[i][j] = 0;
        }
    }
 
    // zero colums
    for(int j =0; j < N ; j++) {
        if(arr_col[j]) {
            for(int i =0; i < M; i++) {
                arr[i][j] = 0;
            }
        }
    }
 
}
 
void printArray(int** arr, int M, int N)
{
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++)
            std::cout<<arr[i][j]<<" ";
        std::cout<<std::endl;
    }
}
 
void main()
{
    int M=3, N=4;
    int c=1;
    int **A = (int**)calloc(M, sizeof(int*));
    for(int i=0; i<M; i++) {
        A[i] = (int*) calloc(N, sizeof(int));
        for(int j=0; j<N; j++) {
            A[i][j] = c++;
        }
    }
    A[0][1] = 0; A[1][1]=0; A[0][3]=0;
    printArray(A, M, N);
    slashZero(A, M, N);
    printArray(A, M, N);
}
