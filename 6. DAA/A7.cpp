#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
void printPath(const vector<vector<int>>& path, int start, int end) {
    if (path[start][end] == -1) {
        cout << start << " -> " << end;
    } else {
        int intermediate = path[start][end];
        printPath(path, start, intermediate);
        cout << " -> " << intermediate;
        printPath(path, intermediate, end);
    }
}
int tsp(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, numeric_limits<int>::max()));
    dp[1 << start][start] = 0;  // Base case: start node is visited first
    
    // Initialize the path matrix with -1
    vector<vector<int>> path(n, vector<int>(n, -1));
    
    // Iterate over all the subsets of nodes
    for (int subset = 1; subset < (1 << n); ++subset) {
        // Iterate over all the end nodes
        for (int end = 0; end < n; ++end) {
            if (subset & (1 << end)) {  // Check if the end node is present in the subset
                // Iterate over all the intermediate nodes
                for (int intermediate = 0; intermediate < n; ++intermediate) {
                    if (intermediate != end && (subset & (1 << intermediate))) {  // Check if the intermediate node is present in the subset and not equal to the end node
                        // Update the DP matrix with the minimum distance from start to end through the intermediate node
                        int newDist = dp[subset ^ (1 << end)][intermediate] + graph[intermediate][end];
                        if (newDist < dp[subset][end]) {
                            dp[subset][end] = newDist;
                            path[start][end] = intermediate;  // Update the path matrix with the intermediate node
                        }
                    }
                }
            }
        }
        cout << "Subset: " << subset << endl;
        for (int i = 0; i < n; ++i) {
            cout << "  " << i << ": " << dp[subset][i] << " ";
            if (dp[subset][i] != numeric_limits<int>::max()) {
                cout << "Path: ";
                printPath(path, start, i);
                cout << endl;
            } else {
                cout << endl;
            }
        }
    }
    return dp[(1 << n) - 1][start];
}

int main() {
    vector<vector<int>> graph = {{0, 10, 15, 20},
                                 {10, 0, 35, 25},
                                 {15, 35, 0, 30},
                                 {20, 25, 30, 0}};
    int start = 0;
    int minDist = tsp(graph, start);
    cout<<minDist;
    // printPath();
    return 0;
}