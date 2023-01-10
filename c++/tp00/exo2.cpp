//exercice 2
struct node* reverse(node* head, int k)
{
    if(head==NULL) 
    {
        return NULL;
    }
    struct node* next=NULL;
    struct node* prev=NULL;
    struct node* curr=head;
    int count=0;
    while(curr && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    head->next=reverse(curr,k);
    return prev;
}
