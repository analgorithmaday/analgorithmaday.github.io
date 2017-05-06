 
class List
{
    int data;
    List* next;
    
public:
    List(int d)
    {
        this->data = d;
        this->next = NULL;
    }
 
    void append(int item)
    {
        List* iter = this;
        
        while(iter->next != NULL) iter = iter->next;
 
        List* newNode = new List(item);
 
        iter->next = newNode;
    }
 
    void deleteNode(List*& node)
    {
        if(this == node)
        {
            List *tmp = node->next;
            node->data = node->next->data;
            node->next = node->next->next;
            delete tmp;
        } else {
            List *iter = this;
            while(iter && iter->next != node) iter = iter->next;
 
            if(iter != NULL) {
                iter->next = node->next;
                delete node;
                node = iter;
            }
        }
    }
    void remove_dup()
    {
        for(List *iter1 = this; iter1 != NULL; iter1 = iter1->next) {
            for(List *iter2 = iter1->next; iter2 != NULL; iter2 = iter2->next) {
                if(iter1->data == iter2->data) {
                    deleteNode(iter2);
                }
            }
        }
    }
 
    void printList()
    {
        List *iter = this;
        while(iter) {
            std::cout<<iter->data<<"->";
            iter = iter->next;
        }
    }
};
 
 
void main()
{
    List obj(10);
    List *ptr = &obj;
    obj.append(2);obj.append(3);obj.append(5);
    obj.append(3); obj.append(6);
    obj.append(2); 
 
    obj.deleteNode(ptr);
    obj.printList();
    obj.remove_dup();
    std::cout<<std::endl;
    obj.printList();
}
