#include<iostream>
using namespace std;
class loan{
	public:
		float principal,rate,yrs,emi;
		int arr[10];
		void get_data();
		float calculate();
};
void loan::get_data(){
	cout<<"Enter the principal amount: ";
	cin>>principal;
	cout<<"Enter the rate of intrest(in %): ";
	cin>>rate;
	cout<<"Enter the time duration(in yrs): ";
	cin>>yrs;
	cout<<"Enter the emi amount: ";
	cin>>emi;
}
float loan::calculate(){
	for(int i=1;i<=yrs;i++){
		if(yrs>0){
			arr[0]=principal;
			arr[i]=arr[i-1]*(1+(rate/100))-emi;
			cout<<"Amount to be paid in "<<i<<" year is: "<<arr[i]<<endl;
		}
	}
	return 1;
}
int main(){
	loan l;
	int ch,x;
	do{
		cout<<"Choose the type of loan\n1.Personal Loan\n2.Car Loan\n3.Home loan\n4.Education Loan: ";
		cin>>ch;
		switch(ch){
			case 1: l.get_data();
					l.calculate();
					break;
			case 2: l.get_data();
					l.calculate();
					break;
			case 3: l.get_data();
					l.calculate();
					break;
			case 4: l.get_data();
					l.calculate();
					break;
			default:cout<<"Invalid choice!";
		}
		cout<<"Press 1 to continue: ";
		cin>>x;
	}while(x==1);
}
