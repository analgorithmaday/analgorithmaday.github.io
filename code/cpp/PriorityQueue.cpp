#define MAXQSIZE 10
 
class PriorityQueue
{
    int arr[MAXQSIZE];
    int idx;
 
public:
    PriorityQueue()
    {
        idx = 0;
    }
 
    bool insert(int elem)
    {
        if(idx > MAXQSIZE-1)
            return false;
 
        arr[idx++] = elem;
        return true;
    }
 
    bool remove(int& elem)
    {
        int maxIndex = 0;
        if(idx < 0)
            return false;
 
        for(int i = 1; i <= idx; i++) {
            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }
 
        elem = arr[maxIndex];
        //since idx++ is done by insert
        arr[maxIndex] = arr[idx-1]; 
        idx -= 1;
        return true;
    }
};
 
void main()
{
    int A[] = { 5, 4, 3, 2, 20, 7, 10};
    PriorityQueue pq;
    for(int i=0; i<7;i++) {
        pq.insert(A[i]);
    }
 
    int val=0;
    pq.remove(val);
}
