#include <iostream>
// https://favtutor.com/blogs/circular-linked-list-cpp#:~:text=A%20circular%20linked%20list%20is,field%20of%20the%20last%20node.
using namespace std;
struct node {
    int data;
    struct node* next;
};
struct node * head=NULL;
void insert_beg(int newdata){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        newnode->next=head->next;
        head->next=newnode;
        head=newnode;
        // head=newnode;
    }
}
void insert_end(int newdata){
    struct node*newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        struct node*ptr=head;
        do{
            ptr=ptr->next;
        }while(ptr->next!=head);
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
}
int Length(){
    struct node *ptr=head;
    int count=0;
    if(head==NULL){
        return 0;
    }
    else{
        do{
            ptr=ptr->next;
            count++;
        }while(ptr!=head);
        return count;
    }
}

void insert_mid(int newdata , int index){
    int len=Length();
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    else if(index>len || index <0){
        cout<<"Wrong input, Insertion is not possible"<<endl;
    }
    else if(index==0){
        insert_beg(newdata);
    }
    else if(index==len){
        insert_end(newdata);
    }
    else{
        len=0;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        struct node*ptr=head;
        do{
            ptr=ptr->next;
        }while(ptr->next!=head);
        while(1){
            if(len==index){
                newnode->data=newdata;
                newnode->next=ptr->next;
                ptr->next=newnode;
                break;
            }
            ptr=ptr->next;
            len++;
        }
    }

}
void Display(){
    struct node *ptr;
    if(head==NULL){
        cout<<"linked list is Empty"<<endl;
        
    }
    ptr=head;
    do{
        cout<<ptr->data<< " ";
        ptr=ptr->next;

    }while(ptr!=head);
    cout<<" "<<endl;
}
int main(){
    insert_beg(5);
    insert_beg(4);
    insert_beg(3);
    insert_beg(2);
    insert_beg(1);
    
    // insert_end(6);
    int length=Length();
    cout<<"Length is : "<<length<<endl;
    cout<<"Original linked list: " <<endl;
    Display();
    cout<<"result"<<endl;
    // insert_mid(10,3);
    // insert_mid(10,9);
    // insert_mid(10,1);
    insert_mid(10,0);
    Display();
    return 0;
}
