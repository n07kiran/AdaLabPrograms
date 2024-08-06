#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> getGraph(int &n);
void rPermutation(vector<int> &nums,int start,int end,vector<vector<int>> &ans);
int nearestNeighbourApprox(vector<vector<int>> G,int n,int source=0);

int main()
{
	int noVertices;
	vector<vector<int>> CostMat = getGraph(noVertices);

	vector<int> V (noVertices,0);
	for(int i=0;i<noVertices;i++)
	{
		V[i] = i;
	}

	// Storing all possible Permutatoins
	vector<vector<int>> ans;
	rPermutation(V,0,noVertices-1,ans);
	
	
	int noOfPermutations = ans.size();
	vector<int> pathCost (noOfPermutations,-1);

	int optimalCost = 999;
	int minPathIndex = -1;
	for(int i=0;i<ans.size();i++)
	{
		//cout<<"i = "<<i<<"\n";
		int cost = 0;
		bool validPath = true;
		for(int j=0;j<ans[i].size()-1;j++)
		{
			int u = ans[i][j];
			int v = ans[i][j+1];
			cost += CostMat[u][v];
			//cout<<"("<<u<<","<<v<<") = "<<cost<<"\n";
			if(cost >= 999)
			{
				//minPathIndex[i] = -1;
				validPath = false;
				break;
			}
		}
		//cout<<"i = "<<i<<"\n";
		//cout<<"Cost = "<<cost<<"\n";

		if(validPath)
		{
			pathCost[i] = cost;
		}
		else
		{
			pathCost[i] = -1;
		}

		if(cost < optimalCost)
		{
			minPathIndex = i;
			optimalCost = cost;
		}
	}

	if( minPathIndex == -1 )
	{
		cout<<"No Solution exists\n";
		return -1;
	}

	cout<<"All Possible Paths : \n";
	for(int i=0;i<noOfPermutations;i++)
	{
		if(pathCost[i] != -1)
		{
			for(auto &x : ans[i])
			{
				cout<<x<<" --> ";
			}
			cout<<" = "<<pathCost[i]<<"\n";
		}
	}

	cout<<"Optimal Path : \n";
	for(auto &x : ans[minPathIndex])
	{
		cout<<x<<" --> ";
	}
	cout<<" = "<<optimalCost<<"\n";
	cout<<"\n";

	int approxCost = nearestNeighbourApprox(CostMat,noVertices);

	if(approxCost == -1){
		cout<<"Can not calculate approximation with nearestNeighbour approach from this source \n";
		return -1;
	}

	float err =  ( (float) (approxCost - optimalCost) / optimalCost ) * 100;

	cout<<"Aprroximation Cost using nearest NeighBour = "<<approxCost<<"\n";
	cout<<"Error in approximation = "<<err<<" % \n";
}

void rPermutation(vector<int> &nums,int start,int end,vector<vector<int>> &ans)
{
	if(start > end)
	{
		if(nums[0] == 0)
		{
			nums.push_back(0);
			ans.push_back(nums);
			//for(auto &x : nums)
                        //{
                                //cout<<x<<" ";
                        //}
                        //cout<<"\n";
			nums.pop_back();
		}
	}
	else
	{
		for(int i=start;i<=end;i++)
        	{
                	swap(nums[start],nums[i]);
                	rPermutation(nums,start+1,end,ans);
			swap(nums[start],nums[i]);
        	}
	}
}

vector<vector<int>> getGraph(int &n)
{
        cout<<"Enter the number of vertices : ";
        cin>>n;

        vector<vector<int>> G (n,vector<int> (n,0));

        cout<<"Enter the Adjacency COST Matrix of G ( 0 or no edge and self loop ): \n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>G[i][j];
				if(i==j || G[i][j] == 0){
					G[i][j] = 999;
				}
            }
        }
        return G;
}

// Nearest Neighbour Approximation;
int nearestNeighbourApprox(vector<vector<int>> G,int n,int source){

	vector<int> visited (n,0);

	bool pathExist = true;
	int pathCost = 0;
	visited[source] = 1;

	int u = source , v;
	for(int noEdge=1;noEdge<=n-1;noEdge++){
		v = -1;
		int minEdge = 999;

		//Find the minimum of unVisited edges:
		for(int i=0;i<n;i++){
			if(!visited[i] && G[u][i] < minEdge ){
				// cout<<u<<","<<i<<" = "<<G[u][i]<<"\n";
				v = i;
				minEdge = G[u][i];
			}
		}

		if(v == -1){
			bool pathExist = false;
			break;
		}

		pathCost += G[u][v];
		visited[v] = 1;
		// cout<<u<<","<<v<<" = "<<pathCost<<"\n";
		u = v;
	}

	// CHecking if the last vertex has edge back to source vertex;
	if(G[u][source] != 999){
		pathCost += G[u][source];
	}else{
		pathExist = false;
	}

	if(pathExist) return pathCost;
	return -1;
}
