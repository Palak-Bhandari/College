#include<bits/stdc++.h>
using namespace std;
void Link_State_Routing() {
    int n , m ;
    cout << "\nEnter total number of routers and total edges(links) in network : " << endl;
    cin >> n >> m;
    int s ;
    cout << "\nEnter source router : " << endl;
    cin >> s ;
    cout << "\nEnter linked routers and their edge weight(transmission delays) : \n\n" ;
    vector< pair<int, int> > adj[n + 1] ;
    for (int i = 0; i < m ; i++) {
        int a , b , wt ;
        cin >> a >> b >> wt ;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    vector<int> dist(n, 1e9) ;
    dist[s] = 0;
    priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int v = cur.second;
        int d_v = cur.first;
        for (auto edge : adj[v]) {
            if (dist[v] + edge.second < dist[edge.first]) {
                dist[edge.first] = dist[v] + edge.second;
                pq.push({dist[edge.first], edge.first});
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << "shortest distance of router " << i << " from router " << s << " is : " << dist[i] << endl;
    }
}
int main() {
    Link_State_Routing() ;
    return 0 ;
}
/*

Input 
	
9

0

0 1 4 
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
	
*/
