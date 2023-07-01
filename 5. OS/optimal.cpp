#include<bits/stdc++.h>
using namespace std;
int count_occ(int n, int i1, int ref[], int num){
	int count = 0;
	for(int i = i1+1; i < n; i++){
		if(ref[i] == num){
			count++;
		}
	}
	return count;
}
int min_occ_index(int f,int occ[]){
	int smallest = INT_MAX;
	int index = -1;
	for(int i = 0; i < f; i++){
	    if(occ[i] < smallest){
	        smallest = occ[i];
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
	int ref[n],frame[f],occ[f];
	cout<<"Enter the reference string: ";
	for(int i=0;i<n;i++){
		cin>>ref[i];
	}
	frame[0]=ref[0];
	page_fault++;
	cout<<frame[0]<<" ";
	occ[0] = count_occ(n,0,ref,ref[0]);
	for(int i=1;i<f;i++){
		if(is_not_present(frame,ref[i],i)){
			frame[i]=ref[i];
			occ[i] = count_occ(n,i,ref,ref[i]);
			page_fault++;
		}
		cout<<frame[i]<<" ";
	}
	cout<<endl;
	int k = min_occ_index(f,occ);
	for(int i=f;i<n;i++){
		int flag=0;
		for(int j=0;j<f;j++){
			if(frame[j] == ref[i]){
				flag=1;
				break;
			} 
			else flag=0;	
		}
		if(flag == 0){
			if(k<f){
				frame[k]=ref[i];
				occ[k] = count_occ(n,i,ref,ref[i]);
				k = min_occ_index(f,occ);
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
