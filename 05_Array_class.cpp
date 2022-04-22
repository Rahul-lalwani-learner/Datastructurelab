#include <iostream>

using namespace std;
class ArrClass{
    int size=0;
    public:
    bool find_int(int *arr,int num){
        for(int i=0;i<size;i++){
            if(arr[i]==num){
                return true;
            }
        }
        return false;
    }

    int * replace(int *arr,int index,int num){
        for(int i=0;i<size;i++){
            if(i==index){
                arr[i]=num;
            }
        }
        return arr;
    }
    void append(int *arr,int num){
        arr[size]=num;
        size++;
    }
    void display(int *arr){
        if(size==0){
            cout<<"Array is empty"<<endl;
        }
        else{

        cout<<"[ "; 
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]"<<endl;
        }
    }

    int *sort_asc(int *arr){
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
    void insert(int *arr,int index,int num){
        int j=size;
        size++;
        while(j>=index){
            arr[j+1]=arr[j];
            j--;
        }
        arr[index]=num;

    }
    void del(int *arr,int index){
        int j=index;
        while(j<=size){
            arr[j]=arr[j+1];
            j++;
        }
        size--;

    }
    int *sort_dec(int *arr){
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
    ArrClass test,second;
    int *arr=(int *)calloc(100,sizeof(int));
    int *array=(int *)calloc(100,sizeof(int));
    test.append(arr,1);
    test.append(arr,2);
    test.append(arr,3);
    test.append(arr,4);
    test.append(arr,5);
    test.append(arr,6);
    second.append(array,23);
    second.append(array,23);
    second.append(array,23);
    // test.replace(arr,3,34);
    // test.replace(arr,6,3,34);
    // test.display(arr,6);
    // test.sort_asc(arr);
    // test.sort_dec(arr);
    // test.insert(arr,2,34);
    // test.del(arr,3);
    test.display(arr);
    second.display(arr);
    return 0;
}
