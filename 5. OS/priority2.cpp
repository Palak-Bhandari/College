// Priority preemptive 
#include<iostream>
using namespace std;
int main(){
	int n,smallest,count=0,time;
	cout<<"Enter the number of Processes: ";
    cin>>n;
    int at[n+1],bt[n+1],bt1[n+1],wt[n+1],tat[n+1],ct[n+1],p[n+1];
    double sum_wt=0,sum_tat=0,end;
    cout<<"Enter Arrival time/ Burst time /Priority: ";
  	for(int i=0;i<n;i++){
		cin>>at[i];
		cin>>bt[i];
		cin>>p[i];
		bt1[i]=bt[i];
	}   
    p[n]=-1;
    for(time=0; count!=n; time++){
        smallest=n;
        for(int i=0; i<n; i++){
            if(at[i]<=time && p[i]>p[smallest] && bt1[i]>0)
                smallest=i;
        }
        bt1[smallest]--;
        if(bt1[smallest]==0){
            count++;
            end=time+1;
            ct[smallest] = end;
            wt[smallest] = end - at[smallest] - bt[smallest];
            tat[smallest] = end - at[smallest];
        }
    }
    cout<<"\nPN\tBT\tAT\tWT\tTAT\tCT\tPriority"<<endl;
    for(int i=0; i<n; i++){
        cout<<i+1<<"\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<ct[i]<<"\t"<<p[i]<<endl;
        sum_wt = sum_wt + wt[i];
        sum_tat = sum_tat + tat[i];
    }
   	cout<<"\nAvg WT = "<<sum_wt/n<<", Avg TAT = "<<sum_tat/n;
}
