// Preemptive SJF / SRTF
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,min,count=0,t;
	cout<<"Enter no of processes: ";
	cin>>n;
	int pn[n],at[n],bt[n],bt1[n+1],wt[n],ct[n],tat[n];
	double sum_wt=0,sum_tat=0,end;
	cout<<"Enter Arrival time/ Burst time: ";
	for(int i=0;i<n;i++){
		pn[i]=i;
		cin>>at[i];
		cin>>bt[i];
		bt1[i]=bt[i];
	}
	bt1[n]=INT_MAX;
    for(t=0; count!=n; t++){
        min=n;
        for(int i=0; i<n; i++){
            if(at[i]<=t && bt1[i]<bt1[min] && bt1[i]>0)
                min=i;
        }        bt1[min]--;
        if(bt1[min]==0){
            count++;
            end=t+1;
            ct[min] = end;
        }
    }
	cout<<"\nPN\tAT\tBT\tWT\tTAT\tCT\n";
	for(int i=0;i<n;i++){
		wt[i] = ct[i]-at[i]-bt[i];
		tat[i]=bt[i]+wt[i];
	    cout<<pn[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<"\n";
	    sum_wt = sum_wt + wt[i];
        sum_tat = sum_tat + tat[i];
	}
	cout<<"\nAvg WT = "<<sum_wt/n<<", Avg TAT = "<<sum_tat/n;
	return 0;
}
