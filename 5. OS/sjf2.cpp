// Non-Preemptive SJF
#include<iostream>
using namespace std;
int main(){
    int n,temp,tt=0,min,d;
    float avg_tat=0,avg_wt=0,sum_of_tat=0,sum_of_wt=0;
  	cout<<"Enter no of processes: ";
  	cin>>n;
  	int at[n],bt[n],bt1[n],tat[n],wt[n],ct[n],pn[n];
  	cout<<"Enter Arival time/Burst time: ";
  	for(int i=0;i<n;i++){
        cin>>at[i]; 
        cin>>bt[i];
        pn[i]=i;
  	}	
  	for(int i=0;i<n;i++){
     	for(int j=i+1;j<n;j++){
	        if(bt[i]>bt[j]){
	         	swap(at[j], at[j + 1]);
				swap(pn[j], pn[j + 1]);
				swap(bt[j], bt[j + 1]);	
	        }
      	}
  	}
  	min=at[0];
  	for(int i=0;i<n;i++){
        if(min>at[i]){
              min=at[i];
              d=i;
        }
  	}
  	tt=min;
  	bt1[d]=tt+bt[d];
  	tt=bt1[d];
    for(int i=0;i<n;i++){
        if(at[i]!=min){
            bt1[i]=bt[i]+tt;
            tt=bt1[i];
        }
    }
  	for(int i=0;i<n;i++){
        tat[i]=bt1[i]-at[i];
        sum_of_tat+=tat[i];
        wt[i]=tat[i]-bt[i];
        sum_of_wt+=wt[i];
        ct[i]=at[i]+bt[i]+wt[i];
  	}
  	cout<<"\nPN\tAT\tBT\tWT\tTAT\nCT";
    for(int i=0;i<n;i++){
    	cout<<pn[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<endl;
    }
    avg_tat = sum_of_tat/n;
  	avg_wt = sum_of_wt/n;
    cout<<"\nAvg WT = "<<avg_wt<<", Avg TAT = "<<avg_tat;
}
