//{ Driver Code Starts
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> getGraph(int &n);

class Disjoint{
    public:
    vector<int> parent,size;

    Disjoint(int n){

        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int uP_u = findUParent(u);
        int uP_v = findUParent(v);

        // Both nodes Belonging to same component
        if(uP_u == uP_v) return;

        if(size[uP_u] > size[uP_v]){
            parent[uP_v] = uP_u;
            size[uP_u] += size[uP_v];
        }
        else{
            parent[uP_v] = uP_u;
            size[uP_u] += size[uP_v];
        }
    }
};



int main(){
    int n;
    vector<vector<int>> G = getGraph(n);

    // {{weight,u,v},...}
    vector<vector<int>> Edges;

    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){

            if(G[u][v] == 0 || G[u][v] == 999){
                // skip , no edge
                continue;
            }
            Edges.push_back({G[u][v],u,v});
        }
    }

    sort(Edges.begin(),Edges.end());

    // cout<<"Edges:\n";
    // for(auto e : Edges){
    //     cout<<e[0]<<"\t"<<e[1]<<"\t"<<e[2]<<"\n";
    // }

    Disjoint ds(n);
    vector<vector<int>> MST;
    int mstCost = 0;
    for(auto e : Edges){
        int wt = e[0];
        int u = e[1];
        int v = e[2];

        if(ds.findUParent(u) == ds.findUParent(v)){
            // skip , forms cycles;
            continue;
        }

        ds.unionBySize(u,v);
        MST.push_back({wt,u,v});
        mstCost += wt;
    }


    // Display MST : 
    cout<<"W\tu\tv\n";
    for(auto e : MST){
        cout<<e[0]<<"\t"<<e[1]<<"\t"<<e[2]<<"\n";
    }

    cout<<"Cost of MST = "<<mstCost<<"\n";
}

vector<vector<int>> getGraph(int &n)
{
        cout<<"Enter the number of vertices : ";
        cin>>n;

        vector<vector<int>> G (n,vector<int> (n,0));

        cout<<"Enter the COST MATRIX of G (0 or 999 no edge): \n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>G[i][j];

                if(G[i][j] == 0 || i == j){
                    G[i][j] = 999;   
                }
            }
        }
        return G;
}
