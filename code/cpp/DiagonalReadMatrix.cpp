#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    int N=1;
    cin>>N;
    int **A = new int*[N];
    for(int i = 0; i < N; ++i)
    {
        A[i] = new int[N];
        for(int j = 0; j < N; ++j)
        {
            cin>>A[i][j];
        }
    }
    
    int sumDiag1 = 0;
    int sumDiag2 = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(i == j)
            {
               sumDiag1 += A[i][j];    
            }
            
            if(j + i == N-1)
            {
               sumDiag2 += A[i][j]; 
            }
        }
    }
    cout<<abs(sumDiag1 - sumDiag2);
    return 0;
}
