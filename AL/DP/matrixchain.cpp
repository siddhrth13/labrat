#include<iostream>
#include<climits>
using namespace std;

void matrixchain(int p[],int n){
    int m[10][10];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            m[i][j]=0;
        }
    }

    int j,min,q;

    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){
            j=i+d;
            min=INT_MAX;
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<min){
                    min=q;
                }
            }
            m[i][j]=min;
        }
    }

    cout<<"Optimal order of multiplication: ";
    cout<<m[1][n-1];

    cout<<endl;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;

    int m=n+1;

    int p[10];
    cout<<"Enter the dimensions: ";
    for(int i=0;i<m;i++){
        cin>>p[i];
    }

    matrixchain(p,m);

    return 0;
}