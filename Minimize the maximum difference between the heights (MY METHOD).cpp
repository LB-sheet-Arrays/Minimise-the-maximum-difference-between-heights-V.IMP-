//MY METHOD (observation kiya maine)


#include<iostream>
#include<algorithm>  //to use sort()
   
using namespace std;

int Min_height(int arr[],int n,int k)
{
	int d=0;
	
	//sort the array first
	sort(arr,arr+n);
	
	//test sort()
		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<arr[i];
		}
	
	//corner case
	if(n==2)
	{
		d=min(((arr[1]-k)-(arr[0]+k)),(arr[1]-arr[0]));
	}
	else if(n>2)
	{
		//[0--mid) me k add karo and [mid---arr[n-1]] me k subtract karo to get min diff
		int mid=n/2;
		for(int i=0;i<n;)
		{
			if(i<mid)
			{
				arr[i]=arr[i]+k;
				i++;
			}
			else if(i>=mid)
			{
				arr[i]=arr[i]-k;
				i++;
			}
		}
		
		//sort the modified array again
		sort(arr,arr+n);
		
		//test sort()
		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<arr[i];
		}
		
		d=arr[n-1]-arr[0];
	}
	
	return d;
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
