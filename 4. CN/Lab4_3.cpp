// Selective ARQ
#include<iostream>
#include<ctime>
#include<cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<math.h>
using namespace std;
int resend_frame(int temp[],int size){
	int rand1;
	int s = sizeof(temp)/sizeof(temp[0]);
	for(int i=0;i<s;i++){
		if(temp[i]!=-1){
			cout<<"\nResending frame: "<<temp[i]<<" ...";
			Sleep(1000);
			srand(time(0));
			rand1=rand()%2;
			if(rand1==0){
				Sleep(1000);
				cout<<"\nAcknowledgment NOT recieved for frame: "<<temp[i];
				resend_frame(temp,size);
			}
			else{
				Sleep(1000);
				cout<<"\nAcknowledgment recieved for frame: "<<temp[i];
				temp[i]=-1;
			}
		}
	}
}
int main(){
	int no,size;
	cout<<"Enter total no of frames: ";
	cin>>no;
	cout<<"Enter window size: ";
	cin>>size;	
	int j;
	int temp[size];
	for(int i=0;i<size;i++){
		temp[i]=-1;
	}
	int z=1,rand1;
	while(z<=no){
		int y=0;
		for(int i=z; i<z+size && z<=no;i++){
			cout<<"\nSending frame: "<<i<<" ..."; 
			Sleep(1000);
		}
		j=0;
		for(int i=z; i<z+size && z<=no;i++){
			srand(time(0));
			rand1=rand()%2;
			if(rand1==0){
				Sleep(1000);
				cout<<"\nAcknowledgment NOT recieved for frame: "<<i<<" ...";
				temp[j]=i;
				j++;
			}
			else{
				Sleep(1000);
				cout<<"\nAcknowledgment recieved for frame: "<<i<<" ...";
			}
		}
		resend_frame(temp,size);
		cout<<endl;
		z = z + size;	
	}
	cout<<"\nCompleted!";
	return 0;	
}
