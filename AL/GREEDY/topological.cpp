#include<iostream>
#include<stack>
using namespace std;


void dfs(int adj[][10],int n,bool visited[],stack<int> &s,int u){
    visited[u]=true;

    for(int i=1;i<n;i++){
        if(visited[i]==false && adj[i][u]==1){
            dfs(adj,n,visited,s,i);
        }
    }
    s.push(u);
}

void topologicalsort(int adj[][10],int n){
    stack<int> s;
    bool visited[10];

    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfs(adj,n,visited,s,i);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;

    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    int p,q;
    int arr[10][10];
    for(int i=0;i<edges;i++){
        cout<<"Enter edge: ";
        cin>>p;
        cin>>q;
        arr[p][q]=1;
        arr[q][p]=1;
    }

    topologicalsort(arr,n);

    return 0;
}