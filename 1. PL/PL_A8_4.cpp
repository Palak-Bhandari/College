#include<iostream>
using namespace std;
class node{
	public:
		int bid;
		string name;
		node *next;
		node(){
			next=NULL;
		}
};
class CQueue{
	node *front, *rear;
	public:
		CQueue(){
			front=NULL;
			rear=NULL;
		}
		bool is_empty(){
			if(front==NULL && rear==NULL)
				return true;
			else
				return false;
		}
		void enqueue(int id, string cname){
			node *temp;
			temp=new node();
			temp->bid=id;
			temp->name=cname;
			temp->next = temp;
			if(is_empty()){
				front=temp;
				rear=temp;
			}
			else{
				rear->next=temp;
				rear=temp; // rear = rear->next;
				rear->next = front;
			}
		}
		void dequeue(){
			node *p, *temp;
			if(!is_empty()){
				cout<<"Call for appointment  waiting no: "<<front->bid<<"  patient name: "<<front->name<<endl;
				if(front == rear){
					temp=front;
					front=NULL;
					rear=NULL;
					delete temp;
				}
				else{
					temp=front;
					front=front->next;
					rear->next=front;
					delete temp;
				}
			}
			else{
				cout<<"\nNo one in list cannot call for appointment!";
			}
		}
		void display(){
			node *p;
			if(!is_empty()){
				p = front;
				do{
					cout<<"Waiting no: "<<p->bid<<"  patient name: "<<p->name<<endl;
					p=p->next;
				}while(p!=front);
			}
			else{
				cout<<"\nNo one in waiting!";
			}
		}
};
int main(){
	CQueue q;
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
	}while(x==1);
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
Call for appointment  waiting no: 1  patient name: aaa
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 1

Enter waiting no and patient name: 4 ddd
Press 1 to continue: 1
1.Add in waiting list
2.Call for appointment
3.Display waiting list
4.Exit: 3

-----Display of waiting list-----
Waiting no: 2  patient name: bbb
Waiting no: 3  patient name: ccc
Waiting no: 4  patient name: ddd
Press 1 to continue: 2

--------------------------------
Process exited after 33.7 seconds with return value 0
Press any key to continue . . .*/
