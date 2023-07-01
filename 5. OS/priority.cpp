// Priority Non Preemptive
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,hp=1,count=0;
	cout<<"Enter no of processes: ";
	cin>>n;
	int pn[n],at[n],bt[n],bt1[n],wt[n],ct[n],tat[n],pr[n];
	cout<<"Enter Arrival time/ Burst time /Priority(1 highest): ";
	for(int i=0;i<n;i++){
		pn[i]=i;
		cin>>at[i];
		cin>>bt[i];
		cin>>pr[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i; j++){
			if (pr[j] > pr[j + 1]){
                swap(at[j], at[j + 1]);
				swap(pn[j], pn[j + 1]);
				swap(bt[j], bt[j + 1]);	
				swap(pr[j], pr[j + 1]);				
			}
		}      
	}
	cout<<"\nPN\tAT\tBT\tPR\n";
    for(int i=0;i<n;i++){
    	cout<<pn[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<pr[i]<<endl;
    }
	return 0;
}
