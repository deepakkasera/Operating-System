#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,bt[20],wt[20],tat[20],avgwt=0,avgtat=0;
	cout<<"Enter the number of processes ";
	cin>>n;
	cout<<"\nEnter burst time for processes\n";
	for(int i=0;i<n;i++){
		cout<<"P["<<i+1<<"]";
		cin>>bt[i];
	}
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=0;
		for(int j=0;j<i;j++)   wt[i]+=bt[j];
	}
	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
		avgwt+=wt[i];
		avgtat+=tat[i];
	}
	avgwt/=n;
	avgtat/=n;
	cout<<"\nProcesses\t\tBurst time\tWaiting time\tTurnAround time\n";
	for(int i=0;i<n;i++){
		cout<<"P["<<i+1<<"]"<<"\t\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
	}
	cout<<"\nAverage waiting time is"<<avgwt;
	cout<<"\nAverage Turn around time is "<<avgtat;
	return 0;
}

