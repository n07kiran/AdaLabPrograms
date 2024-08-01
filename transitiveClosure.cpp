#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

vector<vector<int>> getGraph(int &n);
void displayGraph(const int &n, const vector<vector<int>> &G);
void TransitiveClousre(vector<vector<int>> D,int n);

int main()
{
        int n;
        vector<vector<int>> G = getGraph(n);
        TransitiveClousre(G,n);
}

void TransitiveClousre(vector<vector<int>> D,int n){

    for(int k=0;k<n;k++){

        cout<<"\nD "<<k<<" : \n";
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                if( D[i][j] || ( D[i][k] && D[k][j] ) ){
                    D[i][j] = 1;
                }
            }
        }
        displayGraph(n,D);
    }

    cout<<"After Applying Warshall's Algorithm : \n";
    cout<<"ReachAbility Matrix is  : \n";

    displayGraph(n,D);
}

vector<vector<int>> getGraph(int &n)
{
        cout<<"Enter the number of vertices : ";
        cin>>n;

        vector<vector<int>> G (n,vector<int> (n,0));

        cout<<"Enter the Adjacency Matrix of G (0 or 1): \n";
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
                        cout<<setw(3)<<G[i][j]<<" ";
                }
                cout<<"\n";
        }
}