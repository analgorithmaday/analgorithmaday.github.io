char* longest_substring(char* str)
{
    char* istr = str;
    int checker=0;
    int countmax = 0;
    int maxl = 0;
    char* maxidx = str;
    while(*str != '\0')
    {
        if((checker & (1 << *str)))
        {
            if(maxl < countmax) {
                maxl=countmax;
                maxidx= str; 
            }
            checker=0;
            countmax=1; // include count of the duplicate
        }
        else {
            ++countmax;
        }
        checker |= (1 << *str);
        str++;
    }
    if(maxl < countmax) {
        maxl = countmax;
        maxidx = str;
    }
    char* start = maxidx-maxl;
    if(maxl != 0)     start[maxl] = '\0';
    return start;
}
 
void main()
{
    char* test = strdup("abcdbbnjkuiokklmnuuurstnvwabcd");
    char* str = longest_substring(test);
}
