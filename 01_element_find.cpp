#include <iostream>

using namespace std;

int main(){
    int arr[]={34,32,5,3,5,3,5,2};
    int num;
    cout<<"enter number to search : ";
    cin>>num;
    int p=0;
    int i;
    for( i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i]==num){
            p=1;
            break;
        }
    }
    if(p){
        cout<<"number is present at index "<<i+1<<endl;
    }
    else{
        cout<<"number is not present"<<endl;
    }
    return 0;
}
