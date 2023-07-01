#include<bits/stdc++.h>
using namespace std;
class node{
	pubilc:
		int data;
		node *next;
		node *prev;
};
class dll{
	public:
		node *head;
		dll(){
			head=NULL;
		}
		void create();
		void insert_first();
		void del();
		void fwd_disp();
		void bckd_disp();
};
void create(){
	node *temp,*p;
	char ch;
	do{
		temp=new node;
		cout<<"Enter data: ";
		cin>>temp->data;
		temp->next=NULL;
		temp->prev=NULL;
		if(head==NULL) head=temp;
		else{
			p=head;
			while(p->next!=NULL) p=p->next;
			p->next=temp;
			temp->prev=p;
		}
		cout<<"Do you want to continue(y/n): ";
		cin>>ch;
	}while(ch=='y');
}
void fwd_disp(){
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
}
void bckd_disp(){
	node *temp = head;
	while(temp->next!=NULL) temp=temp->next;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->prev;
	}
}
void insert_first(){
	node *temp = new node;
	cout<<"Enter data: ";
	cin>>temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	head->prev = temp;
	temp->next = head;
	head = temp;
}
void insert_last(){
	node *temp = new node;
	node *p = head;
	cout<<"Enter data: ";
	cin>> temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	while(p->next!=NULL) p = p->next;
	p->next = temp;
	temp->prev = p;
}
void insert_mid(){
	node *temp = new node;
	node *p = head;
	int item,flag=0;
	cout<<"Enter data: ";
	cin>>temp->data;
	temp->next = NULL;
	temp->prev = p;
	cout<<"Enter data after which to insert: ";
	cin>>item;
	while(p!=NULL){
		if(p->val==item){
			p->next->prev=temp;
			temp->next = p->next;
			p->next = temp;
			temp->prev = p;
			flag = 1;
			break;
		}
		else p=p->next;
	}
	if(flag==0){
		cout<<"NOT INSERTED!!";
	}
}
void del_first(){
	node *temp=head;
	haed = head->next;
	head->prev=NULL;
	delete temp;
}
void del_last(){
	node *temp = head;
	while(temp->next!=NULL) temp=temp->next;
	temp->prev->next = NULL;
	delete temp;
}
void del_mid(){
	node *temp=head;
	int item,flag=0;
	cout<<"Enter data: ";
	cin>>temp->data;
	while(temp!=NULL){
		if(temp->val==item){
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete temp;
			flag=1;
			break;
		}else temp=temp->next;
	}
	if(flag==0){
		cout<<"COULD NOT DELETE";
	}
}

void reverse_sll(){
	node *r,*q,*s;
	r=null;
	q=head;
	while(q!=NULL){
		s=r;
		r=q;
		r->next=s;
		q=q->next;	
	}
	head=r;
}
