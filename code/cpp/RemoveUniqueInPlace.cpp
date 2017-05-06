void removeUnique(char*& str)
{
int checker=0;
char* istr = str;
char* ehead = NULL;
while(*str != '\0')
{
int val = *str;
while(*str != '\0' && (checker & 1 << val))
{
if(ehead == NULL)
ehead = str;
// while there are duplicates
*str='\0';
str++;
val = *str;
}
if(*str == '\0') break;
checker |= 1<<val;
if(ehead != NULL) {
*ehead = *str;
*str = '\0';
ehead++;
}
str++;
}
str = istr;
}
 
void main()
{
char* text = strdup("How to Potentially Resolve Big Issues ");
removeUnique(text);
}
