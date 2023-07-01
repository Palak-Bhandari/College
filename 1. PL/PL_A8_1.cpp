#include<iostream>
using namespace std;
#define SIZE 5
class customer{
	public:
		int bid;
		string name;
};
class Queue{
	public:
		customer e[SIZE];
		int front,rear;
		Queue(){
			front = -1;
			rear = -1;
		}
		bool is_empty(){
			if(front == -1 && rear == -1)
				return true;
			else 
				return false;
		}
		bool is_full(){
			if(rear == SIZE-1)
				return true;
			else
				return false;
		}
		void enqueue(int id,string n){
			if(!is_full()){
				if(is_empty()){
					front++;
				}
				rear++;
				e[rear].bid=id;
				e[rear].name=n;
			}
			else{
				cout<<"\nWaiting is full!!";
			}
		}
		void dequeue(){
			if(!is_empty()){
				if(front==rear){
					front = -1;
					rear = -1;
				}
				else{
					cout<<"Up for Appointment  Waiting No: "<<e[front].bid<<"  Patient name: "<<e[front].name<<endl;
					front++;
				}
			}
			else{
				cout<<"\nNo one in waiting cannot call for appointment!";
			}
		}
		void display(){
			if(!is_empty()){
				for(int i=front;i<=rear;i++){
					cout<<"Waiting No: "<<e[i].bid<<"  Patient name: "<<e[i].name<<endl;
				}
			}
			else{
				cout<<"\nNo one in waiting!";
			}
		}
};
int main(){
	Queue q;
	int ch,x,i;
	do{
		cout<<"1.Add in waiting list\n2.Call for appointment\n3.Display waiting list\n4.Exit: ";
		cin>>ch;
		string n;
		switch(ch){
			case 1:	cout<<"\nEnter waiting no and Patient name: ";
					cin>>i>>n;
					q.enqueue(i,n);
					break;
			case 2:	q.dequeue();
					break;
			case 3: cout<<"\n-----Display of waiting list -----\n";
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

Enter waiting no and Patient name: 1 aaa
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and Patient name: 2 bbb
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and Patient name: 3 ccc
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 2
Up for Appointment  Waiting No: 1  Patient name: aaa
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and Patient name: 4 ddd
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 2
Up for Appointment  Waiting No: 2  Patient name: bbb
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 3

-----Display of waiting list -----
Waiting No: 3  Patient name: ccc
Waiting No: 4  Patient name: ddd
Press 1 to continue: 2

--------------------------------
Process exited after 50.43 seconds with return value 0
Press any key to continue . . .
*/
