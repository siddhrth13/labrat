#include<bits/stdc++.h>
using namespace std;

void tsp(int graph[][10], vector<bool>& visited , int currPos,int n,int count,int cost,int& ans){

    if(count==n && graph[currPos][0]){

        ans= min(ans,cost+graph[currPos][0]);
        return;

    }

    for(int i=0;i<n;i++){
        if(!visited[i] && graph[currPos][i]){
            visited[i]=true;
            
            tsp(graph,visited,i,n,count+1,cost+graph[currPos][i],ans);

            visited[i]=false;

        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    int graph[10][10];

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    int p,q;
    int edgeWeight;
    for(int i=0;i<e;i++){
        cout<<"Enter edge"<<endl;
        cin>>p;
        cin>>q;
        cout<<"Enter edge weight: "<<endl;
        cin>>edgeWeight;
        graph[p][q]=edgeWeight;
        graph[q][p]=edgeWeight;
    }

    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    //marking all the nodes as unvisited//

    visited[0]=true;
    int ans=99;

    tsp(graph,visited,0,n,1,0,ans);

    cout<<ans;

    return 0;   

}