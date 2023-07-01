#include <bits/stdc++.h>
using namespace std;
int table[100] = {0};
int minCoins(int N, int M, int coins[])
{
    for (int i = 0; i <= N; i++)
        table[i] = INT_MAX;

    table[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (coins[j] <= i)
            {
                table[i] = min(table[i], 1 + table[i - coins[j]]);
            }
        }
    }
    cout<<"Table: "<<endl;
    for (int k = 0; k < M; k++){
        for(int a = 0; a <= N; a++){
             cout << table[a] << " ";
        }
        cout<<endl;
    }
    return table[N];
}
int main()
{
    int sum;
    int total_coins;
    cout<<"Enter number of denominations: ";
    cin>>total_coins;
    int coins[total_coins];
    cout<<"Enter the denominations: ";
    for(int i = 0;i<total_coins;i++){
        cin>>coins[i];
    }
    cout<<"Enter the sum you want: ";
    cin>>sum;
    int ans = minCoins(sum, total_coins, coins);
    cout << "The Minimum coins required to get the sum: " << ans;
}