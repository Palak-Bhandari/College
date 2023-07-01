#include<iostream>
using namespace std;
class parity_checker{
	string s;
	int b[100];
	public:
		void input();
		void find_parity();
};
void parity_checker::input(){
	cout<<"Enter any string: ";
	cin>>s;
}
void parity_checker::find_parity(){
	int n = s.length();
	int j=0;
	int counter = 0;
	for(int i=0;i<n;i++){
		int val = int(s[i]);
		while(val>0){
			b[j]=val%2;
			val/=2;
			j++;
		}
		for(int i=0;i<j;i++){
			if(b[i]==1){
				counter++;
			}
		}	
	}
	if(counter%2==0)
		cout<<"Even Parity";
	else
		cout<<"Odd Parity";
}
int main(){
	parity_checker p;
	p.input();
	p.find_parity();
}
/*
Enter any string: Palak
Odd Parity
--------------------------------
Process exited after 3.487 seconds with return value 0
Press any key to continue . . .
*/
