#include <bits/stdc++.h>
using namespace std;
#define vvbl vector<vector<bool>>
#define vbl vector<bool>
vector<vvbl> solutions;
int n = 8;
vector<bool> leftDiag(25, 0), rightDiag(25, 0), vertical(25, 0);
bool is_safe(vvbl &grid, int row, int col)
{
    if (leftDiag[n - 1 + (row - col)])
        return false;
    if (rightDiag[col + row])
        return false;
    if (vertical[col])
        return false;
    return true;
}
void solve(vvbl &grid, int row, int n)
{
    if (row == n)
    {
        solutions.push_back(grid);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (is_safe(grid, row, col))
        {
            grid[row][col] = 1;
            leftDiag[n - 1 + (row - col)] = 1;
            rightDiag[col + row] = 1;
            vertical[col] = 1;
            solve(grid, row + 1, n);
            grid[row][col] = 0;
            leftDiag[n - 1 + (row - col)] = 0;
            rightDiag[col + row] = 0;
            vertical[col] = 0;
        }
    }
}
int main()
{
    int no = 8;
    vvbl grid(no, vbl(no, false));
    solve(grid, 0, no);
    cout << "\nTotal Solutions : " << solutions.size() << "\n\n";
    for (auto it : solutions)
    {
        for (int i = 0; i < no; i++)
        {
            for (int j = 0; j < no; j++)
            {
                if (it[i][j])
                    cout << '1';
                else
                    cout << '0';
            }
            cout << endl;
        }
        cout << "\n\n";
    }
}