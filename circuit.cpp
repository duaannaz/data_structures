#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V,vector<int>(V,0));
    }

    void addEdge(int u, int v)
    {
        adj[u][v]=1;
        adj[v][u]=1;
    }

    int tD(){
        int n;
        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                if(adj[i][j]==1){
                    for(int k=)
                }
            }
        }
    }
};

int main()
{
    int M, N, u, v;
    cin >> N >> M;
    Graph G1(N);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        G1.addEdge(u, v);
    }
    cout << G1.isCycleDFS();
    return 0;
}