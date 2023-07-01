// Stop and Wait ARQ
#include<iostream>
#include<ctime>
#include<cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
int main(){
    int rand_no,total_frames;
    cout<<" Enter total number of frames: ";
    cin>>total_frames;
    int frame[total_frames];
    cout<<" Enter frame numbers: ";
    for(int i=1;i<=total_frames;i++){
	    cin>>frame[i];
	}
	int i=1;
    do{
        cout<<"\n Sending frame "<<frame[i]<<" .... ";
        Sleep(2000);
        cout<<"\n Waiting for Acknowledgement .... ";
        Sleep(2000);
    	srand(time(0)); 
    	rand_no=(rand()%2);
    	if(rand_no==1){
    	    cout<<"\n Acknowlegment Recieved for frame no: "<<frame[i];
    	}
    	else{
    	    cout<<"\n Acknowledgment NOT Recieved for frame no: "<<frame[i];
    	    cout<<"\n Resending frame .... ";
    	    total_frames++;
    	    i--;
    	}
	    Sleep(2000);
	    i++;
	    total_frames--;
	    cout<<"\n";
    }while(total_frames>0);
    cout<<"\n Completed!";
    return 0;
}
