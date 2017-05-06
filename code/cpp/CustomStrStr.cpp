int str_str(char* sstr, char* needle)
{
    char* iter = 0;
    char* stmp = 0;
    char* initial = sstr;
    while(*sstr != '\0') {
        iter = needle;
        stmp = sstr;
        while(*iter != '\0') {
            if(*stmp != *iter) {
                stmp++;
                break;
            }
            else
            {
                iter++;    
                stmp++;
            }
        }
        if(iter-needle == stmp-sstr)
            break;
        sstr++;
    }
    if(*sstr == '\0')
        return 0;
    else
        return sstr-initial;
}
 
void main()
{
    char* search_string="aabaaabbbbbbaaaaabbabaaaaaaaaaa";
    char* str = "aaa";
    std::cout<<str_str(search_string, str);
 
 
}
