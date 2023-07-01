#include<iostream>
using namespace std;
class Employee{
	public:
		int empid;
		string name;
		string dept;
		double salary;
		Employee(){
			empid = empid;
			name = name;
			dept = dept;
			salary = salary;
		}
		void getdata(){
			cout<<"Enter Employee id, Name, Salary, Department: ";
			cin>>empid>>name>>salary>>dept;
		}
		void display(){
		    cout<<"\n"<<empid<<"\t"<<name<<"\t"<<salary<<"\t"<<dept;
		}
};
int main(){
	int n,i,pos,id,flag,ch,ch1,j,k;
	Employee e[20];	
	do{
	cout<<"\n1.Accept\n2.Display\n3.Insert\n4.Delete\n5.Update\n6.Search\n7.Exit: ";
	cin>>ch;
	switch(ch){
		case 1: cout<<"\nEnter the no. of employee: ";
	            cin>>n;
	            for(i=0;i<n;i++){
		            e[i].getdata();
	            }
	            break;	            
	    case 2: cout<<"\nDisplaying data:- ";
	   			cout<<"\n Empid \t Name \tSalary \tDepartment ";
				for(i=0;i<n;i++){
				    e[i].display();
				}
				break;				
		case 3:	cout<<"\nEnter position to add details: ";
				cin>>pos;
				for(i=n-1;i>=pos-1;i--)
	    		    e[i+1]=e[i];
				e[pos-1].getdata();
				n++;
				break;				
		case 4: cout<<"\nEnter Employee id to delete: ";
				cin>>id;
				flag=0;
				for(i=0;i<n;i++){
					if(e[i].empid == id){
						flag=1;
						break;
					}
				}
				if(flag == 0){
					cout<<"\nEmployee id not found!!";
				}
				else{
					for(j=i;j<n-1;j++){
						e[j]=e[j+1];
					}
					n--;
				}
				break;				
		case 5: cout<<"\nEnter Employee id to Modify: ";
				cin>>id;
				flag=0;
				for(i=0;i<n;i++){
					if(e[i].empid == id){
						flag=1;
						e[i].getdata();
						break;
					}
				}
				if(flag == 0){
					cout<<"\nEmployee id not found!!";
				}else{
					cout<<"\nModified succesfully!!";
				}
				break;				
		case 6: cout<<"\nEnter Employee id to search details: ";
				cin>>id;
				flag = 0;
				for(k=0;k<n;k++){
					if(e[k].empid == id){
						flag=1;
						break;
					}
				}
				if(flag == 0){
					cout<<"\nEmployee id not found!";
				}else{
					cout<<"\nFound details:- ";
					e[k].display();
				}
			    break;
		case 7: exit(0);
		default:cout<<"\nInvalid choice!";
	}
    cout<<"\nPress 1 to continue: ";	
	cin>>ch1;	
	}while(ch1 == 1);	
	return 0;		
}
/*
Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 1

Enter the no. of employee: 5
Enter Employee id, Name, Salary, Department: 1 aa 11000 d1
Enter Employee id, Name, Salary, Department: 2 bb 10000 d3
Enter Employee id, Name, Salary, Department: 3 cc 14000 d2
Enter Employee id, Name, Salary, Department: 4 dd 13000 d1
Enter Employee id, Name, Salary, Department: 5 ee 12000 d3

Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 2

Displaying data:-
 Empid   Name   Salary  Department
1       aa      11000   d1
2       bb      10000   d3
3       cc      14000   d2
4       dd      13000   d1
5       ee      12000   d3
Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 3

Enter position to add details: 4
Enter Employee id, Name, Salary, Department: 6 ff 19000 d2

Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 5

Enter Employee id to Modify: 5
Enter Employee id, Name, Salary, Department: 5 ee 18000 d1

Modified succesfully!!
Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 6

Enter Employee id to search details: 2

Found details:-
2       bb      10000   d3
Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 4

Enter Employee id to delete: 3

Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 2

Displaying data:-
 Empid   Name   Salary  Department
1       aa      11000   d1
2       bb      10000   d3
6       ff      19000   d2
4       dd      13000   d1
5       ee      18000   d1
Press 1 to continue1

Menu:-
1. Accept
2. Display
3. Insert
4. Delete
5. Update
6. Search
7. Exit
Enter your choice: 7

--------------------------------
Process exited after 146.2 seconds with return value 0
Press any key to continue . . .*/
