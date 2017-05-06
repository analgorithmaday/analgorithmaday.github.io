#include <algorithm>
 
long long minimum_scalar(char* inp1, char* inp2, int size)
{
    vector<long> v1, v2;
    long long sum=0;
    char* next = strtok(inp1, " ");
    while(next) {
        v1.push_back(atol(next));
        next=strtok(NULL, " ");
    }
    next = strtok(inp2, " ");
    while(next) {
        v2.push_back(atol(next));
        next=strtok(NULL, " ");
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    for(int i =0; i<size;i++)
    {
        sum += (long long)v1[i] * (long long)v2[i];
    }
    return sum;
}
 
void main()
{
    ifstream infile("A-large-practice.in");
    ofstream outfile("result.txt");
    string line;
    getline(infile, line);
    int num_of_cases = atoi(line.c_str());
    for(int i=1; i<=num_of_cases; i++)
    {
        getline(infile, line);
        int vsize = atoi(line.c_str());
        getline(infile, line);
        char* list1 = strdup(line.c_str());
        getline(infile, line);
        char* list2 = strdup(line.c_str());
        long long val = minimum_scalar(list1, list2, vsize);
        outfile<<"Case #"<<i<<": "<<val<<endl;
        free(list1);
        free(list2);
    }
}
