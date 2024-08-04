#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> getGraph(int &n);

void Prims(vector<vector<int>> D,int n,int source);

int main(){

    int n;
    vector<vector<int>> G = getGraph(n);

    int s;
    cout<<"Enter the source Vertex to start with : ";
    cin>>s;
    Prims(G,n,s);
}

// Gives next minimum edge among the visited vertices having No cycles;
vector<int> getNextMinimumEdge(vector<vector<int>> &D,int n, vector<int> &visited){
    int u=-1,v=-1;
    int wt = 999;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // Edges that form no Cycles!

            //Outing Edges && Incoming Edges
            if( (visited[i] && !visited[j] ) || (!visited[i] && visited[j] ) ){
                if(D[i][j] < wt){
                    u = i;
                    v = j;
                    wt = D[i][j];
                }
            }
        }
    }

    // No minimum edge found
    if(u == -1 || v == -1 || wt == 999){
        return {};
    }

    D[u][v] = 999;
    visited[u] = 1;
    visited[v] = 1;
    return {u,v,wt};
}

void Prims(vector<vector<int>> D,int n,int source=0){

    cout<<"Prims Algorithm ! \n";

    vector<vector<int>> MST;
    vector<int> visited (n,0);
    visited[source] = 1;

    int sum = 0;

    while(1){
        vector<int> nextNode = getNextMinimumEdge(D,n,visited);
        if(nextNode.size() == 0){
            break;
        }
        sum += nextNode[2];
        MST.push_back(nextNode);
    }

    int countVertices = 0;
    int countEdges = MST.size();

    for(int i=0;i<n;i++){
        if(visited[i]) countVertices++;
    }

    if(countVertices == countEdges + 1){
        cout<<"MST is Formed !! :  \n";
    }
    cout<<"MST Edges : \n";
    cout<<"u\tv\tWeight\n";
    for(auto &edge : MST){
        cout<<edge[0]<<"\t"<<edge[1]<<"\t"<<edge[2]<<"\n";
    }

    cout<<"Cost of Minimum Spanning Tree  = "<<sum<<"\n";
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
