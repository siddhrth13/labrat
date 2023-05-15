#include<iostream>
using namespace std;


void apsp(int graph[][10],int n,int src){

    int dist[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=graph[i][j];
        }
    }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //unreachable case: //
                if(dist[src][i]==99 || dist[i][j]==99){
                    continue;
                }

                //case you the distance is less than through intermediate node//
                else if(dist[src][i]+dist[i][j]<dist[src][j]){
                    dist[src][j]=dist[src][i]+dist[i][j];
                }

            }
        }
    

    
        for(int j=0;j<n;j++){
            cout<<src<<"--"<<j<<": "<<dist[src][j];
            cout<<endl;
        }
    
}

int main(){

    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;

    int graph[10][10];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=99;
            }
        }
    }

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    int p,q;
    int edgeweight;
    for(int i=0;i<e;i++){
        cout<<"Enter edge: ";
        cin>>p;
        cin>>q;
        cout<<"Enter edge weight: ";
        cin>>edgeweight;
        graph[p][q]=edgeweight;
        graph[q][p]=edgeweight;
    }

    int src;
    cout<<"Enter source: ";
    cin>>src;

    apsp(graph,n,src);

    return 0;
}