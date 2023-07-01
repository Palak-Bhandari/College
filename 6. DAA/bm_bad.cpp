#include<bits/stdc++.h>
using namespace std ;
int main() {
	cout << "\nEnter Text : " ;
	string text ;
	cin >> text ;

	cout << "\nEnter Pattern : " ;
	string pattern ;
	cin >> pattern ;

	int n = text.length() , m = pattern.length() ;

	map<char, int> Bad_match ;
	Bad_match[pattern[m - 1]] = m;

	for (int i = m - 2 ; i >= 0 ; i--) {
		if (Bad_match.count(pattern[i])) continue ;
		Bad_match[pattern[i]] = m - i - 1 ;
	}

	int i = m - 1 ;
	vector<int> answer ;

	while (i < n) {
		if (text[i] != pattern[m - 1]) {
			if (Bad_match.count(text[i])) {
				i += Bad_match[text[i]] ;
			}
			else i += m ; // Bad_match [ * ] = m
		}
		else {
			bool ok = true ;
			int j = i ;
			i++;
			for (int ind = m - 1 ; ind >= 0 ; ind--) {
				if (text[j] != pattern[ind]) {
					ok = false ;
					break;
				}
				j--;
			}
			if (ok) {
				answer.push_back(j + 1) ;
			}
		}
	}

	if (answer.size() == 0) {
		cout << "\nPattern Not Found." << endl;
	}
	else {
		for (int i = 0 ; i < answer.size() ; i++) {
			cout << "Pattern is present at index " << answer[i] << endl;
		}
	}
}