#include <iostream>

using namespace std;
struct node{
    int data;
    struct node * next;
};
struct node * top=NULL;
void push(int newdata){
    struct node *newnode=(struct node  *)malloc(sizeof(struct node));
    if(newnode!=NULL){
        newnode->data=newdata;
        newnode->next=top;
        top=newnode;
    }
    else{
        cout<<"No memory allocated"<<endl;
    }
}
void pop(){
    if(top!=NULL){
        cout<<"The popped data is : "<< top->data <<endl;
        struct node * ptr=top;
        top=top->next;
        free(ptr);
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}
void display(){
    if(top!=NULL){
        cout<<"Elements in the Stack are : "<<endl;
        struct node * ptr=top;
        while(ptr!=NULL){
            cout<< ptr->data <<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}
int main(){
    // display();
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    display();
    return 0;
}
