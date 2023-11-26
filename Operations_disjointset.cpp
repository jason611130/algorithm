#include<iostream>

class DisjSet{
    private:
        int *parent,n,*rank;
    public:
        DisjSet(int n){
            rank = new int[n];
            parent = new int[n];
            this->n = n;
            makeSet();
        }
        void makeSet(){
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int a){
            if(parent[a]!=a){
                find(parent[a]);
            }
            return parent[a];
        }
        void Union(int a,int b){
            int xset = find(a);
            int yset = find(b);

            if(xset==yset){
                return;
            }
            if(rank[xset]<rank[yset]){
                rank[xset] = rank[yset];
            }
            else if(rank[xset]>rank[yset]){
                rank[yset] = rank[xset];
            }
            else{
                parent[yset] = xset;
                rank[xset] = rank[xset] + 1;
            }
        }
};

int main(){
    
}