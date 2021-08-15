/*
First we try to sort the array and make each height of the tower maximum . 
We do this by decreasing the height of all the towers towards right by k and increasing all the height of the 
towers towards left (by k). It is also possible that the tower you are trying to increase the height doesn’t have 
the maximum height . Therefore we only need to check whether it has the maximum height or not by comparing it with 
the last element towards the right side which is an-k. Since the array is sorted if the tower’s height is greater than 
the an-k then it’s the tallest tower available. Similar reasoning can also be applied for finding the shortest tower .  

Note:- We need not consider where a[i]<k because the height of the tower can’t be negative so we have to neglect that case.
*/

#include<bits/stdc++.h>
   
using namespace std;

int Min_height(int arr[],int n,int k)
{
	sort(arr,arr+n);
	
	//test sort()
		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
	
	int result = arr[n - 1]- arr[0]; // current result when arr[0] is min and arr[n-1] is max
	
	int minEle,maxEle; // these 2 variables will hold the between elements max and min value
	
	for (int i = 1; i <= n - 1; i++) 
	{
		cout<<"\n\nCurrent element => "<<arr[i];
        if (arr[i] >= k && arr[n - 1] >= k)  //arr[i]<3 not included
		{
			cout<<"\n"<<arr[i - 1]<<" + "<<k<<" = "<<arr[i - 1] + k;
			cout<<"\n"<<arr[n - 1]<<" - "<<k<<" = "<<arr[n - 1] - k;
			cout<<"\n"<<arr[0]<<" + "<<k<<" = "<<arr[0] + k;
			cout<<"\n"<<arr[i]<<" - "<<k<<" = "<<arr[i] - k;
            maxEle = max(arr[i - 1] + k,arr[n - 1] - k); 
            minEle = min(arr[0] + k, arr[i] - k);
 			cout<<"\nmaxEle => "<<maxEle;
 			cout<<"\nminEle => "<<minEle;
            result = min(result, maxEle - minEle);
            cout<<"\nresult => "<<result;
        }
	}
	
	return result;
}

int main()
{
	//Static inputs
	int k=3;
	int arr[]={1, 5, 15, 10};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"\nMinimum difference => "<<Min_height(arr,n,k);
	
	return 0;
}
