#include<iostream>
using namespace std;
#define SIZE 5
class customer{
	public:
		int bid;
		string name;
};
class Cqueue{
	customer c[SIZE];
	int f,r;
	public:
		Cqueue(){
			f = -1;
			r = -1;
		}
		bool is_empty(){
			if(f==-1 && r==-1)
				return true;
			else 
				return false;
		}
		bool is_full(){
			if((r+1)%SIZE==f)
				return true;
			else
				return false;
		}
		void enqueue(int id,string n){
			if(!is_full()){
				if(is_empty())
					f = 0;
				r = (r+1)%SIZE;
				c[r].bid = id;
				c[r].name = n;
			}
			else{
				cout<<"\nWaiting is full!\n";
			}
		}
		void dequeue(){
			if(!is_empty()){
				if(f == r){
					cout<<"\nCall for appointment  waiting no: "<<c[f].bid<<"  Patient name: "<<c[f].name<<endl;
					f = -1;
					r = -1;
				}
				else{
					cout<<"\nCall for appointment  waiting no: "<<c[f].bid<<"  Patient name: "<<c[f].name<<endl;
					f = (f+1)%SIZE;	
				}
			}
			else{
				cout<<"\nNo one in waiting cannot call for appointment!";
			}
		}
		void display(){
			int i;
			if(!is_empty()){
				if(r>=f){
					for(i=f;i<=r;i++){
						cout<<"Waiting  no: "<<c[i].bid<<"  patient name: "<<c[i].name<<endl;		
					}
				}
				else{
					for(i=f;i<SIZE;i++)
						cout<<"Waiting  no: "<<c[i].bid<<"  patient name: "<<c[i].name<<endl;
					for(i=0;i<=r;i++)
						cout<<"Waiting  no: "<<c[i].bid<<"  patient name: "<<c[i].name<<endl;
				}	
			}
			else{
				cout<<"\nNo one in waiting!";
			}
		}
};
int main(){
	Cqueue q;
	int ch,x,i;
	do{
		cout<<"1.Add in waiting list\n2.Call for appointment\n3.Display waiting list\n4.Exit: ";
		cin>>ch;
		string n;
		switch(ch){
			case 1:	cout<<"\nEnter waiting no and patient name: ";
					cin>>i>>n;
					q.enqueue(i,n);
					break;
			case 2:	q.dequeue();
					break;
			case 3: cout<<"\n-----Display of waiting list-----\n";
					q.display();
					break;
			case 4: exit(0);
					break;
			default:cout<<"\nInvalid Choice!\n";
		}
		cout<<"Press 1 to continue: ";
		cin>>x;
	} while(x==1);
	return 0;
}
/*
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and patient name: 1 aaa
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and patient name: 2 bbb
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and patient name: 3 ccc
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 2

Call for appointment  waiting no: 1  Patient name: aaa
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 3

-----Display of waiting list-----
Waiting  no: 2  patient name: bbb
Waiting  no: 3  patient name: ccc
Press 1 to continue: 2

--------------------------------
Process exited after 17.28 seconds with return value 0
Press any key to continue . . .*/
