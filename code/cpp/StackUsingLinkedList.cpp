class StackList 
{
    struct ListNode {
        int data;
        ListNode* next;
    };
    ListNode *head;
public:
    StackList() : head(NULL) {}
    void push(int data);
    int pop();
};
 
void StackList::push(int data)
{
    ListNode* n = new ListNode;
    n->data = data;
    n->next = head;
    head = n;
}
 
int StackList::pop()
{
    if(head == NULL)
        return -1;
 
    int tdata = head->data;
    ListNode* next = head->next;
    free(head);
    head = next;
 
    return tdata;
}
 
void main()
{
    StackList obj;
    obj.push(5);
    obj.push(3);
    obj.push(2);
    obj.push(10);
    cout<<obj.pop();
}
