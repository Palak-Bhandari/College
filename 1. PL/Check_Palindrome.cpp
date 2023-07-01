#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cout<<"Enter string: ";
	cin>>str;
	int flag=0;
	for(int i=0;i<str.length()/2;i++){
		if(str[i]!=str[str.length()-i-1]){
			flag=0;
		}
		else flag=1;
	}
	if(flag==1){
		cout<<"Palindrome!";
	}
	else{
		cout<<"Not Palindrome!";
	}
	
	return 0;
}
