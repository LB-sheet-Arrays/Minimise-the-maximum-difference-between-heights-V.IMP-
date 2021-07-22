//MY METHOD (observation kiya maine)


#include<iostream>
#include<algorithm>  //to use sort()
   
using namespace std;

int Min_height(int arr[],int n,int k)
{
	int d=0;
	
	//sort the array first
	sort(arr,arr+n);
	
	int ans=arr[n-1]-arr[0];
	int smallest=arr[0]+k;
	int largest=arr[n-1]-k;
	int Min,Max;
	
	for(int i=0;i<n-1;i++)
	{
		Min=min(smallest,arr[i+1]-k);
		Max=max(largest,arr[i]+k);
		if(Min<0)
		{
			continue;
		}
		ans=min(ans,Max-Min);
	}
	return ans;

}

int main()
{
	//Static inputs
	int n=6;
	int k=6;
	int arr[n]={1,14,14,10,14,15};
	
	cout<<"\nMinimum difference => "<<Min_height(arr,n,k);
	
	return 0;
}
