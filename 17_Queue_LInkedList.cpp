#include <iostream>

using namespace std;
struct node{
    int info;
    struct node*link;
};
struct node*head=NULL;
struct node*rear=NULL;
void Insert(int item){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=item;
    newnode->link=NULL;
    if(head==NULL){
        head=rear=newnode;
    }
    else{
        rear->link=newnode;
        rear=newnode;
    }
}
void Display(){
    if(head==NULL){
        cout<<"Queue is Empty"<<endl;
        return ;
    }
    else{
        struct node*ptr=head;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        }
        cout<<endl;
    }
}
void Delete(){
    if(head==NULL){
        cout<<"Queue is Empty"<<endl;
        return ;
    }
    cout<<"Element deleted is : "<<head->info<<endl;
    if(head==rear){
        struct node*ptr=head;
        free(ptr);
        head=rear=NULL;
    }
    else{
        struct node*ptr=head;
        head=head->link;
        free(ptr);
    }

}
int main(){
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Delete();
    Display();
    return 0;
}
