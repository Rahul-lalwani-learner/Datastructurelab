#include <iostream>

using namespace std;
struct node {
    int data;
    struct node * next;
};
struct node * head=NULL;
void insertbeg(int data){
    struct node *ptr=(struct node * )malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
}
void display(){
    struct node *ptr=head;
    while(ptr!=NULL){
        cout<< ptr->data <<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void swap_alternate(){
    struct node*ptr=head;
    struct node *nxt=head->next;
    while((ptr->next !=NULL) && (nxt->next!=NULL)){
        int temp=ptr->data;
        ptr->data=nxt->data;
        nxt->data=temp;
        // ptr=ptr->next;
        // nxt=ptr->next;
        // cout<<ptr->data<<" "<<ptr->next->data<<endl;
        ptr=ptr->next->next;
        nxt=nxt->next->next;
    }

}
int main(){
    insertbeg(60);
    insertbeg(50);
    insertbeg(40);
    insertbeg(30);
    insertbeg(20);
    insertbeg(10);
    // insertbeg(0);
    // insertbeg(-10);
    // insertbeg(-20);
    // insertbeg(-30);
    cout<<"Original Linked list is : "<<endl;
    display();
    cout<<"Linked list After Swap function is : "<<endl;
    swap_alternate();
    display();
    return 0;
}
