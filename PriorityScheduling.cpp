#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int left[],int leftcount,int right[],int rightcount){
	int i=0,j=0,k=0;
	// i points to left subarray
	// j points to right subarray
    // k points to merged subarray
	while( i<leftcount && j<rightcount ){
		if( left[i] < right[j] ) a[k++]=left[i++];
		else a[k++]=right[j++];
    }
    while(i < leftcount)  a[k++] = left[i++];
    while(j < rightcount)  a[k++] = right[j++];
}
void mergesort(int a[],int n){
	if(n<2) return;   //base condition:if array has only one element then it is already sorted 
	int middle;   // middle index of array
	int *left=NULL;
	int *right=NULL;
	middle=n/2;
	left = new int[middle];
	right = new int[n-middle];
	for(int i=0;i<middle;i++) 
		left[i]=a[i];
	for(int i=middle;i<n;i++)
		right[i-middle]=a[i];
	mergesort(left,middle);
	mergesort(right,n-middle);
	merge(a,left,middle,right,n-middle);
	delete left;
	delete right;
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the number of processes ";
	cin>>n;
	int burstTime[n],wt[n]={0},tat[n],priority[n],total=0;
	float avg_wt,avg_tat;
	for(int i=0;i<n;i++) {
      cout<<"Enter the burst time and priority for process "<<i+1<<" :";
      cin>>burstTime[i]>>priority[i];
 	}
    mergesort(burstTime,n);
    mergesort(priority,n);
    for(int i=1;i<n;i++){
    	for(int j=0;j<n;j++)
    		wt[i]+=burstTime[j];
    	total+=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;
    for(int i=0;i<n;i++){
    	tat[i]=burstTime[i]+wt[i];
    	total+=tat[i];
    	cout<<"P["<<i+1<<"]\t\t"<<burstTime[i]<<"\t"<<tat[i]<<"\t"<<wt[i];
    }
    avg_tat=(float)total/n;
    cout<<"Average waiting time is "<<avg_wt;
    cout<<"Average turnaround time is "<<avg_tat;
   	return 0;
}