// page replacement algo
#include<bits/stdc++.h>
using namespace std;
bool is_not_present(int i1, int r, int frame[]){
	for(int i=i1-1;i>=0;i--){
		if(frame[i]==r){
			return false;
		}
	}
	return true;
} 
int find_index(int i1, int ref[], int r){
	int index = -1;
	for(int i=i1;i>=0;i--){
		if(ref[i]==r){
			index = i;
			break;
		}
	}
	return index;
}
int find_smallest(int f, int recent_index[]){
	int smallest = INT_MAX;
	int index = -1;
	for(int i=0;i<f;i++){
		if(recent_index[i]<smallest){
			smallest = recent_index[i];
			index = i;
		}
	}
	return index;
}
int main(){
	int n,f,pf=0,flag;
	cout<<"Enter size of ref string and frame: ";
	cin>>n>>f;
	int ref[n], frame[f], recent_index[f];
	cout<<"Enter ref string: ";
	for(int i=0;i<n;i++){
		cin>>ref[i];
	}
	frame[0]=ref[0];
	pf++;
	recent_index[0]=find_index(0,ref,ref[0]);
	cout<<frame[0]<<" ";
	for(int i=1;i<f;i++){
		if(is_not_present(i,ref[i],frame)){
			frame[i]=ref[i];
			pf++;
		} 
		recent_index[i]= find_index(i,ref,ref[i]);
		cout<<frame[i]<<" ";
	}
	cout<<endl;
	int k = find_smallest(f,recent_index);
	cout<<k<<endl;
	for(int j=f;j<n;j++){
		flag=0;
		for(int i=0;i<f;i++){
			if(frame[i]==ref[j]){
				flag=1;
				recent_index[i]= find_index(j,ref,ref[j]);
				k = find_smallest(f,recent_index);
				cout<<k<<endl;
				break;
			}
		}
		if(flag==0){
			if(k<f){
				frame[k]=ref[j];
				pf++;
				recent_index[j]= find_index(j,ref,ref[j]);
				k = find_smallest(f,recent_index);
				cout<<k<<endl;
				for(int i=0;i<f;i++){
					cout<<frame[i]<<" ";
				}
				cout<<endl;
			}
		}
	}
	cout<<pf;
	return 0;
}
