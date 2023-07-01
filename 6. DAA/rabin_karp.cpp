#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
class RabinKarp {
public:
    string text , pattern ;
    int n , m ;
    RabinKarp(string a , string b) {
        pattern = a ;
        text = b ;
        n = text.length() ;
        m = pattern.length() ;
    }
    vector<int> match() {

        ll p = 10 ;
        ll pow = p ;
        ll mod = 1e9 + 7 ;
        ll desired_hash_value = pattern[0] - 'a' + 1;

        for (int i = 1 ; i < m ; i++) {
            desired_hash_value = (desired_hash_value + ((pattern[i] - 'a' + 1) * 1ll * pow) % mod) % mod ;
            pow = (pow * p * 1ll) % mod ;
        }
        vector<ll> dp(n) ;
        vector<ll> powerAti(n) ;

        dp[0] = text[0] - 'a' + 1 ;
        powerAti[0] = 1 ;
        pow = p ;

        for (int i = 1 ; i < n ; i++) {
            dp[i] = (dp[i - 1] + ((text[i] - 'a' + 1) * 1ll * pow) % mod) % mod ;
            powerAti[i] = pow ;
            pow = (pow * p * 1ll) % mod ;
        }
        int start = 0 , end = m - 1 ;
        vector<int> indices ;
        while (end < n) {
            ll window = dp[end] ;
            if (start > 0)
                window = (window - dp[start - 1] + mod) % mod;

            if (window == (desired_hash_value * powerAti[start] * 1ll) % mod) {
                indices.push_back(start) ;
            }
            start++; end++;
        }
        return indices ;
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
    RabinKarp obj(pattern, text) ;
    vector<int> answer = obj.match() ;

    if (answer.size() == 0)
        cout << "\nPattern Not Found\n" ;
    else
        for (int i = 0 ; i < answer.size() ; i++) {
            cout << "\nPattern found at index : " << answer[i] << "\n";
        }
}