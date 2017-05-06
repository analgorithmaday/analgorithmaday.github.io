bool detect_anagram(char* src, char* anagram)
{
    int isrc=0, iana=0;
    while(*src != '\0') {
        char* iter = anagram;
        while(*iter != '\0' && *src != ' ') {
            if(*src == *iter) {
                iana++;
                break;
            }
            iter++;
        }
        if(*src != ' ')
            isrc++;
        src++;
    }
    if(iana == isrc)
        return true;
    else
        return false;
 
}
 
void main()
{
    char *src=strdup("eleven plus two");
    char *a = strdup("so plew veluent");
    bool st = detect_anagram(src, a);
}
