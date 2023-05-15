#include<iostream>
using namespace std;

class MaxClique{
    int adj[10][10];
    //adjacency matrix for the graph//
    int visited[10];
    int bestvisited[10];
    int clique;
    int bestClique;
    int n;

    public:

    MaxClique(int adjmat[][10],int no_of_vertices){
        
        n=no_of_vertices;
        for(int i=0;i<n;i++){
            visited[i]=0;
            bestvisited[i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
            adj[i][j]=adjmat[i][j];
            }
        }

        clique=0;
        bestClique=0;
    }

    void solve(int currVertex){

        //terminating condition//
        if(currVertex>n){
            if(clique > bestClique){
                for(int i=1;i<=n;i++){
                    bestvisited[i]=visited[i];
                }
                bestClique=clique;
            }
            return;
        }

        bool accept=true;

        for(int j=1;j<currVertex;j++){
            
            if(visited[j]==1 && adj[currVertex][j]==0){
                accept=false;
                break;
            }
        }

        if(accept){
            visited[currVertex]=1;
            clique++;
            solve(currVertex+1);
            clique--;
        }
        solve(currVertex+1);
    }

    void display(){

        cout<<"Number of vertices in max clique: ";
        cout<<bestClique;
        cout<<endl;

        cout<<"Vertices in best clique: ";
        cout<<endl;
        for(int i=1;i<=n;i++){
            if(bestvisited[i]==1){
                cout<<i<<" ";
            }
        }
    }
};

int main(){

    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;

    int adjmat[10][10];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adjmat[i][j]=0;
        }
    }

    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    int p,q;
    for(int i=1;i<=edges;i++){
        cout<<"Enter edge: ";
        cin>>p;
        cin>>q;
        adjmat[p][q]=1;
        adjmat[q][p]=1;
    }

    MaxClique m1(adjmat,n);
    m1.solve(1);
    m1.display();

    return 0;
}
