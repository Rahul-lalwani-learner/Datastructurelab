#include <iostream>

using namespace std;
int top=-1;
const int size=100;
int arr[size];

void push(int val){
    if(top>=size-1){
        cout<<"Array is overflowing"<<endl;
    }
    else{
        top++;
        arr[top]=val;
    }
}
void pop(){
    if(top<=-1){
        cout<<"Array is empty"<<endl;
    }
    else{
        cout<<arr[top]<<" element is popped "<<endl;
        int *ptr=&arr[top];
        free(ptr);
        top--;
    }
}
void display(){
    if(top<=-1){
        cout<<"Array is empty"<<endl;
    }
    else{
        cout<<"The elements in the stack are: "<<endl;
        cout<<"[ ";
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<"]"<<endl;
    }
}
int main(){
    int choice;
    do{
        cout<<endl;
        
        cout<<"DashBoard"<<endl;
        cout<<"1. push \n2. pop\n3. display\n4. exit"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"-------------------------"<<endl;
            int val;
            cout<<"Enter number to be pushed : ";
            cin>>val;
            push(val);
            break;
        
        case 2:
            cout<<"-------------------------"<<endl;
            pop();
            break;

        case 3:
            cout<<"-------------------------"<<endl;
            display();
            break;
        case 4:
            cout<<"-------------------------"<<endl;
            cout<<"EXIT"<<endl;
            break;
        default:
            cout<<"-------------------------"<<endl;
            cout<<"Wrong Choice"<<endl;
            break;
        }

    }while(choice!=4);
    return 0;
    return 0;
}
