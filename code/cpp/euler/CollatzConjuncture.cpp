#include <iostream>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    int gMax = 0;
    double gI = 0;
    for(double i=1; i<1000000; i++) {
        double val = i;
        int count = 0;
        cout<<val<<" ";
        while(val != 1) {
            ++count;
            if (fmod(val, 2.0) == 0) {
                val = val/2;
            }
            else
            { // odd
                val = 3*val + 1;
            }
        }
        count++;
        if(count > gMax) {
            gI = i;
            gMax = count;
        }
        cout<<endl;
    }
 
    return 0;
}
