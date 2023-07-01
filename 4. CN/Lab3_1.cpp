#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void check_parity(int t_arr[]){
	int count_ones=0;
	for(int i=0;i<8;i++){
		if(t_arr[i]==1){
			count_ones++;
		}
	}
	if(count_ones%2==0){
		t_arr[7]=0;
	}else{
		t_arr[7]=1;
	}
}
int* error_generate(int t_arr[]){
	static int r_arr[8];
	srand(time(0));
	int err1 = rand() % 7;
	int err2 = rand() % 2;
	cout<<"Error generated at: "<<err1<<" bit: "<<err2<<endl;
	for(int i=0;i<7;i++){
		r_arr[i]=t_arr[i];
	}
	r_arr[err1] = err2;
	check_parity(r_arr);
	return r_arr;
}
void reciever_end(int t_arr[],int r_arr[]){
	cout<<"Bits recieved : ";
	for(int i=0;i<8;i++){
		cout<<r_arr[i]<<" ";
	}
	int temp = t_arr[7];
	if(temp == r_arr[7]){
		cout<<"\n No Error Detected";
	}else{
		cout<<"\n Error Detected";
	}
}
int main(){
 	int t_arr[8];
 	cout<<"enter bits:";
	for(int i=0;i<7;i++){
		cin>>t_arr[i];
	}   
	check_parity(t_arr);
	int* r_arr= error_generate(t_arr);
	reciever_end(t_arr,r_arr);                                                                               
	return 0;
}

