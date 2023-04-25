#include<iostream>
using namespace std;

void sum2D(int arr[][20],int rows,int cols,int sum[]){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            sum[j]=sum[j]+arr[i][j];
        }
    }
}

bool compareArray(int arr1[],int arr2[],int n,int m){
    if(m!=n){
        return false;}

        for(int i=0;i<n;i++){
            if(arr1[i]>arr2[i]){
                return false;
            }
        }
    return true;
}

int main(){
    
    int proc;
    cout<<"Enter the number of processes: ";
    cin>>proc;

    int res;
    cout<<"Enter the number of resources: ";
    cin>>res;

    int totalRes[20];
    for(int i=0;i<res;i++){
        cout<<"Enter the total resources for P"<<i<<" ";
        cin>>totalRes[i];
    }

    int allocated[20][20];

    for(int i=0;i<proc;i++){
        cout<<"Enter resource allocation for process: "<<i<<endl;
        for(int j=0;j<res;i++){
            cin>>allocated[i][j];
        }
    }

    int maxRes[proc][res];

    for(int i=0;i<proc;i++){
        for(int j=0;j<res;j++){
            cout<<"Enter maximum resources for process: "<<i<<endl;
            cin>>maxRes[i][j];
        }
    }

    int need[proc][res];

    for(int i=0;i<proc;i++){
        for(int j=0;j<proc;j++){
            need[i][j]=maxRes[i][j]-allocated[i][j];
        }
    }

    int totalAllocated[20];
    sum2D(allocated,proc,res,totalAllocated);

    int available[proc];

    for(int i=0;i<proc;i++){
        available[i]=totalRes[i]-totalAllocated[i];
    }

    int safeState[proc];
    int stateIndex;
    bool isTerminated;
    bool compare;

    while(compare){
        compare=false;
    for(int i=0;i<proc;i++){
            isTerminated=false;
        for(int j=0;j<stateIndex;j++){
            if(safeState[j]==i){
                isTerminated=true;
            }
        }

        if(!isTerminated){
            if(compareArray(need[i],available,res,res)){
                safeState[stateIndex]=i;
                stateIndex++;
                for(int j=0;j<res;j++){
                    available[j]=available[j]+allocated[i][j];
                }
                compare=true;
            }
        }
    }
}

for(int i=0;i<stateIndex;i++){
    cout<<safeState[i];
}

    



}