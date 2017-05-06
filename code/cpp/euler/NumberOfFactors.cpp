 
#include <math.h>
 
void main(int argc, char* argv[])
{
    int data=0; //pow(35.00,13.00);
    int next=1;
    int max = 0;
 
    while(1) {
    int count=0;
    int diff = 0;
    data = data+next;
    int mid = (int) floor(sqrt((double)data));
    if(mid * mid == data) 
        diff = -1;
    
    for(int j=1;j<=mid;j++) {
        if(data % j == 0) {
            ++count;
        }
    }
    count = count*2+diff;
    if(count > max) {
        max = count;
        cout<<data<<"="<<count<<endl;
        if(max > 499) 
            break;
    }
    next++;
    }
}
