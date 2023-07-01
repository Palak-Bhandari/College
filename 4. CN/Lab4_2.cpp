// Go Back N ARQ
#include<iostream>
#include<ctime>
#include<cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
int main() {
	int total_frame,size;
	srand(time(0));
	cout<<"Enter Total number of frames: ";
	cin>>total_frame;
	cout<<"Enter Window Size: ";
	cin>>size;
	int i=1;
	while(i<=total_frame){
		int k=0;
		for(int j = i; j < i + size && j <= total_frame; j++){
		  cout<<"Sending Frame " << j << "..." << endl;
		  Sleep(1000);
		}
		for(int j = i; j < i + size && j <= total_frame; j++){
		    int rand_no = rand() % 2;
		    if(rand_no!=0){
			    cout<<"Acknowledgment Recieved for Frame no: "<<j<<endl;
			    Sleep(2000);
			    k++;
		    }else{
			    cout<<"Acknowledgment NOT Recieved for Frame no: "<<j<<endl;
			    cout<<"Resending Window ... "<<endl;
			    Sleep(2000);
			    break;
		    }
		}
		cout<<"\n";
		i = i + k;
	}
	cout<<"Completed!";
	return 0;
}
