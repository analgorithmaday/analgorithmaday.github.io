struct List
{
    int data;
    List *next;
};
 
 
List* createNode(int data)
{
    List* n = new List;
    n->data = data;
    n->next = 0;
 
    return n;
}
 
void append(List* head, List* node)
{
    List *iter = head;
    if(head == 0)
    {
        head = node;
        head->next=0;
        return;
    }
 
    while(iter->next != 0) iter = iter->next;
    iter->next = node;
    iter->next->next = 0;
}
 
List* reverse_list(List* head)
{
    List* current = head;
    List* result = NULL;
    while(current != NULL)
    {
        List* next = current->next;
        current->next = result;
        result = current;
        current = next;
    }
    return result;
}
 
void printList(List* head)
{
    while(head != NULL) {
        std::cout<<head->data<<" ";
        head = head->next;
    }
}
void main()
{
    List* list = createNode(2);
    append(list, createNode(3));
    append(list, createNode(4));
    append(list, createNode(5));
    append(list, createNode(6));
    List* revlist = reverse_list(list);
    printList(revlist);
}
