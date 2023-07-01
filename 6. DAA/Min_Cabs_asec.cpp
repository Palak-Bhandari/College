// ascending order
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
    int n ;
    cout<<"Enter no of people: ";
    cin >> n ;
    vector<pair<int, int>> v(n) ;
    cout<<"\nEnter start time of each person: ";
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first;
    }
    cout<<"\nEnter end time of each person: ";
    for (int i = 0 ; i < n ; i++){
        cin >> v[i].second ;
    }
    auto start1 = std::chrono::steady_clock::now();
    sort(v.begin(), v.end() , [&](pair<int, int> p1 , pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first < p2.first ;
        return p1.second < p2.second ;
    }) ;
    set<int> taken ;
    int cab = 1 , i = 0 ;
    while (taken.size() < n) {
        cout << "\nCab No: " << cab << endl;
        cab++ ;
        int prev = -1 ;
        for (int i = 0 ; i < n ; i++) {
            if (taken.find(i) != taken.end()) continue ;
            if (v[i].first < prev)
                continue ;
            cout << v[i].first << " " << v[i].second << endl;
            taken.insert(i) ;
            prev = v[i].second ;
        }
    }
    cout << "\nTotal Cabs Required = " << cab - 1 << endl;
    auto finish1 = std::chrono::steady_clock::now();
    double time1 = std::chrono::duration_cast < std::chrono::duration<double> > (finish1 - start1).count();
    cout << "\nTime Taken By Ascending Sorting  = " << fixed << time1 << setprecision(10) << endl;
}