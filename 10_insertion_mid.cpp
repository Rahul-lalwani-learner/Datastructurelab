#include <iostream>

using namespace std;
struct node{
    int data;
    struct node * next;
};
struct node *head=NULL;
void insert(int new_data){
    struct node *new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=head;
    head=new_node;
}
void insert_end(int new_data){
    struct node *new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=NULL;
    struct node*ptr;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
}
void display(){
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

void insert_mid(int new_data, int num){
    struct node *new_node= (struct node * )malloc(sizeof(struct node ));
    new_node->data=new_data;
    struct node *ptr=head;
    struct node *preptr=ptr;
    while(preptr->data!=num){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;

}
int main(){
    insert(3);
    insert_end(342);
    insert_end(3442);
    insert_end(34);
    insert_mid(78,342);
    display(); 
    return 0;
}
