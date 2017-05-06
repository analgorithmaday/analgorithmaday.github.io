int getRandom(int start, int end)
{
    srand(time(NULL));
    return (rand() % (end-start+1))+start;
}
 
 
int* getUniqueNums(int limit)
{
    int *numbers = (int*) malloc(sizeof(int)*limit);
    int checker=0;
    bool *myset = (bool*) calloc(limit, sizeof(bool));
    int i=0;
 
    do {
        int num = getRandom(0,limit-1);
        if(!myset[num]) 
        { 
            numbers[i] = num;
            myset[num] = true;
            i++;
        }
    }while(i<limit);
 
    return numbers;
}
 
void main()
{
  int a[] = {1,2,3,4,5,6};
  int *b = getUniqueNums(6);
 
  // use b array as priority array into a
  for(int i=0;i<6;i++) {
      b[i] = a[b[i]];
  }
}
