bool isUniqueDigits(int* arr, int size)
{
int checker=0;
for(int i=0; i < size; i++)
{
if((checker & 1 << arr[i]))
return false;
checker |= 1 << arr[i];
}
return true;
}
