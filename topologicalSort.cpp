#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> getGraph(int &n);
void displayGraph(const int &n, const vector<vector<int>> &G);

vector<int> topoLogicalSorting(const int &n,const vector<vector<int>> &G);
void dfs(int n,const vector<vector<int>> &G,int source,vector<int> &visited,stack<int> &st);


int main()
{
	int n;
	vector<vector<int>> G = getGraph(n);
	//displayGraph(n,G);
	vector<int> topologicalOrder = topoLogicalSorting(n,G);
	
	for(int i=0;i<n;i++)
	{
		cout<<topologicalOrder[i]<<" -> ";
	}

	cout<<"\n";
}

vector<int> topoLogicalSorting(const int &n,const vector<vector<int>> &G)
{
        vector<int> visited (n,0);
        stack<int> st;
	
	vector<int> ans;

	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
                        dfs(n,G,i,visited,st);
		}
	}

        while(!st.empty())
        {
                ans.push_back(st.top());
                st.pop();
        }

        return ans;
}

void dfs(int n,const vector<vector<int>> &G,int source,vector<int> &visited,stack<int> &st)
{
	visited[source] = 1;
        for(int i=0;i<n;i++)
        {
                if(visited[i] == 0 && G[source][i] != 0 )
                {
                        dfs(n,G,i,visited,st);
                }
        }
	st.push(source);
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
