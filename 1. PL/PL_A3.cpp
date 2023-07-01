#include<iostream>
using namespace std;
class node{
	public:
		int empid;
		string name;
		double salary;
		node* next;
		node(){
			next=NULL;
		}
};
class sll{
	node *head;
	public:
		sll(){
			head = NULL;
		}
		void create();
		void display();
		void append();
		void insert_beg();
		void insert();
		void search();
		void delete_data();
		void update(int x);
		void sort();
};
void sll :: create(){
	node *temp,*p;
	int ch;
	do{
		temp = new node();
		cout<< "Enter the Employee Id,Name,Salary: ";
		cin>>temp->empid>>temp->name>>temp->salary;
		if(head==NULL)  //first data 
		   head=temp;
		else{
			p=head;
			while(p->next!=NULL) // go till end of list and add data at end
		        p=p->next;
			p->next = temp;
		}
		cout<<"Press 1 to add more Employee\'s details: ";
		cin>>ch;
	} while(ch==1);
}
void sll :: display(){
	node *p;
	if(head==NULL){
		cout<<"There are no Employees added!";
	}
	else{
		p=head;
		cout<<"\nThe Employee details are:-"<<endl;
		cout<<"EmpId\tName\tSalary\n";
		while(p!=NULL){  // p as we want the last node also to be displayed
			cout<<p->empid<<"\t"<<p->name<<"\t"<<p->salary<<endl;
			p=p->next;
		}
	}
}
void sll :: append(){
	node *temp,*p;
	temp = new node();
	cout<<"Enter the Employee Id,Name,Salary: ";
	cin>>temp->empid>>temp->name>>temp->salary;
	if(head==NULL)  //same as create
	   head=temp;
	else {
		p=head;
		while(p->next!=NULL)
	        p = p->next;
		p->next = temp;
	}
}
void sll :: insert_beg(){
	node *temp;
	temp = new node();
	cout<<"Enter the Employee Id,Name,Salary: ";
	cin>>temp->empid>>temp->name>>temp->salary;
	if(head == NULL)
	   head = temp;
	else {
		temp->next = head; 
		head = temp;
	}
}
void sll :: insert(){
	node *temp,*p;
	int flag = 0,x;
	cout<<"Enter the Employee id after which you want insert data: ";
	cin>>x;
	temp = new node();
	cout<<"Enter the Employee Id,Name,Salary: ";
	cin>>temp->empid>>temp->name>>temp->salary;
	p=head;
	while(p != NULL){
		if(p->empid == x){
			flag = 1;
			break;
		}
		p = p->next;
	}
	if(flag == 1){
		temp->next = p->next;
		p->next = temp;
	}
	else{
		cout<<"No such Employee id found!\n";
	}
}
void sll :: search(){
	node *temp,*p;
	int x,flag=0;
	cout<<"Enter the Employee id you are searching details of: ";
	cin>>x;
	temp = new node();
	p=head;
	while(p!=NULL){
		if(p->empid == x){
			flag=1;
			cout<<"The Employee details found are:-\n";
			cout<<"EmpId\tName\tSalary\n";
			cout<<p->empid<<"\t"<<p->name<<"\t"<<p->salary<<endl;
			break;
		}
		p = p->next;
	} 
	if(flag == 0){
		cout<<"Employee not found!\n";
	}
}
void sll :: delete_data(){
	node *prev,*p;
	int x, flag = 0;
	cout<<"Enter the employee id whose data you want to delete: ";
	cin>>x;
	if(head == NULL){
		cout<<"Empty employee data!\n";
	}
	if(head->empid == x){
		p=head;
		head = head->next;
		delete(p);
		return;
	}
	else{
		p=head; 
		while(p!=NULL){
			if(p->empid == x){
				flag=1;
				break;
			}
			prev = p;
			p=p->next;
		}
	}
	if(flag == 1){
		prev->next = p->next;
		delete(p);
	}
	else{
		cout<<"Employee id not found!\n";
	}	
}
void sll :: update(int x){
	int flag = 0;
	node *p; 
	if(head == NULL){
		cout<<"Empty employee data!\n";
	}
	else{
		p=head;
		while(p != NULL){
			if(p->empid = x){
				flag = 1;
				cout<< "Enter the Employee Id,Name,Salary: ";
				cin>> p->empid>>p->name>>p->salary;
				break;
			}
			p=p->next;
		}
		if(flag == 0){
			cout<<"No such Employee found!\n";
		}
		else{
			cout<<"Update Successfull!\n";
		}
	}
	
}
void sll :: sort(){
	int swapped;
	node *p,*q,*temp;
	temp = new node();
	q = head;
	while(q->next != NULL){
		p = head;
		swapped = 0;
		while(p->next != NULL){
			if(p->name > p->next->name){
				temp->empid = p->empid;
				p->empid = p->next->empid;
				p->next->empid = temp->empid;
				
				temp->name = p->name;
				p->name = p->next->name;
				p->next->name = temp->name;
				
				temp->salary = p->salary;
				p->salary = p->next->salary;
				p->next->salary = temp->salary;
				swapped=1;
			}
			p = p->next;
		}
		if(swapped == 0){
			break;
		}
		else{
			cout<<"Sorted Successfully!\n";
		}
		q=q->next;
	}
}

int main()
{
	sll s;
	int ch,ch2,x;
	do{
		cout<<"\nSelect:\n1.Create\n2.Display\n3.Insert\n4.Update\n5.Delete\n6.Search\n7.Sort\n8.Exit ";
		cin>>ch;
		switch(ch){
			case 1: s.create();
					break;
			case 2:	s.display();
					break; 
			case 3: cout<<"\nSelect:\n1.Insert at end\n2.Insert at Beginning\n3.Insert at a location ";
					cin>>ch2;
					switch(ch2){
						case 1: s.append();
								break;
						case 2: s.insert_beg();
						    	break;
						case 3: s.insert();
								break;
						default:cout<<"Invalid Choice!";
					}
					break;
			case 4: cout<<"Enter the employee id you want to update data for: ";
					cin>>x;
					s.update(x);
					break;
			case 5: s.delete_data();
					break;
			case 6: s.search();
					break;
			case 7:	s.sort();
					break;
			case 8: exit(0);
					break;
			default:cout<<"Invalid Choice!";
		}
		cout<<"Press 1 to continue: ";
		cin>> x;
	}while(x==1);
	return 0;
}
/*
Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 1
Enter the Employee Id,Name,Salary: 101 aa 12000
Press 1 to add more Employee's details: 1
Enter the Employee Id,Name,Salary: 102 cc 13000
Press 1 to add more Employee's details: 2
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 4
Enter the employee id you want to update data for: 101
Enter the Employee Id,Name,Salary: 101 aa 14000
Update Successfull!
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 2

The Employee details are:-
EmpId   Name    Salary
101     aa      14000
102     cc      13000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 3

Select:
1.Insert at end
2.Insert at Beginning
3.Insert at a location 1
Enter the Employee Id,Name,Salary: 103 dd 15000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 3

Select:
1.Insert at end
2.Insert at Beginning
3.Insert at a location 2
Enter the Employee Id,Name,Salary: 100 bb 19000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 3

Select:
1.Insert at end
2.Insert at Beginning
3.Insert at a location 3
Enter the Employee id after which you want insert data: 101
Enter the Employee Id,Name,Salary: 104 ff 16000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 2

The Employee details are:-
EmpId   Name    Salary
100     bb      19000
101     aa      14000
104     ff      16000
102     cc      13000
103     dd      15000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 5
Enter the employee id whose data you want to delete: 101
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 2

The Employee details are:-
EmpId   Name    Salary
100     bb      19000
104     ff      16000
102     cc      13000
103     dd      15000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 6
Enter the Employee id you are searching details of: 104
The Employee details found are:-
EmpId   Name    Salary
104     ff      16000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 7
Sorted Successfully!
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 2

The Employee details are:-
EmpId   Name    Salary
100     bb      19000
102     cc      13000
103     dd      15000
104     ff      16000
Press 1 to continue: 1

Select:
1.Create
2.Display
3.Insert
4.Update
5.Delete
6.Search
7.Sort
8.Exit 8

--------------------------------
Process exited after 160.4 seconds with return value 0
Press any key to continue . . .*/
