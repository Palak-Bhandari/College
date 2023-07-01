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
class Queue{
	node *front, *rear;
	public:
		Queue(){
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
			if(is_empty()){
				front=temp;
				rear=temp;
			}
			else{
				rear->next=temp;
				rear=temp; // rear = rear->next;
			}
		}
		void dequeue(){
			node *p, *temp;
			if(!is_empty()){
				cout<<"Up for appointment  waiting no: "<<front->bid<<"  Patient name: "<<front->name<<endl;
				if(front == rear){
					temp=front;
					delete temp;//delete temp;
					front=NULL;
					rear=NULL;
				}
				else{
					temp=front;
					front=front->next;
					delete temp;
				}
			}
			else{
				cout<<"\nNo one in waiting cannot call for appointment!";
			}
		}
		void display(){
			node *p;
			if(!is_empty()){
				p = front;
				while(p!=NULL){
					cout<<"Waiting  no: "<<p->bid<<"  Patient name: "<<p->name<<endl;
					p=p->next;
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
4.Exit: 2
Up for appointment  waiting no: 1  Patient name: aaa
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
Up for appointment  waiting no: 2  Patient name: bbb
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
Waiting  no: 3  Patient name: ccc
Waiting  no: 4  Patient name: ddd
Press 1 to continue: 2

--------------------------------
Process exited after 38.42 seconds with return value 0
Press any key to continue . . .
*/
