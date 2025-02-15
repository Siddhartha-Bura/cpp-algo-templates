#include <iostream>
#include <vector>
using namespace std;


pair<int, vector<int>> knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    

    vector<int> selected_items;
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) { 
            selected_items.push_back(i - 1);
            w -= weights[i - 1];
        }
    }
    
    return {dp[n][W], selected_items};
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();
    
    pair<int, vector<int>> result = knapsack(W, weights, values, n);
    
    cout << "Maximum value in knapsack = " << result.first << endl;
    cout << "Items included (0-based index): ";
    for (int item : result.second) {
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}
