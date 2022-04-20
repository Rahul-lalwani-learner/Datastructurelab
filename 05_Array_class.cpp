#include <iostream>

using namespace std;

class ArrClass{
    public:
    bool find_int(int *arr,int num,int size){
        for(int i=0;i<size;i++){
            if(arr[i]==num){
                return true;
            }
        }
        return false;
    }

    int * replace(int *arr,int size,int index,int num){
        for(int i=0;i<size;i++){
            if(i==index){
                arr[i]=num;
            }
        }
        return arr;
    }

    void display(int *arr,int size){
        cout<<"[ "; 
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]"<<endl;
    }

    int *sort_asc(int *arr,int size){
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(arr[i]<arr[j]){
                    arr[i]=arr[i]+arr[j];
                    arr[j]=arr[i]-arr[j];
                    arr[i]=arr[i]-arr[j];
                }
            }
        }
        return arr;
    }

    int *sort_dec(int *arr,int size){
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    arr[i]=arr[i]+arr[j];
                    arr[j]=arr[i]-arr[j];
                    arr[i]=arr[i]-arr[j];
                }
            }
        }
        return arr;
    }

};
int main(){
    ArrClass test;
    int arr[]={23,4,3,5,32,40};
    // test.replace(arr,6,3,34);
    // test.display(arr,6);
    // test.sort_asc(arr,6);
    // test.sort_dec(arr,6);
    test.display(arr,6);
    return 0;
}
