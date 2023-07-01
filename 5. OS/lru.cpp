#include<bits/stdc++.h>
using namespace std;
int find_index(int i1, int num, int ref[]){
	int index = -1;
	for(int i = i1; i >= 0; i--){
		if(ref[i] == num){
			index=i;
			break;
		}
	}
	return index;
}
int minOfIndex(int f, int min_i[]){
	int smallest = INT_MAX;
	int index = -1;
	for(int i = 0; i < f; i++){
	    if(min_i[i] < smallest){
	        smallest = min_i[i];
	        index = i;
	    }
	}
	return index;
}
bool is_not_present(int frame[],int r,int i1){
	for(int i=i1-1;i>=0;i--){
		if(frame[i]==r) return false;
	}
	return true;
}
int main(){
	int n,f,page_fault=0;
	cout<<"Enter size of reference string: ";
	cin>>n;
	cout<<"Enter size of frame: ";
	cin>>f;
	int ref[n],frame[f],min_i[f];
	cout<<"Enter the reference string: ";
	for(int i=0;i<n;i++){
		cin>>ref[i];
	}
	frame[0]=ref[0];
	page_fault++;
	cout<<frame[0]<<" ";
	min_i[0] = find_index(0,ref[0],ref);
	for(int i=1;i<f;i++){
		if(is_not_present(frame,ref[i],i)){
			frame[i]=ref[i];
			page_fault++;
		}
		min_i[i] = find_index(i,ref[i],ref);
		cout<<frame[i]<<" ";
	}
	cout<<endl;
	int k = minOfIndex(f,min_i);
	for(int i=f;i<n;i++){
		int flag=0;
		for(int j=0;j<f;j++){
			if(frame[j] == ref[i]){
				min_i[j] = find_index(i,ref[i],ref);
				k = minOfIndex(f,min_i);
				flag=1;
				break;
			} 
			else{
				flag=0;
			}	
		}
		if(flag == 0){
			if(k<f){
				frame[k]=ref[i];
				min_i[k] = find_index(i,ref[i],ref);
				k = minOfIndex(f,min_i);
				page_fault++;
				for(int l=0;l<f;l++){
					cout<<frame[l]<<" ";
				}
				cout<<endl;
			}
		}
	}
	cout<<"The page fault is: "<<page_fault;
}
// 7 0 1 2 0 3 0 4 3 0 3 2
// 0 2 1 6 4 0 1 0 3 1 2 1
