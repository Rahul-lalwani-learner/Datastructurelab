#include <iostream>

using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node *front=NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
struct node *rear=NULL;
struct node*temp;
void Insert(){
    int val;
    cout<<"Insert int element in queue: ";
    cin>>val;
    if(front==NULL){
        rear=(struct node*)malloc(sizeof(struct node));
        rear->next=NULL;
        rear->data=val;
        front=rear;
    }
    else {
        temp=(struct node*)malloc(sizeof(struct node));
        rear->next=temp;
        temp->data=val;
        temp->next=NULL;
        rear=temp;
    }
}
void Delete(){
    temp=front;
    if(front ==NULL){
        cout<<"UnderFlow"<<endl;
        return;
    }
    else if(temp->next==NULL){
        temp=temp->next;
        cout<<"Element Deleted front queue is: "<<front->data<<endl;
        free(front);
        front=temp;
    }
    else{
        cout<<"element deleted front Queue is: "<<front->data<<endl;
        free(front);
        front=NULL;
        rear=NULL;
    }
}
int main(){
    
    return 0;
}
