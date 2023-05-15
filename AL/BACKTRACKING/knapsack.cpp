#include<iostream>
#include<vector>
using namespace std;

int maxProfit=0;
vector<int> selected;

void knapsack(int profit[],int weight[],int cap,int n,int currProfit,int currWeight,int index){

    if(index>=n || currWeight>cap){
        return;
    }
    //terminating condition//

    if(currProfit>maxProfit){
        maxProfit=currProfit;
    }
    
    knapsack(profit,weight,cap,n,currProfit+profit[index],currWeight+weight[index],index+1);
    //applying knapsack by including the current Item//

    knapsack(profit,weight,cap,n,currProfit,currWeight,index+1);
    //applying knapsack by excluding the curent item//
}

int main(){
    int n;
    cout<<"Enter the number of items";
    cin>>n;

    int profit[20];
    int weight[20];
    cout<<"Enter the profit and weight for each item: ";
    for(int i=0;i<n;i++){
        cin>>profit[i];
        cin>>weight[i];
    }
    
    int cap;
    cout<<"Enter the knapsack capacity: ";
    cin>>cap;

    knapsack(profit,weight,cap,n,0,0,0);
    

    cout<<endl;
    cout<<"MAX PROFIT: "<<maxProfit;

    return 0;

}