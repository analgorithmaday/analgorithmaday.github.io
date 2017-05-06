char* str_rev(char* str)
{
    char* istr = str;
    char* output= (char*) malloc(strlen(str));
    char* ioutput = output;
    while(*str != '\0') {
        str++;
    }
 
    while(--str != istr) {
        *output = *str;
        output++;
    }
    *output = *str;
    *(output+1) = '\0';
    return ioutput;
}
 
void main()
{
    char* rstr = str_rev("rajan");
 
}
