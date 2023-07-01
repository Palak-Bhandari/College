#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;
#define SIZE 10
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
class Exp {
	public:
	string postfix,infix;
	Stack s;
	bool is_operator(char x){
		if(x=='+'|| x=='-'|| x=='*'|| x=='/'||x=='^')
			return true;
		return false;
	}
	int precedence(string op){
		if(op=="^")
			return 3;
		else if(op=="*" || op=="/")
			return 2;
		else if(op=="+" || op=="-")
			return 1;
		else
			return 0;
	}
	void infix_to_postfix(){
		cout <<"\nEnter Infix expression: ";
        cin >> infix;
        for(int i=0;i<infix.length();i++) {
            if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
                postfix += infix[i];
            }
            else if(infix[i] == '(') {
                s.push("(");
            }
            else if(infix[i] == ')') {
                while(!s.is_empty() && s.stacktop() != "(") {
                    postfix += s.pop();
                }
                if(s.stacktop() == "(") {
                    s.pop();
                }
            }
            else {
                while(!s.is_empty() && precedence(string(1,infix[i])) <= precedence(s.stacktop())) {
                    postfix += s.pop();
                }
                s.push(string(1,infix[i]));
            }
        }
        while(!s.is_empty()) {
            postfix += s.pop();
        }
		cout<<"Postfix Expression: "<<postfix<<endl;
    }
	void postfix_to_prefix(){
		cout<<"\nEnter the postfix expression to convert to prefix: ";
		cin>>postfix;
		string prefix;
		int i;
		for(i=0;i<postfix.length();i++){
			if(is_operator(postfix[i])){
				string op2 = s.pop();
				string op1 = s.pop();
				string temp = postfix[i]+op1+op2;
				s.push(temp);
			}
			else{
				s.push(string(1,postfix[i]));
			}
		}
		prefix = s.pop();
		cout<<"Prefix Expression: "<<prefix<<endl;
	}
	void postfix_evaluation(){
		cout<<"\nEnter the postfix expression for evaluation: ";
		cin>>postfix;
		int i;
		string result;
		for(i=0;i<postfix.length();i++){
			if(isdigit(postfix[i])){
				s.push(string(1,postfix[i]));
			}
			else{
				string op2 = s.pop();
				string op1 = s.pop();
				stringstream ob1(op1);
				stringstream ob2(op2);
				int op_1,op_2;
				ob1>>op_1;
				ob2>>op_2;
				int temp;
				if(postfix[i]=='+')
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
				s.push(x);
			}
		}
		result = s.pop();
		cout<<"Result: "<<result<<endl;
	}
};
int main(){
	Exp e1;
	int ch,x;
	do{
		cout<<"1.Infix to Postfix\n2.Postfix to Prefix\n3.Postfix Evaluation\n4.Exit: ";
		cin>>ch;
		switch(ch){
			case 1:	e1.infix_to_postfix();
					break;
			case 2:	e1.postfix_to_prefix();
					break;
			case 3: e1.postfix_evaluation();
					break;
			case 4: exit(0);
					break;
			default:cout<<"\nInvalid Choice!\n";
		}
		cout<<"\nPress 1 to continue: ";
		cin>>x;
	} while(x==1);
	return 0;
}
/*OUTPUT=>
1.Infix to Postfix
2.Postfix to Prefix
3.Postfix Evaluation
4.Exit: 1

Enter Infix expression: k+l-m*n+(o^p)*w
Postfix Expression: kl+mn*-op^w*+

Press 1 to continue: 1
1.Infix to Postfix
2.Postfix to Prefix
3.Postfix Evaluation
4.Exit: 2

Enter the postfix expression to convert to prefix: kl+mn*-op^w*+
Prefix Expression: +-+kl*mn*^opw

Press 1 to continue: 1
1.Infix to Postfix
2.Postfix to Prefix
3.Postfix Evaluation
4.Exit: 3

Enter the postfix expression for evaluation: 246+*
Result: 20

Press 1 to continue: 2

--------------------------------
Process exited after 122.5 seconds with return value 0
Press any key to continue . . .
*/
