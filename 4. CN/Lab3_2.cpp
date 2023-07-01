#include<cstdlib>
#include<ctime>
#include<iostream>
#include<math.h>
using namespace std;
int get_redundant_bit(int m,int r,int n,int hamming_code[]){
	static int R[11];
	static int r_bit[7];
	int k=0;
	int count0=0,count1=0;
	for(int i=0;i<n;i++){
		R[i]=0;
		count0++;
	}
	for(int i=n;i<=m+r;i++){
		if(count0=n){
			R[i]=1;
			count1++;
			count0--;
		}
		else if(count1=n){
			R[i]=0;
			count0++;
			count1--;
		}
	}
	for(int i=0;i<=m+r;i++){
    	if(R[i]==1){
    		r_bit[i]=hamming_code[i];
		}
	}
	int count=0;
	for(int i=1;i<=m+r;i++){
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

int* error_generate(int data_bits[]){
	static int err_bits[7];
	srand(time(0));
	int err1 = rand() % 7;
	int err2 = rand() % 2;
	cout<<"\nError generated at: "<<err1<<" bit: "<<err2<<endl;
	for(int i=1;i<=7;i++){
		err_bits[i]=data_bits[i];
	}
	err_bits[err1] = err2;
	return err_bits;
}
int main() {
    int m = 7,r = 0;
    while(pow(2,r) < m+r+1){
        r++;
    }
    int hamming_code[11],data_bits[m],redundant_bits[r];  
    cout<<"Redundant bits required: "<<r<<endl;
    cout<<"\nEnter data bits: ";
    for(int i = 1; i <= m; i++)
        cin>>data_bits[i];
    
    int j=r-1,k = 1;    
    for(int i=m+r; i>0; i--){    
        if(i == pow(2, j)){
            hamming_code[i] = -1;  
            j--;
        }else{
            hamming_code[i] = data_bits[k];
            k++;
        }
    }  
	k=0,j=0;
	for(int i=1;i<=r;i=pow(2,k)){
		redundant_bits[k] = get_redundant_bit(m,r,i,hamming_code);
		k++;
	}
	for(int i = 1; i <= m + r; i++){    
        if(i == pow(2, j)){
            hamming_code[i] = redundant_bits[j];  
            j++;
        }
    }
    cout<<"\nHamming code: ";
    for(int i=1;i<=m+r;i++){
    	cout<<hamming_code[i];
	}
	cout<<"\nRedundant bits: ";
    for(int i=1;i<=r;i++){
    	cout<<redundant_bits[i];
	}      
    int* p;
    int recieved_bits[m+r];
    p = error_generate(data_bits);
    for(int i = 1;i<=m+r;i++){
    	recieved_bits[i] = *(p+i);
	}
	for(int i = 1;i<=m+r;i++){
    	cout<<recieved_bits[i];
	}
    return 0;
}
