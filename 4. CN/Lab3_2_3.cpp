#include<cstdlib>
#include<ctime>
#include<iostream>
#include<math.h>
using namespace std;
int get_redundant_bit(int m,int r,int n,int h[]){
	int R[12],r_bit[6];
	for(int i=1;i<7;i++){
		r_bit[i]=0;
	}
	bool temp = true;
	for(int i=0;i<=m+r;i++){
		int l = n;
		while(l--){
			if(temp) R[i] = 0;
			else R[i] = 1;
			i++;
		}
		i--;
		temp = !temp;
	}
	int j=1;
	for(int i=1;i<=m+r;i++){
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
	if(count % 2 == 0){
		r_bit[1]=0;
		return 0;
	}else{
		r_bit[1]=1;
		return 1;
	}
}
int* generate_hm(int m,int r,int data_bits[]){
	int k=0,j=1;
	int hc[m+r],rb[r];
	for(int i=1;i<=m+r;i++){
		if(i==pow(2,k)){
			hc[i]=-1;
			k++;
		}
		else{
			hc[i]=data_bits[j];
			j++;
		}
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
    	cout<<hc[i]<<" ";
	}
    return rb;
}
int main(){
	int m=7,r;
	while(pow(2,r) < m+r+1){
        r++;
    }
    cout<<"Redundant bits required for m = 7 are: "<<r;
    int data_bits[m];
    cout<<"\nEnter data bits: ";
    for(int i=m;i>0;i--){
    	cin>>data_bits[i];
	}
	int* rb = generate_hm(m,r,data_bits);
	cout<<"\nRedundant bits at transmitting end: ";
    for(int i=0;i<r;i++){
    	cout<<*(rb+i)<<" ";
	} 
	int err_bits[m];
	srand(time(0));
	int err1 = rand() % 7;
	int err2 = rand() % 2;
	cout<<"\n\nError generated at: "<<err1<<" bit: "<<err2<<endl;
	for(int i=1;i<=m;i++){
		err_bits[i]=data_bits[i];
	}
	err_bits[err1] = err2; 
	cout<<"Bits recieved: ";
	for(int i = m;i>0;i--){
    	cout<<err_bits[i]<<" ";
	}
	int* rb1 = generate_hm(m,r,err_bits);
    cout<<"\nRedundant bits at reciever end: ";
    for(int i=0;i<r;i++){
    	cout<<*(rb1+i)<<" ";
	}
    int flag=0;
    for(int i=0;i<r;i++){
    	if(rb[i]==rb1[i]){
    		flag = 1;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<"\n\nNo error detected!";
	}
	else{
		cout<<"\n\nError detected!";
	}
	return 0; 
}
