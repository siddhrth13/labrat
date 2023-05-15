#include<iostream>
using namespace std;

class MinMax{
    int min;
    int max;

public:
    
    MinMax solve(int arr[],int low,int high){

        MinMax result,leftResult,rightResult;

        if(low==high){
            result.min=arr[low];
            result.max=arr[high];
            return result;
        }

        if(low==high+1){
            if(arr[low]<arr[high]){
                result.min=arr[low];
                result.max=arr[high];
            }
            else{
                result.min=arr[high];
                result.max=arr[low];
            }

            return result;
        }

        int mid;
        mid=(low+high)/2;

        leftResult=solve(arr,low,mid);
        rightResult=solve(arr,mid+1,high);

        if(leftResult.min<rightResult.min){
            result.min=leftResult.min;
        }
        else{
            result.min=rightResult.min;
        }

        if(leftResult.max>rightResult.max){
            result.max=leftResult.max;
        }
        else{
            result.max=rightResult.max;
        }

        return result;
        
    }

    void display(MinMax res){

        cout<<"Maximum element: ";
        cout<<res.max;
        cout<<endl;
        cout<<"Minimum element: ";
        cout<<res.min;
    
    }
};

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[10];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    MinMax m1;

    
    m1.display(m1.solve(arr,0,n-1));

    return 0;
}