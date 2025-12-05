#include<vector>
#include<iostream>
using namespace std;
class UnionFind{ // QuickFind implementation
private:
    int n;
    vector<int> leader;
public:
    UnionFind(){}
    UnionFind(int num):n{num}{
        leader.resize(n);
        for(int i=0; i<n; i++){
            leader[i]=0; //0 means blocked, 1 means open
        }
    }
    void unify(int p, int q){
        for(int i=0; i<n; i++){
            if(leader[i]==leader[p]) leader[i]=leader[q];
        }
    }
    int find(int p){
        return leader[p];
    }
};