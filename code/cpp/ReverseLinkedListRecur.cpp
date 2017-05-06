List* recur_rlist(List* head)
{
    List* result;
    if(!(head && head->next)) 
        return head;
 
    result = recur_rlist(head->next);
    head->next->next = head;
    head->next = NULL;
 
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
    List* revlist = recur_rlist(list);
    printList(revlist);
}
