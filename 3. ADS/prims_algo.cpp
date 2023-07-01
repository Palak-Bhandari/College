#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int parent[n], key[n];
    bool mst[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1, key[i] = INT_MAX, mst[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int mini = INT_MAX, u;
        for (int v = 0; v < n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;
        for (auto i : adj[u])
        {
            int wt = i.second;
            int v = i.first;
            if (mst[v] == false && wt < key[v])
                parent[v] = u;
            key[v] = wt;
        }
    }
    for (int i = 0; i < n; i++)
        cout << parent[i] << "-" << i << " \n";

    return 0;
}