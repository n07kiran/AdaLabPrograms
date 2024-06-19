//19th July 2024

//0-1 Knapsack using dp

#include<iostream>

using namespace std;


void knapsack(int P[],int V[],int n,int W){
	
	cout<<"KnapSack\n";

	int k[n+1][W+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(i==0 || j==0){
				k[i][j] = 0;
			}

			else if(j >= V[i-1]){
			k[i][j] = max(k[i-1][j],P[i-1]+k[i-1][j-V[i-1]]);
			}
			else{
				k[i][j] = k[i-1][j];
			}
		} 
	}

	//cout<<"Max Profit = "<<k[n][W]<<"\n";

	cout<<"\nDP Table\n";
	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			cout<<k[i][j]<<" ";
		}
		cout<<"\n";
	}

	//cout<<"\nMax Profit = "<<k[n][W]<<"\n";

	//Included Elements:
	

	int x[n];
	int i=n , j=W;

	while(i>0 && j>=0){

		if(k[i][j] == k[i-1][j]){
			x[i-1] = 0;
			i--;
		}else{
			x[i-1] = 1;
			j = j - V[i-1];
			i--;
		}
	}

	cout<<"\n0/1 Knapsack : \n";

	cout<<"P\t:\t";
	for(int i=0;i<n;i++){
		cout<<P[i]<<"\t";
	}
	cout<<"\n";

	cout<<"V\t:\t";
        for(int i=0;i<n;i++){
                cout<<V[i]<<"\t";
        }
	cout<<"\n";
	
	cout<<"0/1\t:\t";
	for(int i=0;i<n;i++){
		cout<<x[i]<<"\t";
	}
	cout<<"\n";

	cout<<"Max Profit = "<<k[n][W]<<"\n";
	cout<<"Capacity = "<<W<<"\n";
	
}

int main(){
	int n=4;
	int P[]={2,5,1,9};
	int V[]={1,2,3,4};
	int W = 5;
	knapsack(P,V,n,W);
}
