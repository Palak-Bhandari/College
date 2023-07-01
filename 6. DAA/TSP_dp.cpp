#include <bits/stdc++.h>
using namespace std;
int dp[10][10], visited[10],cpath[10], n, cost = 0;
int least(int c)
{
    int i, nc = 999;
    int minc = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if ((dp[c][i] != 0) && (visited[i] == 0)){
            cout<<"City: "<<i+1<<" ,Going to city costs: "<<dp[c][i]<<endl;
            if (dp[c][i] + dp[i][c] < minc)
            {
                minc = dp[i][0] + dp[c][i];
                kmin = dp[c][i];
                nc = i;
            }
        }
    }
    if (minc != 999)
        cout<<"This level final, City: "<<nc<<" ,Going to city costs: "<<kmin<<endl;
        cost += kmin;
    return nc;
}
void mincost(int city)
{
    int i, ncity;
    visited[city] = 1;
    cout << city + 1 << "--->\n";
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += dp[city][ncity];
        cout<<"This level final, City: "<<city<<" ,Going to city costs: "<<ncity<<endl;
        return;
    }
    mincost(ncity);
}
int main()
{
    int i, j;
    cout << "Enter the total number of cities: ";
    cin >> n;
    cout << "Enter the Cost Matrix: \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cin >> dp[i][j];
        visited[i] = 0;
    }
    cout << "\n\nThe Path is:\n";
    mincost(0);
    cout << "\n\nMinimum cost is " << cost;
    return 0;
}