#include <iostream>

using namespace std;
int n=5;
int queue[5];
int Front =-1 ,Rear=-1;
void InsertCQ(int val){
    if((Front==0 && Rear == n-1) || (Front == Rear +1)){
        cout<<"Queue is Full"<<endl;
        return ;
    }
    if(Front==-1){
        Front=0,Rear=0;
    }
    else if(Rear == n-1){
        Rear=0;
    }
    else {
        Rear++;
    }
    queue[Rear]=val;
}
void DeleteCQ(){
    if(Front == -1){
        cout<<"Queue is Empty"<<endl;
        return ;
    }
    cout<<"Deleted Element is : "<<queue[Front]<<endl;
    if(Front==Rear){
        Front=-1,Rear = -1;
    }
    else if(Front==n-1){
        Front=0;
    }
    else{
        Front++;
    }
}
void Display(){
    if(Front==-1){
        cout<<"Queue is Empty"<<endl;
        return ;
    }
    int f=Front,r=Rear;
    if(f<=r){
        while(f<=r){
            cout<<queue[f]<<" ";
            f++;
        }
    }
    else {
        while(f<=n-1){
            cout<<queue[f]<<" ";
            f++;
        }
        f=0;
        while(f<=r){
            cout<<queue[f]<<" ";
            f++;
        }
    }
    cout<<endl;

}
int main(){
    cout<<"This is Queue Capacity of this queue is 5 "<<endl;
    int ch;
    do{
        cout<<"1) Insert\n2) Delete\n3) Display\n4) Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: 
                int val;
                cout<<"Enter value of Data: "<<endl;
                cin>>val;
                InsertCQ(val);
                break;
            case 2: 
                DeleteCQ();
                break;
            case 3: 
                Display();
                break;
            case 4: 
                cout<<"Exit"<<endl;
                break;
            default: 
                cout<<"Wrong Input"<<endl;
                break;
        }
    }while(ch!=4);
    return 0;
}
