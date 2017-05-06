const int SIZE=10;
 
template<class T>
class Stack
{
    T arr[SIZE];
    int top_idx;
 
    int top() const    {    return top_idx; }
 
    bool stack_empty() const {  return (top_idx == -1);     }
 
    bool stack_full() const { return (top_idx+1 > SIZE-1); }
 
public:
    Stack() {
        top_idx = -1;
    }
 
    bool push(T val)    {    
        if(stack_full())
            return false;
        else {
            arr[++top_idx] = val;
            return true;
        }
    }
 
    bool pop(T& val) {
        if(stack_empty())
            return false;
        else {
            val = arr[top_idx];
            top_idx -=1;
            return true;
        }
    }
};
 
void main()
{
    Stack<int> sobj;
    int pop_val;
