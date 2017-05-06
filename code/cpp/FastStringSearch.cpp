int boyer_moore(char* sstr, char* pattern)
{
    char* inits = sstr;
    char* initp = pattern;
 
    int spatt = strlen(pattern);
    while(*pattern != '\0') pattern++;
    // this algorithm tested for printable ASCII characters
    // from ASCII, 65-90 and 97-122
    int* jump_table=(int*) calloc(128, sizeof(int));
    int count=0;
 
    while(pattern != initp) {
        pattern--;
        jump_table[*pattern]=count;
        count++;
    }
 
    char* stmp=0;
    char* iter=0;
    int shift=0;
    int bad_count=0;
 
    while(*sstr != '\0')
    {
        bad_count=spatt;
        stmp = sstr+ (spatt-1);
        iter = pattern + (spatt-1);
        while(*stmp == *iter) {
            bad_count--;
            stmp--;
            iter--;
            if(bad_count==0)
                return sstr-inits;
        }
 
        //jump table
        (jump_table[*stmp] == 0)?shift=bad_count:shift=jump_table[*stmp];
        sstr += shift;
    }
    //not found
    return -1;
}
 
 
void main()
{
    char* source = "aabaaabbbbbbaaaaabbabaaaaaaaaaa";
    char* pattern = "bab";
 
    std::cout<<boyer_moore(source, pattern);
}
