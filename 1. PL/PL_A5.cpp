#include<iostream>
using namespace std;
class node {
	public:
		int stu_id;
		string name;
		float marks;
		node *next;
		node *prev;
		node() {
			next = NULL;
			prev = NULL;
		}
};
class dll {
	public:
		node *head;
		dll() {
			head = NULL;
		}
		int create();
		void display();
		void sort(int n);
		void merge(dll p1, dll p2);
};
int dll :: create() {
	node *p, *temp;
	int ch,n=0;
	do {
		temp = new node();
		cout <<"Enter Student prn, Name and Marks: ";
		cin>> temp->stu_id>>temp->name>>temp->marks;
		if(head == NULL) {
			head = temp;
		}
		else {
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next = temp;
			temp->prev = p;
		}
		n++;
		cout<<"Press 1 to add more: ";
		cin>>ch;
	} while(ch == 1);
	return n;
}
void dll :: display() {
	node *p;
	if(head == NULL)
		cout<<"List is empty";
	else {
		p=head;
		cout<<"Student PRN \tName \tMarks\n";
		while(p!=NULL) {
			cout<<"\t"<<p->stu_id<<"\t"<<p->name<<"\t"<<p->marks<<"\n";
			p=p->next;
		}
	}
}
void dll :: sort(int n) {
	node *q,*ptr1,*ptr2,*temp;
	int i;
    for(i=0;i<n;i++) {
		q=head;
		while(q->next != NULL) {
			if(q->marks < q->next->marks) {
				ptr1 = q;
				ptr2 = q->next;
				temp = ptr2->next;
				if(ptr1->prev != NULL)
					ptr1->prev->next = ptr2;
				else 
					head=ptr2;
				ptr2->next = ptr1;
				ptr2->prev = ptr1->prev;
				ptr1->next = temp;
				ptr1->prev = ptr2;
				if(temp != NULL)
					temp->prev=ptr1;
				q=ptr2;
		    }
			q=q->next;
		} 
	} 
}
void dll::merge(dll p1, dll p2){
	if(p1.head==NULL && p2.head==NULL)
		return;
	if(p1.head == NULL){
		head = p2.head;
		return;
	}
	if(p2.head == NULL){
		head = p1.head;
		return;
	}
	node *p,*q,*r;
	p=p1.head;
	q=p2.head;
	if(p->marks >= q->marks){
		head = p;
		p=p->next;
	}
	else{
		head = q;
		q=q->next;
	}
	r=head;
	while(p!=NULL && q!=NULL){
		if(p->marks >= q->marks) {
			r->next = p;
			p->prev = r;
			p = p->next;
			r = r->next;
		}
		else {
			r->next = q;
			q->prev = r;
			q = q->next;
			r = r->next;
		}
	}
	if(p==NULL){
		r->next = q;
		q->prev = r;
	}
	if(q==NULL){
		r->next = p;
		p->prev = p;
	}
}
int main()
{
	dll s1,s2,s3;
	int n1,n2;
	cout<<"\nCreate list for students of batch 1:-\n";
	n1 = s1.create();
	cout<<"\nCreate list for students of batch 2:-\n";
	n2 = s2.create();
	cout<<"\nDisplay before sort list(Batch 1):-\n";
	s1.display();
	cout<<"\nDisplay before sort list(Batch 2):-\n";
	s2.display();
	s1.sort(n1);
	s2.sort(n2);
    cout<<"\nDisplay after sort list(Batch 1):-\n";
	s1.display();
	cout<<"\nDisplay after sort list(Batch 2):-\n";
	s2.display();
	cout<<"\nMerge lists(Batch 1 and 2):-\n";
	s3.merge(s1,s2);
	s3.display();			
	return 0;
}
/*
Create list for students of batch 1:-
Enter Student prn, Name and Marks: 101 aaa 87
Press 1 to add more: 1
Enter Student prn, Name and Marks: 102 bbb 56
Press 1 to add more: 1
Enter Student prn, Name and Marks: 103 ccc 67
Press 1 to add more: 1
Enter Student prn, Name and Marks: 104 ddd 91
Press 1 to add more: 1
Enter Student prn, Name and Marks: 105 eee 62
Press 1 to add more: 2

Create list for students of batch 2:-
Enter Student prn, Name and Marks: 106 fff 59
Press 1 to add more: 1
Enter Student prn, Name and Marks: 107 ggg 88
Press 1 to add more: 1
Enter Student prn, Name and Marks: 108 hhh 45
Press 1 to add more: 1
Enter Student prn, Name and Marks: 109 iii 83
Press 1 to add more: 1
Enter Student prn, Name and Marks: 110 jjj 71
Press 1 to add more: 2

Display before sort list(Batch 1):-
Student PRN     Name    Marks
        101     aaa     87
        102     bbb     56
        103     ccc     67
        104     ddd     91
        105     eee     62

Display before sort list(Batch 2):-
Student PRN     Name    Marks
        106     fff     59
        107     ggg     88
        108     hhh     45
        109     iii     83
        110     jjj     71

Display after sort list(Batch 1):-
Student PRN     Name    Marks
        104     ddd     91
        101     aaa     87
        103     ccc     67
        105     eee     62
        102     bbb     56

Display after sort list(Batch 2):-
Student PRN     Name    Marks
        107     ggg     88
        109     iii     83
        110     jjj     71
        106     fff     59
        108     hhh     45

Merge lists(Batch 1 and 2):-
Student PRN     Name    Marks
        104     ddd     91
        107     ggg     88
        101     aaa     87
        109     iii     83
        110     jjj     71
        103     ccc     67
        105     eee     62
        106     fff     59
        102     bbb     56
        108     hhh     45

--------------------------------
Process exited after 93.11 seconds with return value 0
Press any key to continue . . .
*/
