// FCFS - with/without AT
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter number of process: ";
	int a;
	cin>>a;
	int pn[a],at[a],bt[a],wt[a],ct[a],tat[a];
	cout<<"Enter Arrival time/ Burst time: ";
	for(int i=0;i<a;i++){
		pn[i]=i;
		cin>>at[i];
		cin>>bt[i];
	}
	for (int i = 0; i < a; i++){
		for (int j = 0; j < a - i; j++){
			if (at[j] > at[j + 1]){
                swap(at[j], at[j + 1]);
				swap(pn[j], pn[j + 1]);
				swap(bt[j], bt[j + 1]);				
			}
		}      
	}   
	wt[0]=0;
	ct[0]=at[0]+bt[0];
	for(int i=1;i<=a;i++){
		int temp;
		if(ct[i-1]<at[i]){
			temp = at[i] - ct[i-1];
		}else{
			temp = 0;
		}
		ct[i] = ct[i-1]+bt[i]+temp;
		wt[i] = ct[i]-at[i]-bt[i];
	}
	cout<<"\nPN\tAT\tBT\tWT\tTAT\tCT\n";
	for(int i=0;i<a;i++){
		tat[i]=bt[i]+wt[i];
	    cout<<pn[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<"\n";
	}
	return 0;
}
