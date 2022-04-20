#include <iostream>

using namespace std;
void display(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100],size=10,j,index;
    j=size;
    for(int i=0;i<size;i++){
        arr[i]=i+1;
    }
    display(arr,size);
    cout<<"Enter the index that you want to delete: ";
    cin>>index;
    while(index<size){
        arr[index]=arr[index+1];
        index++;
    }
    size--;
    // while(j>index){
    //     arr[j-1]=arr[j];
    //     j--;
    // }
    // size--;
    display(arr,size);
    
    return 0;
}
