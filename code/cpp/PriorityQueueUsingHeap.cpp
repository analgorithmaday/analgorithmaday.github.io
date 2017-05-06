#define PARENT(i)  (i-1)>>1
 
const int PQSIZE = 15;
 
class PriorityQueue
{
    int arr[PQSIZE];
    int idx;
 
public:
    PriorityQueue()
    {
        idx=0;
    }
 
    bool insert(int val)
    {
        if(idx > PQSIZE)
            return false;
 
        arr[idx] = INT_MIN;
        change(idx, val);
        idx++;
        return true;
 
    }
 
    int maximum() const { return arr[0]; }
 
    bool remove(int& val)
    {
        if(idx <= 0)
            return false;
 
        val = arr[0];
        arr[0] = arr[--idx];
        arr[idx] = INT_MIN;
        max_heapify(arr, 0, idx);
        return true;
    }
 
    bool change(int i, int val)
    {
        if(val < arr[i])
            return false;
        
        arr[i] = val;
        // the below loop never runs if the input
        // array is already in maxheap format!!
        while(i>0 && arr[PARENT(i)] < arr[i]) {
            int tmp=arr[PARENT(i)];
            arr[PARENT(i)] = arr[i];
            arr[i] = tmp;
            i = PARENT(i);
        }
        return true;
    }
};
 
void main()
{
    PriorityQueue pq;
    int A[] = {4,0,13,15,8,7,12,6,2,1,9,5};
 
    for(int i=0; i<12; i++)
    {
        pq.insert(A[i]);
    }
    int maxval = pq.maximum();
    int remval = 0;
    for(int i=0; i<15; i++)
    {
        pq.remove(remval);
    }
}
