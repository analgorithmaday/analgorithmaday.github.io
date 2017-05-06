void main()
{
    int a=0,b=0,c=0;
    int m,n;
 
    for(m=1; m < 15; m++) {
        for(n=m+1; n<30;n++) {
            if( a+b+c != 1000 ) {
                a = n*n - m*m;
                b = 2*n*m;
                c = n*n + m*m;
                std::cout<<m<<","<<n<<" ("<<a<<","<<b<<","<<c<<")"<<"="<<a+b+c<<std::endl;
            } else
                break;
        }
    }
 
}
