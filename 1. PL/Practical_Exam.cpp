/*
	Name - Palak Vikas Bhandari
	Seat No - S214072
	Problem Statement - Write a program in C++ to implement infix to postfix conversion and evaluate the 
						postfix expression obtained.
*/
#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;
#define SIZE 20
class Stack{
	string st[SIZE];
	int top;
	public:
		Stack(){
			top=-1;	
		}
		int is_empty(){
			if(top == -1)
				return 1;
			else 
				return 0;
		}
		int is_full(){
			if(top == SIZE-1)
				return 1;
			else 
				return 0;
		}
		void push(string x){
			if(is_full()){
				cout<<"Stack is full cannot push!\n";
				return;
			}
			else {
				top++;
				st[top] = x;
			}
		}
		string pop(){
			if(is_empty()){
				return "Stack Empty cannot pop!\n";
			}
			else{
				string x = st[top];
				top--;
				return x;
			}
		}
		string stacktop(){
			if(is_empty()) {
				return "Stack is empty!\n";
			}
			else
				return st[top];
		}
};
class Expression {
	public:
	string postfix,infix;
	Stack s;
	int precedence(string op){ // precedence of op ^ / * + -
		if(op=="^")
			return 3;
		else if(op=="*" || op=="/")
			return 2;
		else if(op=="+" || op=="-")
			return 1;
		else
			return 0;
	}
	string infix_to_postfix(string infix){
        for(int i=0;i<infix.length();i++) { // iterate through all characters
            if(isdigit(infix[i])){   // if digit output it
                postfix += infix[i];
            }
            else if(infix[i] == '(') {  // push (
                s.push("(");
            }
            else if(infix[i] == ')') { // pop till ( is popped
                while(!s.is_empty() && s.stacktop() != "(") {
                    postfix += s.pop();
                }
                if(s.stacktop() == "(") {
                    s.pop();
                }
            }
            else {  // higher or equal pop top operator and push current operator
                while(!s.is_empty() && precedence(string(1,infix[i])) <= precedence(s.stacktop())) {
                    postfix += s.pop();
                }
                s.push(string(1,infix[i]));
            }   // lower push current operator
        }
        while(!s.is_empty()) { // pop all characters till stack is empty
            postfix += s.pop(); 
        }
		return postfix;
    }
	void postfix_evaluation(string postfix){
		int i;
		string result;
		for(i=0;i<postfix.length();i++){
			if (isdigit(postfix[i])){
				s.push(string(1,postfix[i])); // push if digit
			}
			else{
				string op2 = s.pop(); // pop 2 digits 
				string op1 = s.pop();
				stringstream ob1(op1);
				stringstream ob2(op2);
				int op_1,op_2;
				ob1>>op_1; // read the digits
				ob2>>op_2;
				int temp;
				if(postfix[i]=='+') // apply respective operation
					temp = op_1 + op_2;
				else if(postfix[i]=='-')
					temp = op_1 - op_2;
				else if(postfix[i]=='*')
					temp = op_1 * op_2;
				else if(postfix[i]=='/')
					temp = op_1 / op_2;
				else 
					temp = pow(op_1,op_2);
				stringstream ob3;
				ob3<<temp;
				string x = ob3.str();
				s.push(x); // push that answer in stack
			}
		}
		result = s.pop(); 
		cout<<"Result: "<<result<<endl;
	}
};
int main(){
	Expression e;
	int ch,x;
	string p,i;
	do{
		cout<<"1.Infix to Postfix\n2.Postfix Evaluation: ";
		cin>>ch;
		switch(ch){
			case 1:	cout<<"Enter the infix expression: ";
					cin>>i;
					p = e.infix_to_postfix(i);
					cout<<"Postfix expression is: "<<p<<endl;
					break;
			case 2:	e.postfix_evaluation(p);
					break;
			default:cout<<"\nInvalid Choice!\n";
		}
		cout<<"\nPress 1 to continue: ";
		cin>>x;
	} while(x==1);
	return 0;
}
/*
1.Infix to Postfix
2.Postfix Evaluation: 1
Enter the infix expression: 9+9-3*4/2-(4+1)
Postfix expression is: 99+34*2/-41+-

Press 1 to continue: 1
1.Infix to Postfix
2.Postfix Evaluation: 2
Result: 7

Press 1 to continue: 2

--------------------------------
Process exited after 44.03 seconds with return value 0
Press any key to continue . . .
*/
