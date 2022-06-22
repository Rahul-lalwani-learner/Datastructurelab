#include <iostream>

using namespace std;
/*
1. [Linked queue empty?] if(Front ==NULL) then write. UnderFlow and Exit
2. Set Temp=Front
3. Item=temp->info
4. Front=Front->link
5. Temp->link=Avail and Avial = temp
6. Exit
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
*/
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
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1:
            int val;
            cout<<"Enter data: ";
            cin>>val; 
            Insert(val);
            break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
    return 0;
}
