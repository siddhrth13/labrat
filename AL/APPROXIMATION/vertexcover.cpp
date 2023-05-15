#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of verticies: ";
    cin>>n;

    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    int adj[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }

    bool visited[10];

    for(int i=0;i<n;i++){
        visited[i]=false;
    }


    for(int i=0;i<n;i++){
        if(!visited[i]){
            for(int j=0;j<n;j++){
                if(!visited[j] && adj[i][j]==1){
                    visited[i]=true;
                    visited[j]=true;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        if(visited[i]){
            cout<<i<<" ";
        }
    }
}