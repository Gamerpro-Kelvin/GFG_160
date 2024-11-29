/*
Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.

Input: prices[] = [7, 6, 4, 3, 1]
Output: 0 
Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.

Input: prices[] = [1, 3, 6, 9, 11]
Output: 10 
Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].

Constraint:
1 <= prices.size()<= 10^5
0 <= prices[i] <=10^4
*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) return 0;

    int buy = 0;       // Pointer to track the buy day
    int maxProfit = 0; // Store the maximum profit

    for (int sell = 1; sell < n; sell++) {
        if (prices[sell] < prices[buy]) {
            buy = sell; // Update buy pointer if a lower price is found
        } else {
            maxProfit = max(maxProfit, prices[sell] - prices[buy]); // Update profit
        }
    }

    return maxProfit;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
