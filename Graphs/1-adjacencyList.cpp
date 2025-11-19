#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // bfs traversal
    void bfs(){ // O(V+E)
        queue<int> q;
        vector<bool> visited(V,false);
        q.push(0);
        visited[0]=true;
        cout<<"BFS Traversal: \n";
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v:l[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                    // cout<<v<<" ";
                }
            }
        }
    }

    // dfs traversal
    void DFS(){ 
        int u=0;
        vector<bool> visited(V,false);
        // visited[0]=true;
        cout<<"DFS Traversal:\n";
        dfs(u,visited);
    }
    void dfs(int u,vector<bool> &visited){ // O(V+E)
        cout<<u<<" ";
        visited[u]=true;
        for(int v:l[u]){
            if(!visited[v]){
                dfs(v,visited);
            }
        }
    }

    bool isCycle(){
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(cycleDetectDFS(i,-1,visited)) return true;
            }
        }
        return false;
    }
    bool cycleDetectDFS(int u,int par,vector<bool> &visited){ // O(V+E)
        visited[u]=true;
        for(int v:l[u]){
            if(!visited[v]){
                if(cycleDetectDFS(v,u,visited)) return true;
            }
            else{
                if(v!=par) return true;
            }
        }
        return false;
    }
    void printAdjList(){
        for(int i=0; i<V; i++){
            cout<<i<<": ";
            for(int neigh:l[i]){
                cout<<neigh<<" ";
            }
            cout<<"\n";
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3); //cycle
    g.addEdge(4,2);
    g.addEdge(3,1);
    // g.printAdjList();
    // g.bfs();
    // g.DFS();
    cout<<g.isCycle();
    return 0;
}