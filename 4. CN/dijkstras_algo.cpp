#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
	cin >> n >> m;
	vector< pair<int,int> > adj[n+1]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt});
	    adj[v].push_back({u, wt}); 
	}
    priority_queue<pair<int,int>, vector< pair<int,int> >,greater< pair<int,int> > >pq;
    vector<int> distTo(n+1,INT_MAX);
    int vertex;
    cout<<"Enter vertex: ";
    cin>>vertex;
    distTo[vertex] = 0;
    pq.push(make_pair(0,vertex));
    while (!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        vector< pair<int,int> >::iterator i;
        for(auto i:adj[prev]){
            int next = i.first;
            int nextD = i.second;
            if(distTo[next] > dist + nextD){
                distTo[next] = distTo[prev] + nextD;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    cout<<"Distance from source "<<vertex<<", are: \n";
    for(int i=vertex;i<=n;i++) cout<<distTo[i]<<" "<<i<<endl;
    return 0;
}
