#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> getGraph(int &n);
void displayGraph(const int &n, const vector<vector<int>> &G);
vector<vector<int>> tranposeGraph(vector<vector<int>> G);
void dfs(vector<vector<int>> &G,int &n,int source,vector<int> &visited);

int main()
{
	int n;
	vector<vector<int>> G = getGraph(n);
    vector<int> vis1 (n,0); 
    vector<int> vis2 (n,0);

    dfs(G,n,0,vis1);

    vector<vector<int>> G_t =  tranposeGraph(G);
    dfs(G_t,n,0,vis2);

    bool connected = true;
    for(int i=0;i<n;i++){
        if(!vis1[i] && !vis2[i]){
            connected = false;
            cout<<"The Graph is not connected \n";
            cout<<"At vertex : "<<i<<"\n";
            break;
        }
    }

    if(connected){
        cout<<"The Graph is Connected!\n";
    }

}

void dfs(vector<vector<int>> &G,int &n,int source,vector<int> &visited){
    visited[source] = 1;
    for(int v=0;v<n;v++){
        if(!visited[v] && G[source][v]){
            dfs(G,n,v,visited);
        }
    }    
}

vector<vector<int>> getGraph(int &n)
{
        cout<<"Enter the number of vertices : ";
        cin>>n;

        vector<vector<int>> G (n,vector<int> (n,0));

        cout<<"Enter the Adjacency Matrix of G : \n";
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cin>>G[i][j];
                }
        }

        return G;
}

void displayGraph(const int &n, const vector<vector<int>> &G)
{
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<G[i][j]<<" ";
                }
                cout<<"\n";
        }
}


vector<vector<int>> tranposeGraph(vector<vector<int>> G){
    int n = G.size();
    vector<vector<int>> G_t (n,vector<int> (n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G_t[i][j] = G[j][i];
        }
    }

    return G_t;
}