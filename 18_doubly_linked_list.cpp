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

void DeleteBeg(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    else if(head->next==NULL){
        struct node*ptr=head;
        cout<<"Deleted Element is : "<<ptr->data<<endl;
        free(ptr);
        head=NULL;
    }
    else{
        struct node*ptr=head;
        cout<<"Deleted Element is : "<<ptr->data<<endl;
        head=head->next;
        head->prev=NULL;
        free(ptr);
    }
}


void DeleteEnd(){
    if(head==NULL){
        cout<<"List is Empty"<<endl;
    }
    else if(head->next==NULL){
        struct node*ptr=head;
        cout<<"Deleted Element is: "<<ptr->data<<endl;
        head=NULL;
        free(ptr);
    }
    else{
        struct node*ptr=head;
        struct node*preptr=ptr;
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr=ptr->next;
        }
        cout<<"Deleted Element is: "<<ptr->data<<endl;
        preptr->next=NULL;
        free(ptr);
    }
}
void DeleteAtIndex(int Index){
    if(head==NULL){
        cout<<"List is Empty"<<endl;
    }
    else if(Index <0){
        cout<<"Wrong Input"<<endl;
    }
    else if(Index==0){
        DeleteBeg();
    }
    else{
        int len=0;
        struct node*ptr=head;
        struct node*preptr=ptr;
        // struct node*nxt=ptr->next;
        while(ptr!=NULL){
            if(len==Index){
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
            // cout<<"Hello";
            // nxt=nxt->next;
            len++;
        }
        if(ptr==NULL){
            cout<<"Enter correct Input"<<endl;
        }
        else if(ptr->next==NULL){
            DeleteEnd();
        }
        else{
            preptr->next=ptr->next;
            ptr->next->prev=preptr;
            cout<<"Deleted Element is: "<<ptr->data<<endl;
            free(ptr);
        }
    }
}
void DeleteMid(int num){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    else if(head->data==num){
        DeleteBeg();
    }
    else{
        struct node*ptr=head;
        struct node*preptr=ptr;
        while(ptr!=NULL){
            if(ptr->data==num){
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cout<<"Element not found"<<endl;
        }
        else if(ptr->next==NULL){
            DeleteEnd();
        }
        else{
            preptr->next=ptr->next;
            ptr->next->prev=preptr;
            cout<<"Deleted Element is : "<<ptr->data<<endl;
            free(ptr);
        }
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

int main()
{
    /*
    Create(11);
    InsertEnd(12);
    InsertEnd(13);
    InsertEnd(14);
    InsertEnd(15);
    InsertBeg(10);
    // InsertAtIndex(123,2);
    // InsertMid(34,5);
    // DeleteBeg();
    // DeleteEnd();
    // DeleteAtIndex(2);
    DeleteMid(15);
    Display();
    */
    cout<<"Doubly Linked list"<<endl;
    int ch;
    do{
        cout<<endl;
        cout<<"1. Insert Element at Beginning\n2. Insert Element at End\n3. Insert Element at Index\n4. Insert Element after Number\n5. Delete Element at Beginning\n6. Delete Element at End\n7. Delete Element At Index\n8. Delete Element \n9. Display\n10. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        cout<<endl;
        int val,index,num;
        switch (ch)
        {
        case 1:
            cout<<"Enter data: ";
            cin>>val;
            InsertBeg(val);
            break;
        case 2:
            // int val;
            cout<<"Enter data: ";
            cin>>val;
            InsertEnd(val);
            break;
        case 3: 
            // int val,index;
            cout<<"Enter data and Index: ";
            cin>>val>>index;
            InsertAtIndex(val,index);
            break;
        case 4:
            // int val,num;
            cout<<"Enter data and number after which you want to insert: ";
            cin>>val>>num;
            InsertMid(val,num);
            break;
        case 5: 
            DeleteBeg();
            break;
        case 6:
            DeleteEnd();
            break;
        case 7: 
            // int index;
            cout<<"Enter index: ";
            cin>>index;
            DeleteAtIndex(index);
            break;
        case 8:
            // int num;
            cout<<"Enter number you want to Delete: ";
            cin>>num;
            DeleteMid(num);
            break;
        case 9:
            Display();
            break;
        case 10:
            cout<<"Exit"<<endl;
            break;
        default:
            cout<<"Wrong Input"<<endl;
            break;
        }   
    }while(ch!=10);
    return 0;
}