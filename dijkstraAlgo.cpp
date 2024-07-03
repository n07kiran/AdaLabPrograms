#include<iostream>
#include<vector>


using namespace std;

void dijkstra(int n,vector< vector <int> > COST,int source);

int main()
{
	int n;
	cout<<"Enter the no of Vertices of a graph : ";
	cin>>n;

	vector< vector <int> > COST (n , vector <int> (n,999) );

	cout<<"Enter the cost matrix ( 999 for self loop and No edge : \n";

	for(auto &v : COST)
	{
		for( auto &x : v)
		{
			cin>>x;
		}
	}

	int s;
	cout<<"Enter the start node : ";
	cin>>s;

	if(s>=n)
	{
		cout<<"INVALID Start Node\n";
	}
	else
	{
		dijkstra(n,COST,s);
	}
}

void dijkstra(int n,vector< vector <int> > COST,int source)
{
	vector<int> visited (n,0);
	visited[source] = 1;

	vector< vector <int> > dp (n,vector <int> (n,999) );
	
	int node = source;
	dp[0] = COST[source];
	dp[0][source] = 0;

	int prevDis = 0;
	int min, nextNode = node;
	for(int i=1;i<n;i++)
	{
		// find minimum COST edge of that node to an unvisited node
		min = 999;
		for(int j=0;j<n;j++)
		{
			if(visited[j] == 0 && dp[i-1][j] < min)
			{
				min = COST[node][j];
                                nextNode = j;
			}
		}
		
		prevDis = min;
		visited[nextNode] = 1;

		for(int j=0;j<n;j++)
		{
			if(visited[j] == 1)
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(COST[nextNode][j]+prevDis < dp[i-1][j])
			{
				dp[i][j] = COST[nextNode][j] + prevDis;	
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}

		node = nextNode;
	}

	cout<<"Distance Table:\n";
	for(auto &v : dp)
        {
                for( auto &x : v)
                {
                        cout<<x<<" ";
                }
                cout<<"\n";
        }
}
