// Sorting 
#include<iostream>
#include<ctime>
//#include<cstdlib>
#include<cmath>
using namespace std;

void RandArr(int arr[],int n);
void display_arr(int arr[],int n);
void merge(int arr[],int s,int m,int e);
void mergeSort(int arr[],int s,int e);
void inputArray(int arr[],int n);

int main()
{
	clock_t start,end;

	int size = 0;
	cout<<"Enter the size of array : ";
	cin>>size;
	int *arr = new int[size];

	inputArray(arr,size);

	start = clock();
	mergeSort(arr,0,size-1);
	end = clock();
	
	display_arr(arr,size);

	cout<<"Time Taken by Merge Sort = "<<((double) (end-start)/CLOCKS_PER_SEC)*1000 <<" ms\n";

	delete[] arr;
	arr = NULL;

	cout<<"MERGE SORT TIME COMPLEXITY\n";
	cout<<"A_Size\tTime(ms)\n";
	for(int i=1;i<=pow(10,6);)
	{
		size = i;
		arr = new int[size];
		RandArr(arr,size);
		start = clock();
		mergeSort(arr,0,size-1);
		end = clock();
		cout<<size<<"\t"<<((double) (end-start)/CLOCKS_PER_SEC)*1000 <<"\n";
		delete[] arr;
		arr = NULL;
		i = i*10;

	}
}

void mergeSort(int arr[],int s,int e)
{
	if(s>=e)
	{
		return;
	}
	int m = (s+e)/2;
	mergeSort(arr,s,m);
	mergeSort(arr,m+1,e);
	merge(arr,s,m,e);
	//display_arr(arr,6);
}
void merge(int arr[],int s,int m,int e)
{
	int new_arr[e-s+1];

	int i=s,j=m+1,k=0;

	while(i<=m && j<=e)
	{
		if(arr[i]<=arr[j])
		{
			new_arr[k++] = arr[i++];
		}

		if(arr[j]<arr[i])
		{
			new_arr[k++] = arr[j++];
		}

	}

	while(i<=m)
	{
		new_arr[k++] = arr[i++];
	}

	while(j<=e)
	{
		new_arr[k++] = arr[j++];
	}

	for(int i=s,k=0;i<=e;)
	{
		arr[i++] = new_arr[k++];
	}

}




void display_arr(int arr[],int n)
{
        for(int i=0;i<n;i++)
        {
                cout<<arr[i]<<" ";
        }
        cout<<"\n";
}

void RandArr(int arr[],int n)
{	
	int upper = 100;

	for(int i=0;i<n;i++)
	{
		arr[i] = rand()%upper;
	}
}

void inputArray(int arr[],int n)
{
	cout<<"Enter the elements of the Array : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
