#include <iostream>

using namespace std;
struct node {
    int data;
    struct node*next;
};
struct node *head=NULL;
void insert(int new_data){
    struct node * new_node= (struct node * )malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=head;
    head=new_node;
}
void display(){
    struct node *ptr;
    ptr=head;
    while (ptr!=NULL)       
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    
}
void search(int data){
    struct node*ptr;
    ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data==data){
            count++;
        }
        ptr=ptr->next;
    }
    if(count){
        cout<<data<<" is present in linked list where count is : "<<count<<endl;
    }
    else{
        cout<<data<<" not found"<<endl;
    }
}
int main(){
    insert(34);
    insert(3);
    insert(64);
    insert(89);
    insert(9);
    insert(9);
    insert(9);
    search(9);
    display();


    return 0;
}
