char* str_rev_words(char* str)
{
    char* result = str;
    while(*str != '\0') {
        char* tstr = str;
        char* istr = tstr; // string start
        while(1) {
            if(*(tstr+1) == ' ' || *(tstr+1) == '\0') break;
            tstr++;            
        }
        char* estr = tstr; // string end
        while(!(istr >= estr))
        {
            char tmp = *istr;
            *istr = *estr;
            *estr = tmp;
            istr++;
            estr--;
        }
        if(*(tstr+1) == '\0')
            str = tstr+1;
        else
            str = tstr+2;
    }
    return result;
}
 
#include <fstream>
 
using namespace std;
 
void main()
{
    char line[1000];
    ifstream myfile ("C:\\Works\\cppassignments\\algorithms\\B-large-practice.in");
    ofstream outfile ("C:\\Works\\cppassignments\\algorithms\\result.txt");
    myfile.getline(line, 1000);
    int num_of_cases = atoi(line);
    for(int i=1; i<=num_of_cases; i++)
    {
        myfile.getline(line, 1000);
        // doProblem
        str_rev(line);
        outfile<<"Case #"<<i<<": "<<str_rev_words(line)<<endl;
    }
    outfile.close();
    myfile.close();
}
