#include <iostream>

using namespace std;
int top=-1;
void push(int *arr,int *maxstack,int item){
    if(top==-1){
        top+=1;
    }
    arr[top]=item;
    top+=1;
}
void display(int *arr){
    if(top==-1){
        cout<<"This is a empty array"<<endl;
        
    }
    else{
        for(int i=0;i<top;i++){
            cout<<arr[top]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int maxstack=3;
    int *arr;
    push(arr,&maxstack,3);
    display(arr);
    return 0;
}
