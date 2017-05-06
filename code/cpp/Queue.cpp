 
const int QSIZE=5;
 
template<class T>
class Queue
{
    T arr[QSIZE];
    int front;
    int back;
 
public:
    Queue()
    {
        front=0;
        back=0;
    }
 
    bool enqueue(const T val)
    {
        if(isFull()) return false;
 
        arr[back] = val;
        if(back == QSIZE-1)
            back = 0;
        else
            back++;
 
        return true;
    }
 
    // cannot mark this fn as const
    bool dequeue(T& val)
    {
        if(isEmpty()) 
            return false;
 
        val = arr[front];
        arr[front] = "";
        if(front == QSIZE-1)
            front = 0;
        else
            front++;
 
        return true;
    }
 
    bool isEmpty() const { return (front == back); }
 
    bool isFull() const { return (front == back + 1 || (front ==0 && back==QSIZE-1)); }
};
 
void main()
{
    Queue<char*> names;
    // Note that all are const char*
    names.enqueue("Jack");
    names.enqueue("Muthu");
    names.enqueue("Murugan");
    names.enqueue("Kumar");
    names.enqueue("Vinay");
    names.enqueue("Purva");
 
    char* toppers="";
    // remove jack, muthu
    for(int i=0; i<2;i++)
        names.dequeue(toppers);
 
    // enqueue rowdi
    // eventhough they go at top index
    // they are not at front :)
    for(int i=0;i<4;i++) 
        names.enqueue("Rowdis");
 
    // Now, murugan & kumar 
    // Rowdis cannot do anything!!
    for(int i=0; i<2;i++)
        names.dequeue(toppers);
 
    // Polician join Rowdies now
    // here too only after Rowdies, Politicians :)
    for(int i=0;i<4;i++) 
        names.enqueue("Politician");
 
}
