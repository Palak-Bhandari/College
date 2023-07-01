#include<iostream>
using namespace std;
class node {
	public:
		int coeff;
		int exp;
		node* next;
		node() {
			next=NULL;
		}
};
class scll {
	node *head;
	public:
		scll() {
			head = NULL;
		}
		void create();
		void display();
		void sorted_insert(node *temp);
		void add(scll p1,scll p2);
		void multiply(scll p1,scll p2);
};
void scll::create() {
	node *temp;
	int x;
	do{
		temp = new node;
		temp->next = temp;
		cout<<"Enter coefficient & exponent: ";
		cin>>temp->coeff>>temp->exp;
		sorted_insert(temp);
		cout<<"Press 1 to continue ";
		cin>>x;
	}while(x==1);
}
void scll :: sorted_insert(node *temp) {
	if(head == NULL) {
		head = temp;
		return;
	}
	node *p,*prev;
	if(temp->exp>head->exp) {
		p=head;
		while(p->next != head)
			p=p->next;
		p->next = temp;
		temp->next = head;
		head = temp;
		return;
	}
	p=head;
	while(1) {
		if(p->exp == temp->exp) {
			p->coeff = p->coeff + temp->coeff;
			delete(temp);
			break;
		}
		else if(p->exp<temp->exp || p->next == head) {
			if(p->exp < temp->exp) {
				prev->next = temp;
				temp->next = p;
				break;
			}
			else {
				temp->next = p->next;   //or temp->next = head;
				p->next = temp;
				break;
			}
		}
		else {
			prev = p;
			p=p->next;
		}
	}
}
void scll::display() {
	node *p;
	if (head==NULL)
		cout<<"Polynomial empty";
	else {
		p=head;
		while(p->next!=head) {
			cout << p->coeff << "X^" << p->exp << " + ";
			p=p->next;
		}
		cout<<p->coeff<<"X^"<<p->exp<<" = 0\n";
	}
}
void scll::add(scll p1,scll p2){ 
	if(p1.head==NULL && p2.head==NULL)
		return;
	node *p,*temp;
	p=p1.head;
	do {
		temp=new node;
		temp->coeff=p->coeff;
		temp->exp=p->exp;
		temp->next=temp;
		sorted_insert(temp);
		p=p->next;
	} while(p!=p1.head);
	p=p2.head;
	do {
		temp=new node;
		temp->coeff=p->coeff;
		temp->exp=p->exp;
		temp->next=temp;
		sorted_insert(temp);
		p=p->next;
	} while(p!=p2.head);
}
void scll :: multiply(scll p1,scll p2) {
	if(p1.head==NULL && p2.head==NULL)
		return;
	node *t1,*t2,*temp;
	t1=p1.head;
	do {
		t2 = p2.head;
		do {
			temp=new node;
			temp->coeff = t1->coeff * t2->coeff;
			temp->exp = t1->exp + t2->exp;
			temp->next = temp;
			sorted_insert(temp);
			t2 = t2->next;	
		} while(t2!=p2.head);
		t1=t1->next;
	} while(t1!=p1.head);
}
int main()
{
	scll p1,p2,p3,p4;
    p1.create();
    p1.display();
    p2.create();
    p2.display();
    p3.add(p1,p2);
    cout<<"Addition\n";
    p3.display();
    p4.multiply(p1,p2);
    cout<<"Multiplication\n";
    p4.display();
    
    return 0;
}
/*
Enter coefficient & exponent: 4 5
Press 1 to continue 1
Enter coefficient & exponent: 6 3
Press 1 to continue 1
Enter coefficient & exponent: 9 2
Press 1 to continue 1
Enter coefficient & exponent: 1 1
Press 1 to continue 1
Enter coefficient & exponent: 9 0
Press 1 to continue 2
4X^5 + 6X^3 + 9X^2 + 1X^1 + 9X^0 = 0
Enter coefficient & exponent: 2 4
Press 1 to continue 1
Enter coefficient & exponent: 1 2
Press 1 to continue 1
Enter coefficient & exponent: 2 1
Press 1 to continue 1
Enter coefficient & exponent: 2 0
Press 1 to continue 2
2X^4 + 1X^2 + 2X^1 + 2X^0 = 0
Addition
4X^5 + 2X^4 + 6X^3 + 10X^2 + 3X^1 + 11X^0 = 0
Multiplication
8X^9 + 16X^7 + 26X^6 + 16X^5 + 39X^4 + 31X^3 + 29X^2 + 20X^1 + 18X^0 = 0

--------------------------------
Process exited after 80.85 seconds with return value 0
Press any key to continue . . .*/
