// Round Robin
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t=0;
	int tq;
	cout<<"Enter no of processes: ";
	cin>>n;
	cout<<"Enter time quantum: ";
	cin>>tq;
	int pn[n],at[n],at1[n],bt[n],bt1[n],wt[n],ct[n],tat[n];
	cout<<"Enter Arrival time/ Burst time: ";
	for(int i=0;i<n;i++){
		pn[i]=i;
		cin>>at[i];
		cin>>bt[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i; j++){
			if (at[j] > at[j + 1]){
                swap(at[j], at[j + 1]);
				swap(pn[j], pn[j + 1]);
				swap(bt[j], bt[j + 1]);				
			}
		}      
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		bt1[i]=bt[i];
		ct[i]=0;
		if(at[i]==0){
			q.push(pn[i]);
			at1[i]=-1;
		}
		else at1[i]=at[i];
	}
	int flag=0,j;
	do{
		while(q.empty()==false){
			int sz=q.size();
			for(int i=0;i<sz;i++){
				j=q.front(); 
				q.pop();
				if(bt1[j]>tq){
					t=t+tq;
					bt1[j]=bt1[j]-tq;
					ct[j]=t;
					for(int k=j;k<n;k++){
						if(at[k+1]<=t && at1[k+1]!=-1){
							q.push(pn[k+1]);
							at1[k+1]=-1;
						}
					}
					q.push(j);
				}
				else{
					t=t+bt1[j];
					ct[j]=t;
					bt1[j]=0;
					for(int k=j;k<n;k++){
						if(at[k+1]<=t && at1[k+1]!=-1){
							q.push(pn[k+1]);
							at1[k+1]=-1;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(bt1[i]!=0){
				flag=1;
				break;
			}
		}
	}while(flag==1);
	for(int i=0;i<n;i++){
		wt[i] = ct[i]-at[i]-bt[i];
	}
	cout<<"\nPN\tAT\tBT\tWT\tTAT\tCT\n";
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	    cout<<pn[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<"\n";
	}	
	return 0;
}
