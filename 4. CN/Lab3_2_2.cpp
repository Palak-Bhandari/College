#include<cstdlib>
#include<ctime>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int m=7,r,k=0,j=1;
	while(pow(2,r) < m+r+1){
        r++;
    }
    cout<<"Redundant bits required: "<<r;
    int data_bits[m], hc[m+r], hc1[m+r];
    cout<<"\nEnter data bits: ";
    for(int i=m;i>0;i--){
    	cin>>data_bits[i];
	}
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
	for(int i=m+r;i>0;i--){
		cout<<hc[i]<<" ";
	}
	int ithBit = 0;
	for (int i = 1; i <= m+r; i++) {
		int setBits = 0 ;
		if (hc[i] == -1) {
			for (int j = 1 ; j <= m+r; j++) {
				if ((j & (1 << ithBit)) != 0) {
					if (hc[j] == 1) 
						setBits++;
				}
			}
			ithBit++;
			if (setBits & 1) 
				hc[i] = 1 ;
			else 
				hc[i] = 0 ;
		}
	}
    cout<<"\nHamming code at transmitting end: ";
    for(int i=m+r;i>0;i--){
    	cout<<hc[i]<<" ";
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
	cout<<"\nBits recieved: ";
	for(int i=m;i>0;i--){
    	cout<<err_bits[i]<<" ";
	}
	k=0,j=1;
	for(int i=1;i<=m+r;i++){
		if(i==pow(2,k)){
			hc1[i]=-1;
			k++;
		}
		else{
			hc1[i]=err_bits[j];
			j++;
		}
	}
	cout<<endl;
	for(int i=m+r;i>0;i--){
		cout<<hc1[i]<<" ";
	}
	ithBit = 0 ;
	for (int i = 1; i <= m+r ; i++) {
		int setBits = 0 ;
		if (hc1[i] == -1) {
			for (int j = 1 ; j <= m+r; j++) {
				if ((j & (1 << ithBit)) != 0) {
					if (hc1[j] == 1) 
						setBits++;
				}
			}
			ithBit++;
			if (setBits & 1) 
				hc1[i] = 1 ;
			else 
				hc1[i] = 0 ;
		}
	}
    cout<<"\nHamming code at reciever end: ";
    for(int i=m+r;i>0;i--){
    	cout<<hc1[i]<<" ";
	}
	int flag=1;
    for(int i=1;i<m+r;i++){
    	if(hc[i]!=hc1[i]){
    		flag=0;
    		break;
		}
	}
	if(flag==0){
		cout<<"\nError detected!";
	}
	else{
		cout<<"\nNo Error detected!";
	}
	return 0; 
}
