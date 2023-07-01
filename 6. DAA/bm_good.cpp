#include<bits/stdc++.h>
using namespace std;
void good_suffix(int shift[], int bpos, int pat_len) {
    int k = pat_len - bpos - 1; 
    if (shift[bpos] > k) {
        return;
    }
    if (shift[bpos] < k) {
        shift[bpos] = k;
    }
    int j = bpos - 1;
    while (j >= 0) {
        if (shift[j] >= k - j) {
            break;
        }
        shift[j] = k - j;
        j--;
    }
}

void boyer_moore(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    int shift[m];
    for (int i = 0; i < m; i++) {
        shift[i] = m;
    }
    int j = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (pat[i] == pat[j]) {
            good_suffix(shift, i, m);
            j++;
        }
    }
    while (j < m) {
        good_suffix(shift, j, m);
        j++;
    }
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[i + j]) {
            j--;
        }
        if (j < 0) {
            cout << "Pattern occurs at position " << i << endl;
            i += shift[0];
        } else {
            i += shift[j];
        }
    }
}
int main()
{
    string txt,pat;
    cout<<"Enter text: ";
    cin>>txt;
    cout<<"Enter pattern: ";
    cin>>pat;
	boyer_moore(txt, pat);
	return 0;
}