#include <iostream>
#define capacity 10
using namespace std;
int *arr=(int *)malloc(sizeof(int)*capacity);
int front=-1;
int rear=-1;
int size=0;
void display(){
    if(size<=0){
        cout<<"Queue is empty"<<endl;
    }
    else{
    int i=front;
    while(i<=rear){
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
    }
}
void addElement(int data){
    if(front==-1 && size<capacity){
        rear++;
        arr[rear]=data;
        front++;
        size++;
    }
    else if(size < capacity){
        rear++;
        arr[rear]=data;
        size++;
    }
    else if(rear == capacity -1 && size<capacity){
        rear=0;
        arr[rear]=data;
        size++;
    }
    else if(size>=capacity){
        cout<<"overflow queue"<<endl;
    }
    else {
        cout<<"Some error"<<endl;
    }
}
void deleteElement(){
    if(rear==-1 || size<=0 ){
        cout<<"Queue is Empty"<<endl;
    }
    else if(front < capacity && front > 0){
        cout<<"The element deleted is : "<<arr[front]<<endl;
        front++;
        size--;
    }
    else if(front >= capacity ){
        cout<<"The element deleted is : "<<arr[front]<<endl;
        front=0;
        size--;
    }
    
    else{
        cout<<"The element deleted is : "<<arr[front]<<endl;
        front++;
        size--;
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
            int data;
            cout<<"Enter value of data: ";
            cin>>data;
            addElement(data);
            break;
         case 2: deleteElement();
         break;
         case 3: display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);

    // display();
    return 0;
}
