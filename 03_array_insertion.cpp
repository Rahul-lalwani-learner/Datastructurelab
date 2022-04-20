#include <iostream>

using namespace std;
void display(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100];
    int size=10,index,num,j;
    for(int i=0;i<size;i++){
        arr[i]=i+1;
    }
    display(arr,size);
    j=size;
    cout<<"Enter index and number that you want to insert: ";
    cin>>index>>num;
    while(j>=index){
        arr[j+1]=arr[j];
        j--;
    }
    arr[index]=num;
    size++;
    display(arr,size);
    return 0;
}
