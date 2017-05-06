char* str_rev(char* str)
{
    char* tstr = str;
    char* istr = tstr; // string start
    while(*tstr != '\0') tstr++;
    char* estr = --tstr; // string end
    while(istr != estr)
    {
        char tmp = *istr;
        *istr = *estr;
        *estr = tmp;
        istr++;
        estr--;
    }
    return str;
}
 
void main()
{
    char* ptr = strdup("rajan");
    char* rstr = str_rev(ptr);
 
}
