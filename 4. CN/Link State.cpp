#include<bits/stdc++.h>
using namespace std;
int main(){
	int count,src_router,i,j,k,w,v,min;
	cout<<"Enter the no of routers: ";
	cin>>count;
	int cost_matrix[count][count],dist[count],last[count];
	int flag[count];
	cout<<"Enter the cost matrix values(Enter -1 for no direct edge): \n";
	for(i=0;i<count;i++){
		for(j=i+1;j<count;j++){
			cout<<i<<" -> "<<j<<": ";
			cin>>cost_matrix[i][j];
			cost_matrix[j][i] = cost_matrix[i][j];
			if(cost_matrix[i][j]<0) cost_matrix[i][j]=999;
		}
	}
	cout<<"Enter the source router: ";
	cin>>src_router;
	for(v=0;v<count;v++){
		flag[v]=0;
		last[v]=src_router;
		dist[v]=cost_matrix[src_router][v];
	}
	flag[src_router]=1;
	for(i=0;i<count;i++){
		min=999;
		for(w=0;w<count;w++){
			if(!flag[w])
			if(dist[w]<min){
				v=w;
				min=dist[w];	
			}	
		}	
		flag[v]=1;	
		for(w=0;w<count;w++){	
			if(!flag[w])	
			if(min+cost_matrix[v][w]<dist[w]){	
				dist[w]=min+cost_matrix[v][w];	
				last[w]=v;	
			}	
		}	
	}
	for(i=0;i<count;i++){
		if(i!=src_router){
			cout<<"\n Router "<<src_router<<" -> Router "<<i<<", Cost: "<<dist[i];
			cout<<"\nPath taken: "<< i;
			w=i;
			while(w!=src_router){	
				cout<<" <- "<<last[w];
				w=last[w];	
			}	
		}	
	}
	return 0;
}
