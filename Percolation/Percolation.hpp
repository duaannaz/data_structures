#include "unionFind.hpp"
class Percolation {
private:
    int n,opened;
    vector<vector<int>> arr;
    UnionFind System;
public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n):System(n*n+2){
        if(n<=0) throw std::invalid_argument("n should be greater than 0");
        this->n=n;
        this->arr=vector<vector<int>>(n,vector<int>(n,0));
        opened=0;
    }

    // opens the site (row, col) if it is not open already
    void open(int row, int col){
        if(row<0 || col<0 || row>n-1 || col>n-1) throw std::invalid_argument("Boundary Error");
        int idx=(row*n)+col;
        if(!isOpen(row,col)){
            arr[row][col]=1;
            if(row==0) System.unify(idx,n*n);
            if(row==n-1) System.unify(idx,n*n+1);
            
        }
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col){
        return arr[row][col];
    }
    
    // is the site (row, col) full?
    bool isFull(int row, int col);
    
    // returns the number of open sites
    int numberOfOpenSites();
    
    // does the system percolate?
    bool percolates();
    
    // unit testing (required)
    static void test();
};
