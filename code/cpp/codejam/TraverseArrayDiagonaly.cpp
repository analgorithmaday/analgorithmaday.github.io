void main()
{
    int x[3][3] = {1, 2, 3,
                   4, 5, 6,
                   7, 8, 9};
    int N=3;
    for (int slice = 0; slice < N*2-1; ++slice) {
        int z = slice < N ? 0 : slice - N + 1;
        for (int j = z; j <= slice - z; ++j) {
            int c1=j;
            int c2=(N-1)-(slice-j);
            printf("%d ", x[c1][c2]);
        }
        printf("\n");
    }
    
    printf("\n");
    for (int slice = 0; slice < N*2-1; ++slice) {
        int z = slice < N ? 0 : slice - N + 1;
        for (int j = z; j <= slice - z; ++j) {
            int c1=j;
            int c2=slice-j;
            printf("%d ", x[c1][c2]);
        }
        printf("\n");
    }
}
