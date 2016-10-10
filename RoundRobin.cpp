#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cout<<"Enter the number of processes ";
	cin>>n;
	int flag,count,time,arrivalTime[n],burstTime[n],remainingTime[n],wait_time=0,turn_around_time=0,time_quantum;
	int remain=n;
	for(int i=0;i<n;i++){
		cout<<"Enter the arrival and burst time for process "<<i+1<<":";
		cin>>arrivalTime[i]>>burstTime[i];
        remainingTime[i]=burstTime[i];
	}
	cout<<"Enter time quantum ";
	cin>>time_quantum;
    cout<<"\nProcess\t"<<"|TAT\t"<<"|Waitng Time\n";
    for(time=0,count=0;remain!=0;){
    	if(remainingTime[count]<=time_quantum && remainingTime[count]>0){
    		time+=remainingTime[count];
    		remainingTime[count]=0;
    		flag=1;
    	}
    	else if(remainingTime[count]>time_quantum && remainingTime[count]>0){
    		remainingTime[count]-=time_quantum;
    		time+=time_quantum;
    	}
    	if(flag==1){
    		remain--;
    		cout<<"P["<<count+1<<"]\t"<<"|"<<time-arrivalTime[count]<<"\t|"<<time-arrivalTime[count]-burstTime[count]<<"\n";
    		wait_time+=time-arrivalTime[count];
    		turn_around_time+=time-arrivalTime[count]-burstTime[count];
    		flag=0;
    	}
    	if(count==n-1)
    		count=0;
    	else if(arrivalTime[count+1]<=time)
    		count++;
    	else count=0;
    }
    cout<<"Average waitng time is :"<<wait_time*1.0/n<<"\n";
    cout<<"Average turnaround time :"<<turn_around_time*1.0/n;
	return 0;
}
