#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> getGraph(int &n);
void displayGraph(const int &n, const vector<vector<int>> &G);

void bfs(int n,vector<vector<int>> G,int source)
{
	vector<int> visited (n,0);

	queue<int> q;

	q.push(source);
	visited[source] = 1;

	cout<<"From starting Node = "<<source<<"\n";
	cout<<"Nodes that are reachable using BFS are :\n";

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		cout<<u<<" ";

		for(int i=0;i<n;i++)
		{
			if(visited[i] == 0 && G[u][i] != 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	cout<<"\n";
}

int main()
{
	int n;
	vector<vector<int>> G = getGraph(n);
	int source;
	cout<<"Enter the source vertex : ";
	cin>>source;
	bfs(n,G,source);
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
