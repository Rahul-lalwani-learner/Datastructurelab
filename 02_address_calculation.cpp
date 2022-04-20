#include <iostream>

using namespace std;

int main(){
    int row, col;
    cout<<"Enter row and col of matrix: ";
    cin>>row>>col;
    int lowBoundX, lowBoundY,size,baseAdd;
    cout<<"Enter lower bound(X , Y) : ";
    cin>>lowBoundX>>lowBoundY;
    cout<<"Enter size : ";
    cin>>size;
    cout<<"Enter Base address: ";
    cin>>baseAdd;
    int address, indexX, indexY, choice;
    cout<<"Enter index for which you want to find addresss: ";
    cin>>indexX>>indexY;
    cout<<"Your want to find row wise or col wise addresss\n 1. row wise \n 2. col wise \n Enter your choice: ";
    cin>>choice;
    if(choice == 1){
        address= ((indexX-lowBoundX)*col+ (indexY-lowBoundY))*size+baseAdd;
        cout<<"The row wise Address of index "<<indexX<<" "<<indexY<<" is : "<<address<<endl;
    }
    else if(choice == 2){
        address= ((indexY-lowBoundY)*row+ (indexX-lowBoundX))*size+baseAdd;
        cout<<"The row wise Address of index "<<indexX<<" "<<indexY<<" is : "<<address<<endl;
    }
    else{
        cout<<">>>>>>>>>>>>>>>>Enter correct choice<<<<<<<<<<<<<<<<";
    }
    return 0;
}
