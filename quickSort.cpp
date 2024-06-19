// Sorting 
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

void randArr(int arr[],int n);
void input_arr(int arr[],int n);
void display_arr(int arr[],int n);
void quick_sort(int arr[],int s,int e);


int main()
{
	cout<<"QuickSort\n";
	int n;
	cout<<"Enter the size of the array : ";
	cin>>n;

	int* arr = new int[n];
	input_arr(arr,n);

	cout<<"After sortin:\n";
	quick_sort(arr,0,n-1);
	display_arr(arr,n);

	delete[] arr;
	arr = NULL;

	clock_t start , end;
	cout<<"Quick SORT TIME COMPLEXITY\n";
        cout<<"A_Size\tTime(ms)\n";
	int size;
	for(int i=1;i<=pow(10,5);)
	{
		size = i;
                arr = new int[size];
                randArr(arr,size);
                start = clock();
                quick_sort(arr,0,size-1);
                end = clock();
                cout<<size<<"\t"<<((double) (end-start)/CLOCKS_PER_SEC)*1000 <<"\n";
                delete[] arr;
                arr = NULL;
                i = i*10;
	}
}

void quick_sort(int arr[],int s,int e)
{
	if(s<e)
	{
		//display_arr(arr,e-s+1);
		int m = (s+e)/2;
		int pivot = arr[m];

		int i=s, j=e;

		while(i<=j)
		{
			while(arr[i]<pivot)
			{
				i++;
			}	

			while(arr[j]>pivot)
			{
				j--;
			}

			if(i<=j)
			{
				swap(arr[i],arr[j]);
				i++;j--;
				//display_arr(arr,e-s+1);
			}
		}

		quick_sort(arr,s,j);
		quick_sort(arr,i,e);
		
				
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

void input_arr(int arr[],int n)
{
        cout<<"Enter the array elements:  ";
        for(int i=0;i<n;i++)
        {
                cin>>arr[i];
        }
}

void randArr(int arr[],int n)
{
	int upper = 100;

	for(int i=0;i<n;i++)
	{
		arr[i] = rand()%upper;
	}
}


