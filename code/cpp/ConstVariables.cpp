void main()
{
   int a = 10;
   int b = 20;
   const int& c = a;
   // This will give error, through c you cannot modify a 
   c = b;   
   // But a is not following physical const, overwrite!!
   a = b; 
   std::cout<<c; //you will get 20, since a is modified!!
 
}
