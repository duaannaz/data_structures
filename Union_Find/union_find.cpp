#include<bits/stdc++.h>
using namespace std;

class QuickFind{
    private:
        int n;
        int* leader;
    public:
        QuickFind(int s):n{s},leader{new int[n]}{
            for(int i=0; i<n; i++){ //time complexity O(n)
                leader[i]=i;
            }
        }
        ~QuickFind(){
            delete[] leader;
        }
        int find(int p){ //time complexity O(1)
            return leader[p];
        }
        void unify(int p, int q){ //time complexity O(n)
            for(int i=0; i<n; i++){
                if(leader[i]==leader[p]) leader[i]=leader[q];
            }
        }
};

class QuickUnion{
    private:
        int n;
        int* parent;
    public:
        QuickUnion(int s):n{s},parent{new int[n]}{
            for(int i=0; i<n; i++){ //time complexity O(n)
                parent[i]=i;
            }
        }
        ~QuickUnion(){
            delete[] parent;
        }
        int find(int p){ //time complexity = depth of node worst case O(n)
            while(p!=parent[p]){
                p=parent[p];
            }
            return p;
        }
        void unify(int p, int q){ //time complexity when given roots O(1)
            int i=find(p);
            int j=find(q);
            parent[i]=j;
        }
};

class WeightedUnion{
    private:
        int n;
        int* parent;
        int* size;
    public:
        WeightedUnion(int s):n{s},parent{new int[n]},size{new int[n]}{
            for(int i=0; i<n; i++){ //time complexity O(n)
                parent[i]=i;
                size[i]=i;
            }
        }
        ~WeightedUnion(){
            delete[] parent;
        }
        int find(int p){ //time complexity = depth of node which in this case O(log n)
            while(p!=parent[p]){
                p=parent[p];
            }
            return p;
        }
        void unify(int p, int q){ //time complexity when given roots O(1)
            int i=find(p);
            int j=find(q);

            if(i==j) return;
            if(size[i]>size[j]) {int temp=i; i=j; j=temp;}
            parent[i]=j;
            size[i]+=size[j];
        }
};