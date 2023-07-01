#include<bits/stdc++.h>
using namespace std;
class KMP {
public:
    vector<int> LPS , occurances ;
    string text ;
    int n , m ;

    KMP(string para1 , string pattern) {
        m = pattern.length() ; // pattern length
        n = para1.length() ;
        pattern.push_back('#') ;
        text = pattern + para1 ;
        LPS.resize(m + 1 + n, 0) ;
    }

    vector<int> generateLPS() {
        int i = 1 , len = 0 ;
        while (i < text.length()) {
            if (text[i] == text[len]) {
                len++;
                LPS[i] = len ;
                i++ ;
            }
            else {
                if (len > 0)
                    len = LPS[len - 1] ;
                else {
                    LPS[i] = 0 ;
                    i++ ;
                }
            }
        }

        for (int i = 0 ;  i < text.length() ; i++) {
            if (LPS[i] == m) {
                occurances.push_back(i - m - m) ;
            }
        }

        return occurances ;
    }
};

int main() {

    cout << "\nEnter Text : " ;
    string text ;
    cin >> text ;

    cout << "\nEnter Pattern : " ;
    string pattern ;
    cin >> pattern ;

    int n = text.length() , m = pattern.length() ;
    KMP obj(text, pattern) ;
    vector<int> occurances = obj.generateLPS() ;
	
	cout<<"\nNumber Of Occurances : " ;
    cout << occurances.size() << endl;
    cout<<"\nOccurances is present at this indices : " ;
    for (int i = 0 ; i < occurances.size() ; i++) {
        cout << occurances[i] << " ";
    }
}