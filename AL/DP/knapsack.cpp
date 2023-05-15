#include<iostream>
using namespace std;

void knapsack(int profit[],int weight[],int cap,int n){

    int knap[n+1][cap+1];
    int j;

    for(int i=0;i<=n;i++){
        for(j=0;j<=cap;j++){

            //condition if no itemselected or bag capacity is 0//
            if(i==0||j==0){
                knap[i][j]=0;
            }

            else if(weight[i]<=j){
                knap[i][j]=max(profit[i]+knap[i-1][j-weight[i]],knap[i-1][j]);
                //formula//
            }

            else{
                knap[i][j]=knap[i-1][j];
                /*it means that weight of the current object is 
                exceeding the bag capacity*/
            }
        }
    }

    int i=n;
    j=cap;

    while(i>0 && j>cap){

        if(knap[i][j]==knap[i-1][j]){
            i--;
        }
        else{
            cout<<i;
            j=j-weight[i];
            i--;
        }
    }

    cout<<"MAX PROFIT: ";
    cout<<knap[n][j];
}

int main(){

    int n;
    int cap;
    int profit[10];
    int weight[10];
    cout<<"Enter the number of items: ";
    cin>>n;

    profit[0]=0;
    weight[0]=0;

    cout<<"Enter the weight and profit of each item: ";
    for(int i=1;i<=n;i++){
        cout<<"Enter profit: ";
        cin>>profit[i];
        cout<<endl;
        cout<<"Enter weight: ";
        cin>>weight[i];
    }

    cout<<"Enter the knapsack capacity: ";
    cin>>cap;

    knapsack(profit,weight,cap,n);

    return 0;
}