#include<iostream>
#include<vector>

using namespace std;

class Disjoint{

    public:

    vector<int> rank,parent,size;
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUparent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }

    void unionByRank(int u,int v){
        int uP_u = findUparent(u);
        int uP_v = findUparent(v);

        // Both nodes Belonging to same component
        if(uP_u == uP_v) return;


        if(rank[uP_u] > rank[uP_v]){
            parent[uP_v] = uP_u;
        }
        else if(rank[uP_v] > rank[uP_u]){
            parent[uP_u] = uP_v;
        }
        else{
            parent[uP_v] = uP_u;
            rank[uP_u]++;

        }
    }

    void unionBySize(int u,int v){
        int uP_u = findUparent(u);
        int uP_v = findUparent(v);

        // Both nodes Belonging to same component
        if(uP_u == uP_v) return;


        if(size[uP_u] > size[uP_v]){
            parent[uP_v] = uP_u;
            size[uP_u] += size[uP_v];
        }
        else if(size[uP_v] > size[uP_u]){
            parent[uP_u] = uP_v;
            size[uP_v] += size[uP_u];

        }
        else{
            parent[uP_v] = uP_u;
            size[uP_u] += size[uP_v];
        }
    }
};

int main(){
    int n = 7;
    Disjoint ds(n);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findUparent(3) == ds.findUparent(7)){
        cout<<"Belong to Same component\n";
    }
    else
        cout<<"Not belong to the Same Componenet\n";

    ds.unionBySize(3,7);

    if(ds.findUparent(3) == ds.findUparent(7)){
        cout<<"Belong to Same component\n";
    }
    else
        cout<<"Not belong to the Same Componenet\n";

    cout<<"Size : \n";
    for(auto x : ds.size){
        cout<<x<<" ";
    }

    cout<<"\nParent : \n";
    for(auto x : ds.parent){
        cout<<x<<" ";
    }
}