void rle(char* sstr)
{
    while(*sstr != '\0')
    {
        int cc=1;
        std::cout<<*sstr;
        while(*sstr == *(sstr+1)) {
            cc++;
            sstr++;
        }    
        std::cout<<cc;
        sstr++;
    }
    return;
}
 
void main()
{
    char* str="WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
    rle(str);
}
