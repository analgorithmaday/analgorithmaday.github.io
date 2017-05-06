 
bool isUniqueChars(char* str)
{
//assume lower case
int checker = 0;
while(*str != '\0')
{
int val = *str - 'a';
if((checker & (1 << val))) // when some 1 collide with checker, false
return false;
checker |= 1 << val; // checker will become series of 1's
str++;
}
return true;
}
 
void main()
{
char* mstr = "ravi kuma";
bool test = isUniqueChars(mstr);
}
