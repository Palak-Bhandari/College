#include<bits/stdc++.h>
using namespace std;
int main(){
	int p, r, f=0;
	cout<<"Enter number of process: ";
	cin>>p;
	cout<<"Enter number of resources: ";
	cin>>r;
	int allocation[p][r], maxr[p][r], avl[r], need[p][r]; 
	bool flag[p];
	queue<int> q;
	cout<<"Enter the Allocation/Max Matrix \n";
	for(int i=0;i<p;i++){
		cout<<"Enter p"<<i<<" allocation: ";
		for(int j=0;j<r;j++){
			cin>>allocation[i][j];
		}
		cout<<"Enter p"<<i<<" max: ";
		for(int j=0;j<r;j++){
			cin>>maxr[i][j];
			need[i][j] = maxr[i][j] - allocation[i][j];
		}
	}
	cout<<"\nEnter available: ";
	int available[r];
	for(int i=0;i<r;i++){
		cin>>avl[i];
		available[i] = avl[i];
	}
	int count=0;
	while(count<p){			
		for(int i=0;i<p;i++){
			if (flag[i] == 0) {
                int flag1 = 0;
                for (int j = 0; j < r; j++){
                    if (need[i][j] > available[j]){
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0) {
                    q.push(i);
                    count++;
                    for (int j = 0; j < r; j++)
                        available[j] += allocation[i][j];
                    flag[i] = 1;
                }
            }	
		}
	}
	for(int i=0;i<p;i++){
    	if(flag[i]==0){
        	cout<<"\nDeadLock!";
        	return 0;
      	}
    }
	for(int i=0;i<p;i++){
		cout<<"Need p"<<i<<" - ";
		for(int j=0;j<r;j++){
			cout<<need[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nFinal available: ";
	for(int i=0;i<r;i++){
		cout<<available[i]<<" ";
	}
	cout<<"\nSafe state!\nSafe Sequence: ";
	while(!q.empty()) {
  		cout<<"p"<<q.front()<<" ";
  		q.pop();
	}
	return 0;
}
