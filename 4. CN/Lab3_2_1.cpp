#include<cstdlib>
#include<ctime>
#include<iostream>
#include<math.h>
using namespace std;
int get_redundant_bit(int m,int r,int n,int h[]){
	static int R[12];
	static int r_bit[6];
	int k=0;
	int count0=0,count1=0;
	for(int i=0;i<6;i++){
		r_bit[i]=0;
	}
	for(int i=0;i<n;i++){
		R[i]=0;
		count0++;
	}
	for(int i=n;i<=m+r;i++){
		if(count0==n){
			R[i]=1;
			count1++;
			count0--;
		}
		else if(count1==n){
			R[i]=0;
			count0++;
			count1--;
		}
	}
	int j=1;
	for(int i=0;i<=m+r;i++){
    	if(R[i]==1){
    		r_bit[j]=h[i];
    		j++;
		}
	}
	int count=0;
	for(int i=2;i<7;i++){
		if(r_bit[i]==1){
			count++;
		}
	}
	if(count%2==0){
		r_bit[0]=0;
		return 0;
	}else{
		r_bit[0]=1;
		return 1;
	}
}
int main(){
	int m=7,r,k=0,j=1;
	while(pow(2,r) < m+r+1){
        r++;
    }
    cout<<"Redundant bits required: "<<r;
    int data_bits[m],hc[m+r],rb[r];
    cout<<"\nEnter data bits: ";
    for(int i=m;i>0;i--){
    	cin>>data_bits[i];
	}
	for(int i=1;i<=m+r;i++){
		if(i==pow(2,k)){
			hc[i]=2;
			k++;
		}
		else{
			hc[i]=data_bits[j];
			j++;
		}
	}
	for(int i=1;i<=m+r;i++){
		cout<<hc[i];
	}
	for(int k=0;k<r;k++){
		int i=pow(2,k);
		rb[k] = get_redundant_bit(m,r,i,hc);
	}
	j=0;
	for(int i = 1; i <= m + r; i++){    
        if(i == pow(2, j)){
            hc[i] = rb[j];  
            j++;
        }
    }
    cout<<"\nHamming code: ";
    for(int i=1;i<=m+r;i++){
    	cout<<hc[i];
	}
	cout<<"\nRedundant bits: ";
    for(int i=0;i<r;i++){
    	cout<<rb[i];
	} 
	int err_bits[m];
	srand(time(0));
	int err1 = rand() % 7;
	int err2 = rand() % 2;
	cout<<"\nError generated at: "<<err1<<" bit: "<<err2<<endl;
	for(int i=1;i<=m;i++){
		err_bits[i]=data_bits[i];
	}
	err_bits[err1] = err2;  
	for(int i = 1;i<=m;i++){
    	cout<<err_bits[i];
	}
	return 0; 
}
