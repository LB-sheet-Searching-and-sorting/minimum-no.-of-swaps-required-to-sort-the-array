/*
I have referred to this approach from youtube.

Approach: 

TC : O(nLog n) 

SC : O(n)

Sort the array and store it in a map (key as elements bcoz all input elements are distinct and value as index after sorting)

now iterate in our input array and 

*/

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int minSwaps(int a[],int b[],int n)
{
	int swaps=0,index;
	sort(b,b+n);
	
	//create a map
	unordered_map<int, int> map;
	
	//fill the map with key as elements bcoz all input elements are distinct and value as index after sorting
	for(int i=0;i<n;i++)
	{
		//                  key  value
		map.insert(make_pair(b[i],i));
	}
	
	//at() sidha key ki value return karta hai
	
	//now iterate on the original input array
	for(int i=0;i<n;)
	{
		//check if the current element is at its right place or not,if yes ,i++, if not swap it with element with 
		//its correct position
		if(i==map.at(a[i]))
		{
			i++;
		}
		else if(i!=map.at(a[i]))
		{
			swaps++;
			index=map.at(a[i]);
			swap(&a[i],&a[index]);
			i++;
		}
	}
	
	return swaps;
}

int main()
{
	int arr[] = {1,2,3,4};
	int arr_copy[] = {1,2,3,4};
	//copy karo isko in another array and then pass
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr,arr_copy,n);
	
	return 0;
}
