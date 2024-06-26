#include<iostream>
#include<vector>


using namespace std;


int subSequenceSum(int i,int rSum,int &noOfSolutions,vector<int> res,vector<int> &S,int n);
int main(){

	int n;
	cout<<"Enter the number of elements in Set : \n";
	cin>>n;

	vector<int> S (n,0);

	cout<<"Enter the elements : \n";
	for(int &x : S)
	{
		cin>>x;
	}
	
	int sum = 0;
	cout<<"Enter the subsequence Sum : \n";
	cin>>sum;
	
	int noOfSolutions = 0;
	noOfSolutions = subSequenceSum(0,sum,noOfSolutions,{},S,n);

	if(!noOfSolutions){
		cout<<"There does not exist any subset with sum "<<sum<<"\n";
	}
	else{
		cout<<"Total No of subsets with sum "<<sum<<" = "<<noOfSolutions<<"\n";
	}
}

int subSequenceSum(int i,int rSum,int &noOfSolutions,vector<int> res,vector<int> &S,int n)
{
	if(i>=n)
	{
		if(rSum == 0)
		{
			cout<<"Subset with sum : \n";
			
			for(int &x: res)
			{
				cout<<x<<" ";
			}
			cout<<"\n";
			noOfSolutions++;
		}
		return noOfSolutions;
	}

	subSequenceSum(i+1,rSum,noOfSolutions,res,S,n);

	res.push_back(S[i]);
	subSequenceSum(i+1,rSum-S[i],noOfSolutions,res,S,n);
	return noOfSolutions;
}


