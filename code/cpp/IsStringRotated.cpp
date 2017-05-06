/*
Whether the string is rotated or not?
simple
plesim
*/
 
bool isRotated(char* input, char* rotated)
{
    if(strlen(input) != strlen(rotated))
        return false;
 
    char* buff = (char*) malloc(strlen(rotated)*2);
    strcat(buff, rotated);
    strcat(buff, rotated);
    char* pos = strstr(buff, input);
    if(pos != NULL)
        return true;
    else
        return false;
}
void main()
{
    bool test = isRotated("simple", "esimpl");
}
