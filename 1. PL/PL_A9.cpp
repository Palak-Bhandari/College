#include<iostream>
#define SIZE 5
using namespace std;
class customer{
public:
	int cid;
	string name;
};
class DEQueue{
customer a[SIZE];
int front,rear;
public:
	DEQueue(){
		front = -1;
		rear = -1;
	}
	void insert_at_front(int, string);
	void insert_at_rear(int, string);
	void delete_at_front();	
	void delete_at_rear();	
	void get_rear();
	void get_front();
	bool is_full();
	bool is_empty();
	void display();		
};
bool DEQueue :: is_empty(){
	if(front == -1 && rear == -1)
		return true;
	return false;
}
bool DEQueue :: is_full(){
	if(front == (rear+1)%SIZE)
		return true;
	return false;
}
void DEQueue :: insert_at_front(int id, string sname){
	if(is_full()){
		cout<<"\nBooking is Full!";
	}
	else{
		if(is_empty())
			front = rear = 0;
		else
			front = (SIZE + (front-1))%SIZE;
		a[front].cid = id;
		a[front].name = sname;
	}
}
void DEQueue :: insert_at_rear(int id, string sname){
	if(is_full()){
		cout<<"\nBooking is Full!";
	}
	else{
		if(is_empty())
			front = rear = 0;
		else
			rear = (rear+1)%SIZE;
		a[rear].cid = id;
		a[rear].name = sname;
	}
}
void DEQueue :: delete_at_front(){
	if(is_empty()){
		cout<<"\nNo bookings yet!";
	}
	else{
		cout<<"\nBooking id: "<<a[front].cid<<"  Name: "<<a[front].name<<endl;
		if(front == rear)
			front = rear = -1;
		front = (front + 1)% SIZE;
	}
}
void DEQueue :: delete_at_rear(){
	if(is_empty()){
		cout<<"\nNo bookings yet!";
	}
	else{
		cout<<"\nBooking id: "<<a[rear].cid<<"  Name: "<<a[rear].name<<endl;
		if(front == rear)
			front = rear = -1;
		else
			rear = (SIZE+(rear-1))% SIZE;
	}
}
void DEQueue :: get_front(){
	if(is_empty()){
		cout<<"\nNo bookings yet!";
	}
	else{
		cout<<"\nAt front Booking id: "<<a[front].cid<<"  Name: "<<a[front].name<<endl;
	}
}
void DEQueue :: get_rear(){
	if(is_empty()){
		cout<<"\nNo bookings yet!";
	}
	else{
		cout<<"\nAt end Booking id: "<<a[rear].cid<<"  Name: "<<a[rear].name<<endl;
	}
}
void DEQueue :: display(){
	int i;
	if(!is_empty()) {
		if(front<=rear){
			for(i=front;i<=rear;i++){
				cout<<"Booking id: "<<a[i].cid<<"  Name: "<<a[i].name<<endl;		
			}
		}
		else{
			for(i=front;i<SIZE;i++)
				cout<<"Booking id: "<<a[i].cid<<"  Name: "<<a[i].name<<endl;
			for(i=0;i<=rear;i++)
				cout<<"Booking id: "<<a[i].cid<<"  Name: "<<a[i].name<<endl;
		}	
	}
	else {
		cout<<"\nNo bookings yet!";
	}
}
int main(){
	DEQueue q;
	int ch,x,i;
	do{
		cout<<"1.Enqueue at front\n2.Enqueue at rear\n3.Dequeue at front\n4.Dequeue at rear\n5.Get front\n6.Get rear\n7.Display\n8.Exit: ";
		cin>>ch;
		string n;
		switch(ch){
			case 1:	cout<<"\nEnter booking id and name: ";
					cin>>i>>n;
					q.insert_at_front(i,n);
					break;
			case 2:	cout<<"\nEnter booking id and name: ";
					cin>>i>>n;
					q.insert_at_rear(i,n);
					break;
			case 3:	q.delete_at_front();
					break;
			case 4:	q.delete_at_rear();
					break;
			case 5:	q.get_front();
					break;
			case 6:	q.get_rear();
					break;
			case 7: cout<<"\n-----Display of list of bookings-----\n";
					q.display();
					break;
			case 8: exit(0);
					break;
			default:cout<<"\nInvalid Choice!\n";
		}
		cout<<"Press 1 to continue: ";
		cin>>x;
	} while(x==1);
	return 0;
}
/*
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 1

Enter booking id and name: 1 aaa
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 2

Enter booking id and name: 2 bbb
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 1

Enter booking id and name: 3 ccc
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 2

Enter booking id and name: 4 ddd
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 5

At front Booking id: 3  Name: ccc
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 6

At end Booking id: 4  Name: ddd
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 3

Booking id: 3  Name: ccc
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 4

Booking id: 4  Name: ddd
Press 1 to continue: 1
1.Enqueue at front
2.Enqueue at rear
3.Dequeue at front
4.Dequeue at rear
5.Get front
6.Get rear
7.Display
8.Exit: 7

-----Display of list of bookings-----
Booking id: 1  Name: aaa
Booking id: 2  Name: bbb
Press 1 to continue: 2

--------------------------------
Process exited after 55.96 seconds with return value 0
Press any key to continue . . .*/
