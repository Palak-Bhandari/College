/*Suppose that a person deposits 10000rs in a saving account at a bank yielding 11% year with 
interest compounded annually. How much the will be the amount after 30 years.*/
#include<iostream>
using namespace std;
class bank{
	public:
		float principal,rate,yrs;
		int a[10];
		void get_data();
		void calculate();
};
void bank::get_data(){
	cout<<"Enter the principal amount: ";
	cin>>principal;
	cout<<"Enter the rate of intrest(in %): ";
	cin>>rate;
	cout<<"Enter the time duration(in yrs): ";
	cin>>yrs;
}
void bank::calculate(){
	for(int i=1;i<=yrs;i++){
		if(yrs>0){
			a[0]=principal;
			a[i]=a[i-1]*(1+(rate/100));
			cout<<"The Amount in "<<i<<" year is: "<<a[i]<<endl;
		}
	}
}
int main(){
	bank b;
	int x;
	do{
		b.get_data();
		b.calculate();
		cout<<"Press 1 to continue: ";
		cin>>x;
	}while(x==1);	
	return 0;
}
/*
Enter the principal amount: 10000
Enter the rate of intrest(in %): 11
Enter the time duration(in yrs): 30
The Amount in 1 year is: 11100
The Amount in 2 year is: 12321
The Amount in 3 year is: 13676
The Amount in 4 year is: 15180
The Amount in 5 year is: 16849
The Amount in 6 year is: 18702
The Amount in 7 year is: 20759
The Amount in 8 year is: 23042
The Amount in 9 year is: 25576
The Amount in 10 year is: 28389
The Amount in 11 year is: 31511
The Amount in 12 year is: 34977
The Amount in 13 year is: 38824
The Amount in 14 year is: 43094
The Amount in 15 year is: 47834
The Amount in 16 year is: 53095
The Amount in 17 year is: 58935
The Amount in 18 year is: 65417
The Amount in 19 year is: 72612
The Amount in 20 year is: 80599
The Amount in 21 year is: 89464
The Amount in 22 year is: 99305
The Amount in 23 year is: 110228
The Amount in 24 year is: 122353
The Amount in 25 year is: 135811
The Amount in 26 year is: 150750
The Amount in 27 year is: 167332
The Amount in 28 year is: 185738
The Amount in 29 year is: 206169
The Amount in 30 year is: 228847
Press 1 to continue: 2

--------------------------------
Process exited after 8.425 seconds with return value 3221225477
Press any key to continue . . .
*/

