#include<iostream>
using namespace std;

int maxWeight=0;

void containerloading(int weights[],int n,int cap,int currWeight,int index){

    if(index>=n || currWeight>cap){
        return;
    }

    if(currWeight>maxWeight){
        maxWeight=currWeight;
    }

    containerloading(weights,n,cap,currWeight+weights[index],index+1);

    containerloading(weights,n,cap,currWeight,index+1);
}

int main(){
    int n;
    cout<<"enter the number of containers:";
    cin>>n;

    int weights[10];
    int cap;
    cout<<"Enter the capacity of the ship: ";
    cin>>cap;

    for(int i=0;i<n;i++){
        cout<<"Enter weight: ";
        cin>>weights[i];
    }

    containerloading(weights,n,cap,0,0);

    cout<<"MAX Weight accomodated: ";
    cout<<maxWeight;

    return 0;
}