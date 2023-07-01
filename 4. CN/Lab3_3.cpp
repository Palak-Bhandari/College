#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
int* divide(int data_bits[],int poly_bits[],int p){
	static int rem[10];
	for(int i=0;i<10;i++){
		rem[i]=data_bits[i];
	}
	for(int i=0;i<7;i++){
		if(rem[i]==1){
			for(int k=0;k<p;k++){
				if(rem[i+k]==poly_bits[k]){
					rem[i+k]=0;
				}else{
					rem[i+k]=1;
				}
			}
		}
	}
	return rem;
}
int main(){
	int p=4;
	int data_bits[10],poly_bits[p],r_arr[10];
	int rem[10],rem2[10];
	cout<<"Enter data bits: ";
	for(int i=0;i<7;i++){
		cin>>data_bits[i];
	}
	cout<<"Enter polynomial bits: ";
	for(int i=0;i<p;i++){
		cin>>poly_bits[i];
	}
	for(int i=7;i<7+p-1;i++){
		data_bits[i]=0;
	}
	int* p1 = divide(data_bits,poly_bits,p);
    for(int i=0;i<10;i++){
    	rem[i] = *(p1+i);
	}
	for(int i=7;i<7+p-1;i++){
		data_bits[i]=rem[i];
	}
	cout<<"CRC code is: ";
	for(int i=0;i<10;i++){
		cout<< data_bits[i];
	}
	srand(time(0));
	int err1 = rand() % 7;
	int err2 = rand() % 2;
	cout<<"\nError generated at: "<<err1<<" bit: "<<err2<<endl;
	for(int i=0;i<10;i++){
		r_arr[i]=data_bits[i];
	}
	r_arr[err1] = err2;
	cout<<"\nRecieved bits are: ";
	for(int i=0;i<7;i++){
		cout<<r_arr[i];
	}
	int* p2 = divide(r_arr,poly_bits,p);
    for(int i=0;i<10;i++){
    	rem2[i] = *(p2+i);
	}
	int flag=0;
	for(int i=0;i<10;i++){
		if(rem2[i]!=0){
			flag=1;
		}
	}
	if(flag==0){
		cout<<"\nNo Error detected!";
	}else{
		cout<<"\nError detected!";
	}
	return 0;
}
