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
void display(){
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    insert(3);
    insert(34);
    insert(4);
    insert(56);
    display();   
    return 0;
}
