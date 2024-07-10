#include<iostream>
#include<vector>

using namespace std;


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

int main()
{
	int noVertices;
	cout<<"Enter the number of Vertices : ";
	cin>>noVertices;

	vector<vector<int>> CostMat (noVertices, vector<int> (noVertices,999));

	cout<<"Enter the Cost Matrix (999 for self loop and no edge): \n";

	for(int i=0;i<noVertices;i++)
	{
		for(int j=0;j<noVertices;j++)
		{
			cin>>CostMat[i][j];
		}
	}


	vector<int> V (noVertices,0);
	for(int i=0;i<noVertices;i++)
	{
		V[i] = i;
	}

	vector<vector<int>> ans;
	rPermutation(V,0,noVertices-1,ans);
	
	
	int noOfPermutations = ans.size();
	vector<int> pathCost (noOfPermutations,-1);

	int minCost = 999;
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

		if(cost < minCost)
		{
			minPathIndex = i;
			minCost = cost;
		}
	}

	if( minPathIndex == -1 )
	{
		cout<<"No Solution exists\n";
		return -1;
	}

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
	cout<<" = "<<minCost<<"\n";
	cout<<"\n";
}
