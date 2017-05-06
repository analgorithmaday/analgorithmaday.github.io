#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void remove_dup(string& gems) {
    map<char, bool> visited;
    int len = gems.length();
    int i = 0;
    while(i < len) {
        if(visited[gems[i]]) {
            gems.erase(i, 1);
            len--;
            continue;
        }
        visited[gems[i]] = true;
        ++i;
    }
}

int commons(vector<string>& stones) {
    map<char, int> element_map;
    int commons = 0;
    for(int i = 0; i < stones.size(); ++i) {
        for(int j = 0; j < stones[i].length(); ++j) {
            element_map[stones[i][j]]++;
        }
    }

    for(map<char, int>::iterator it = element_map.begin(); it != element_map.end(); ++it ) {
       if(it->second == stones.size())
           commons++;
    }
    return commons;
}
int main()
{
    int N;
    vector<string> stones;
    cin>>N;
    for(int i=0; i < N; i++) {
        string gem;
        cin>>gem;
        remove_dup(gem);
        stones.push_back(gem);
    }
    cout<<commons(stones)<<endl;
}
