#include <vector>
#include <iostream>
 
using namespace std;
 
int main(void)
{
    int T;
    vector<long> out;
    cin>>T;
    for(int i = 0; i < T; ++i)
    {
        long q, r, val;
        cin>>val;
        q = val / 2;
        r = val - q;
        out.push_back(q*r);
    }
    for(int i = 0; i < (int) out.size(); ++i)
        cout<<out[i]<<endl;
}
