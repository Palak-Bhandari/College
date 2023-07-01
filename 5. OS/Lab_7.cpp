#include<bits/stdc++.h>
using namespace std;
bool is_not_present(int frame[],int r,int i1){
	for(int i=i1-1;i>=0;i--){
		if(frame[i]==r) return false;
	}
	return true;
}
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
int fifo(int frame[],int ref[],int f,int n){
	int page_fault=0;
	frame[0]=ref[0];
	page_fault++;
	cout<<frame[0]<<" ";
	for(int i=1;i<f;i++){
		if(is_not_present(frame,ref[i],i)){
			frame[i]=ref[i];
			page_fault++;
		}
		cout<<frame[i]<<" ";
	}
	cout<<endl;
	int k=0;
	for(int i=f;i<n;i++){
		int flag=0;
		for(int j=0;j<f;j++){
			if(frame[j] == ref[i]){
				flag=1;
				break;
			} 
			else flag=0;	
		}
		if(flag==0){
			if(k<f){
				frame[k]=ref[i];
				k++;
				page_fault++;
				for(int l=0;l<f;l++){
					cout<<frame[l]<<" ";
				}
				cout<<endl;
			}
			if(k==f){
				k=0;
			}
		}
	}
	return page_fault;
}
int lru(int frame[],int ref[],int f,int n){
	int page_fault=0;
	int min_i[f];
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
	return page_fault;
}
int optimal(int frame[], int ref[], int f, int n){
	int page_fault = 0;
	int occ[f];
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
	return page_fault;
}
int main(){
	int n, ch, f, pg;
	cout<<"Enter size of reference string: ";
	cin>>n;
	cout<<"Enter size of frame: ";
	cin>>f;
	int ref[n],frame[f];
	cout<<"Enter the reference string: ";
	for(int i=0;i<n;i++){
		cin>>ref[i];
	}
	cout<<"1. FIFO\n2. LRU\n3. Optimal\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1: pg = fifo(frame,ref,f,n);
				break;
		case 2: pg = lru(frame,ref,f,n);
				break;
		case 3: pg = optimal(frame,ref,f,n);
				break;
		default:cout<<"Inalid Input!";
				return 0;
	}
	cout<<"The page fault is: "<<pg;
}
