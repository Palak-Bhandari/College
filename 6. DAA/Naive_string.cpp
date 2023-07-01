#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "\nEnter Text : " ;
	string text ;
	cin >> text ;

	cout << "\nEnter Pattern : " ;
	string pattern ;
	cin >> pattern ;

	int n = text.length() , m = pattern.length() ;
	vector<int> answer ;

	for (int i = 0 ; i + m <= n ; i++ ) {
		bool matches = true ;
		for (int j = 0 ; j < m ; j++) {
			if (pattern[j] != text[i + j]) {
				matches = false ;
				break;
			}
		}
		if (matches) {
			answer.push_back(i) ;
		}
	}

	if (answer.size() == 0) {
		cout << "\nPattern Does Not Exist";
	}
	else {
		for (int i = 0 ; i < answer.size() ; i++) {
			cout << "\nPattern Found at index " << answer[i] << endl;
		}
	}
}