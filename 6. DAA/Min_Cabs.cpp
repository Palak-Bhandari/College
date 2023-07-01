#include<bits/stdc++.h>
using namespace std;
int main()
{	
    int n;
    int m = 50;
    cin>>n;
    vector<int>v(m,0);
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        for(int j=s;j<=e;j++)
        {
            v[j]+=1;
        }
    }
    int res=0;
    for(int i=0;i<m;i++)
    {
        res=max(res,v[i]);
    }
    cout<<res;
}