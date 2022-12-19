#include <iostream>
using namespace std;
int arr[]={1,5,7,2,6,8,3,4,13,11};
int merge(int arr[],int s,int mid, int e)
{
	int left[10];
	int right[10];
	int counterl=0;
	int counterr=0;
	for(int i=s;i<=mid;i++)
	{
		left[counterl]=arr[i];
		counterl++;
	}
	left[counterl]=9999;
	for(int i=mid+1;i<=e;i++)
	{
		right[counterr]=arr[i];
		counterr++;
	}
	right[counterr]=9999;
	counterl=0;counterr=0;
	for(int i=s;i<=e;i++)
	{
		if (left[counterl] <right[counterr]	)
		{
			arr[i]=left[counterl];
			counterl++;
		}
		else
		{
			arr[i]=right[counterr];
			counterr++;
		}
	}
	return 0;
}
int mergesort(int arr[],int s,int e)
{
	if(s<e)
	{
		int mid=(s+e)/2;
		mergesort(arr,s,mid);
		mergesort(arr,mid+1,e);
		merge(arr,s,mid,e);
	}
	return 0;
}

int main()
{
mergesort(arr,0,9);
	for(int i=0;i<=9;i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<"\n";
return 0;
}
