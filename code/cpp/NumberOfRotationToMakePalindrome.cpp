#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int cramble(string str) {
    int size = str.length();
    int count = 0;
    for(int i = 0, j = size-1; i < j; ++i, --j) {
        if(str[i] != str[j]) {
            count += abs(str[i] - str[j]);
        }
    }
    return count;
}

int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        string love;
        cin>>love;
        cout<<cramble(love)<<endl;
    }    
    return 0;
}
