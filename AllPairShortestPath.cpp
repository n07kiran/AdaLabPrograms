//AllPairShortestPath -> Floyd's algorithm.

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

vector<vector<int>> getGraph(int &n);
void displayGraph(const int &n, const vector<vector<int>> &G);
void Floyds(vector<vector<int>> D,int n);

int main()
{
	int n;
	vector<vector<int>> G = getGraph(n);
    Floyds(G,n);
}

void Floyds(vector<vector<int>> D,int n){

    for(int k=0;k<n;k++){
        cout<<"\nD "<<k<<" : \n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j] );
            }
        }
        displayGraph(n,D);
    }

    cout<<"\nAfter Applying Floyds Algorithm : \n";
    cout<<"\nALL Pair SHORTEST PATH : \n";

    displayGraph(n,D);
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

                if(i==j){
                    G[i][j] = 0;
                }else if(G[i][j] == 0){
                    G[i][j] = 999;
                }
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
