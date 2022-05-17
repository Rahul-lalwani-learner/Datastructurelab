#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void Create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    head = newnode;
}
void InsertBeg(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}
void InsertEnd(int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode->prev = ptr;
        ptr->next = newnode;
    }
}
void Display()
{
    struct node *ptr = head, *last;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "Traversal in Forward Direction" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            last = ptr;
            ptr = ptr->next;
        }
        cout << endl;
        cout << "Traversal in reverse Direction" << endl;
        while (last != NULL)
        {
            cout << last->data << " ";
            last = last->prev;
        }
        cout << endl;
    }
}
void InsertMid(int data,int num){
    if(head==NULL){
        cout<<"Linked list is Empty"<<endl;
    }
    else if(head->data==num){
        InsertBeg(data);
        cout<<data<<" is added After "<<num<<endl;
    }
    else {
        struct node*ptr=head;
        struct node*nxt=ptr->next;
        while(ptr!=NULL){
            if(ptr->data==num){
                break;
            }
            ptr=ptr->next;
            nxt=nxt->next;
        }
        if(ptr==NULL){
            cout<<"Element not found"<<endl;
        }
        else if(nxt==NULL){
            InsertEnd(data);
            cout<<data<<" is added After "<<num<<endl;

        }
        else{
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        ptr->next=newnode;
        nxt->prev=newnode;
        newnode->prev=ptr;
        newnode->next=nxt;
        cout<<data<<" is added After "<<num<<endl;

        }
    }
}
void InsertAtIndex(int data,int index){
    if(head==NULL && index!=0){
        cout<<"Linked list is Empty you can only Insert at index 0"<<endl;
    }
    else if(index<0){
        cout<<"Entered wrong input"<<endl;
    }
    else if(index==0){
        InsertBeg(data);
        cout<<data<<" is added to index "<<index<<endl;
    }
    else{
        int len=0;
        struct node *ptr=head;
        struct node *nxt=ptr->next;
        while(ptr!=NULL){
            if(len==index-1){
                break;
            }
            ptr=ptr->next;
            nxt=nxt->next;
            len++;
        }
        if(ptr==NULL){
            cout<<"You have Entered a wrong input"<<endl;
        }
        else if(nxt==NULL){
            InsertEnd(data);
            cout<<data<<" is added to index "<<index<<endl;

        }
        else{   
            struct node*newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=data;
            nxt->prev=newnode;
            ptr->next=newnode;
            newnode->prev=ptr;
            newnode->next=nxt;
            cout<<data<<" is added to index "<<index<<endl;
        }
    }
}
int main()
{
    Create(1);
    InsertEnd(2);
    InsertEnd(3);
    InsertEnd(4);
    InsertEnd(5);
    InsertBeg(0);
    InsertAtIndex(123,2);
    InsertMid(34,5);
    Display();
    return 0;
}