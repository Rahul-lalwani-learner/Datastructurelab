#include <iostream>

using namespace std;
class CircularLinked{
    typedef struct node {
        int data;
        struct node*next;
        // int index;
    }node;
    int count=0;
    node* head=NULL;
    public: 
        void InsertBeg(int newdata){
            node *newnode= (node *)malloc(sizeof(node));
            if(head==NULL){
                newnode->data=newdata;
                head=newnode;
                newnode->next=head;
                // newnode->index=count;
                // count++;
            }
            else{
                newnode->data=newdata;
                newnode->next=head->next;
                head->next=newnode;
                head=newnode;
                // newnode->index=count;
                // count++;
            }
        }
        void InsertEnd(int newdata){
            node * newnode=(node*)malloc(sizeof(node));
            if(head==NULL){
                newnode->data=newdata;
                head=newnode;
                newnode->next=head;
            }
            else{
                newnode->data=newdata;
                node *ptr=head;
                do{
                    ptr=ptr->next;
                }while(ptr->next!=head);
                newnode->next=ptr->next;
                ptr->next=newnode;
            }
        }
        int Lenght(){
            int len=0;
            if(head==NULL){
                return len;
            }
            else{
                node *ptr=head;
                do{
                    len++;
                    ptr=ptr->next;
                }while(ptr!=head);
                return len;
            }
        }
        void InsertAtIndex(int newdata,int Index){
            int len=Lenght();
            if(head==NULL){
                cout<<"Linked list is Empty"<<endl;
            }
            else if(Index > len || Index <0){
                cout<<"You have Entered Wrong index"<<endl;
            }
            else if(Index==0){
                InsertBeg(newdata);
            }
            else if(Index == len){
                InsertEnd(newdata);
            }
            else{
                len=0;
                node *ptr=head;
                do{
                    ptr=ptr->next;
                }while(ptr->next!=head);
                while(1){
                    if(len==Index){
                        node* newnode=(node*)malloc(sizeof(node));
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
        void InsertAfterData(int newdata,int num){
            if(head==NULL){
                cout<<"Linked list is Empty"<<endl;
            }
            else if(head->data==num){
                        node*ptr=head;
                        node*newnode=(node*)malloc(sizeof(node));
                        newnode->data=newdata;
                        newnode->next=ptr->next;
                        ptr->next=newnode;
            }
            else{
                node*ptr=head;
                // do{
                //     ptr=ptr->next;
                // }while(ptr->next!=head);
                do{
                    if(num==ptr->data){
                        node*newnode=(node*)malloc(sizeof(node));
                        newnode->data=newdata;
                        newnode->next=ptr->next;
                        ptr->next=newnode;
                        break;
                    }
                    ptr=ptr->next;
                }while(ptr!=head);
                if(ptr==head){
                    cout<<"Element not found"<<endl;
                }
            }
        }
        void Display(){
            node*ptr=head;
            if(ptr==NULL){
                cout<<"Linked List is Empty"<<endl;
            }
            else{
                do{
                    // cout<<ptr->data<<" Index : "<<ptr->index<<endl;
                    cout<<ptr->data<<" ";
                    ptr=ptr->next;
                }while(ptr!=head);
                cout<<endl;
            }
            
        }
        void deleteEnd(){
            if(head==NULL){
                cout<<"Linked list is empty"<<endl;
            }
            else if(head->next==head){
                node *ptr=head;
                cout<<"Deleted Element is : "<<head->data<<endl;
                free(ptr);
                head=NULL;
            }
            else{
                node *ptr=head;
                node *preptr=ptr;
                do{
                    preptr=ptr;
                    ptr=ptr->next;
                }while(ptr->next!=head);

                preptr->next=ptr->next;
                head=preptr->next;
                cout<<"Deleted element is: "<<ptr->data<<endl;
                free(ptr);
            }
            
        }
        void deleteIndex(int Index){
            int len=Lenght();
            if(head==NULL){
                cout<<"Linked list is empty"<<endl;
            }
            else if(Index>len-1 || Index<0){
                cout<<"Wrong Input for Index"<<endl;
            }
            else if(Index==0){
                deleteBeg();
            }
            else if(Index==len-1){
                deleteEnd();
            }
            else{
                len=0;
                node *ptr=head;
                node *preptr=ptr;
                // do{
                //     ptr=ptr->next;
                // }while(ptr->next!=head);
                while(1){
                    if(len==Index){
                        preptr->next=ptr->next;
                        cout<<"Deleted Element is: "<<ptr->data<<endl;
                        free(ptr);
                        break;
                    }
                    preptr=ptr;
                    ptr=ptr->next;
                        len++;
                }
            }
        }
        void deleteAtData(int num){
            if(head==NULL){
                cout<<"Linked list is empty"<<endl;
            }
            else if(head->data==num){
                deleteBeg();
            }
            else{
                node *ptr=head;
                node *preptr=ptr;
                // do{
                //     ptr=ptr->next;
                // }while(ptr->next!=head);
                do{
                    if(ptr->data==num){
                        preptr->next=ptr->next;
                        cout<<"Deleted Element is: "<<ptr->data<<endl;
                        free(ptr);
                        break;
                    }
                    preptr=ptr;
                    ptr=ptr->next;
                }while(ptr!=head);
                if(ptr==head){
                    cout<<"Data not found"<<endl;
                }
            }
        }
        void deleteBeg(){
            if(head==NULL){
                cout<<"Linked list is empty"<<endl;
            }
            else if(head->next==head){
                node *ptr=head;
                cout<<"Deleted element is: "<<ptr->data<<endl;
                free(ptr);
                head=NULL;
            }
            else{
                node *ptr=head;
                node *last=head;
                do{
                    last=last->next;
                }while(last->next!=head);
                last->next=ptr->next;
                head=ptr->next;
                cout<<"Deleted element is: "<<ptr->data<<endl;
                free(ptr);
            }

        }
};
int main(){
    CircularLinked obj;
    // obj.InsertBeg(1);
    // obj.InsertBeg(2);
    obj.InsertEnd(5);
    obj.InsertEnd(6);
    obj.InsertEnd(7);
    obj.InsertEnd(8);
    obj.InsertEnd(9);
    obj.InsertEnd(10);
    // obj.deleteAtData(12);
    // obj.deleteIndex(6);
    // obj.deleteEnd();
    // obj.deleteBeg();
    // obj.InsertBeg(3);
    // obj.InsertAtIndex(23,3);
    obj.InsertAfterData(23,5);
    // cout<< obj.Lenght()<<endl;
    obj.Display();
    return 0;
}
