class QueueList
{
    struct ListNode
    {
        int data;
        ListNode* next;
    };
    ListNode *first, *last;
public:
 
    QueueList() : first(NULL), last(NULL) { }
    void enqueue(int data);
    int dequeue();
};
 
void QueueList::enqueue(int data)
{
    ListNode *n = new ListNode;
    n->data = data;
    if(first == NULL && last == NULL)
    {
        first = last = n;
    }
    last->next = n;
    n->next = NULL;
    last = n;
}
 
int QueueList::dequeue()
{
    if(first == NULL && last == NULL) return -1;
 
    int data = first->data;
    ListNode* next = first->next;
    if(first == last) {
        free(last); 
        last = NULL;
    } else {
        free(first);
    }
    first = next;
 
 
    return data;
}
