#include <vector>
#include <iostream>
#include <string>
 
vector<int> maxcredit(int credit, char* list, int lsize)
{
    int i;
    int* tlist;
    tlist = (int*) malloc(sizeof(int)*lsize);
    std::vector<int> result;
    char* prod = strdup(list);
    char* next = prod;
    i=0;
    strtok(next, " ");
    while(next)
    {
        int key = atoi(next);
        tlist[i] = key;
        next = strtok(NULL, " ");
        ++i;
    }
    free(prod);
    for(int j=0; j <i;j++)
    {
        for(int k=0; k < i; k++) {
            if(k != j && credit-tlist[j] == tlist[k]) {
                result.push_back(j+1);
                result.push_back(k+1);
                return result;
            }
        }
    }
    return result;
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
        int credit = atoi(line.c_str());
        getline(infile, line);
        int size = atoi(line.c_str());
        getline(infile, line);
        char* list = strdup(line.c_str());
        vector<int> tst = maxcredit(credit, list, size);
        outfile<<"Case #"<<i<<": "<<tst[0]<<" "<<tst[1]<<endl;
        free(list);
    }
}
Contact GitHub API Training Shop Blog About
