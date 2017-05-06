class TestConst
{
    int a;
 
public:
    TestConst() { a = 0;}
 
    int ret() const { return a; }
 
    int ret() { a=10; return a; }
 
    int normalApi() { a=20; return a; }
 
};
 
void main()
{
    TestConst obj; 
    const TestConst& objRef = obj;  
    // only const ret() can be called, a=0 
    std::cout<<objRef.ret();
    // logical const, non-const ret() is called
    std::cout<<obj.ret();  
    //now, a=10 !!.. same physical const problem
    std::cout<<objRef.ret();  
    // throws an error, pointer is const!!
    std::cout<<objRef.normalApi(); 
}
